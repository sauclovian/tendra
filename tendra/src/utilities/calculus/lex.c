/*
 * Copyright (c) 2002, The Tendra Project <http://www.ten15.org/>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 *    		 Crown Copyright (c) 1997
 *    
 *    This TenDRA(r) Computer Program is subject to Copyright
 *    owned by the United Kingdom Secretary of State for Defence
 *    acting through the Defence Evaluation and Research Agency
 *    (DERA).  It is made available to Recipients with a
 *    royalty-free licence for its use, reproduction, transfer
 *    to other parties and amendment for any purpose not excluding
 *    product development provided that any such use et cetera
 *    shall be deemed to be acceptance of the following conditions:-
 *    
 *        (1) Its Recipients shall ensure that this Notice is
 *        reproduced upon any copies or amended versions of it;
 *    
 *        (2) Any amended version of it shall be clearly marked to
 *        show both the nature of and the organisation responsible
 *        for the relevant amendment or amendments;
 *    
 *        (3) Its onward transfer from a recipient to another
 *        party shall be deemed to be that party's acceptance of
 *        these conditions;
 *    
 *        (4) DERA gives no warranty or assurance as to its
 *        quality or suitability for any purpose and DERA accepts
 *        no liability whatsoever in relation to any use to which
 *        it may be put.
 *
 * $TenDRA$
 */


#include "config.h"
#include "calculus.h"
#include "error.h"
#include "lex.h"
#include "syntax.h"
#include "xalloc.h"


/*
 *    INPUT FLAGS
 *
 *    The flag new_format is set to true to indicate the new input format.
 *    The flags allow_stack and allow_vec are set to false to suppress the
 *    stack and vector operations respectively.
 */

int new_format = 1;
int allow_stack = 1;
int allow_vec = 1;


/*
 *    CHECK STACK FLAG
 *
 *    This routine is called if the STACK keyword is encountered to check the
 *    value of allow_stack.
 */

static int
check_stack(int t)
{
    if (!allow_stack) {
		error (ERROR_SERIOUS, "Stack operations have been suppressed");
		allow_stack = 1;
    }
    return (t);
}


/*
 *    CHECK VECTOR FLAG
 *
 *    This routine is called if the VEC or VEC_PTR keywords are encountered
 *    to check the value of allow_vec.
 */

static int
check_vec(int t)
{
    if (!allow_vec) {
		error (ERROR_SERIOUS, "Vector operations have been suppressed");
		allow_vec = 1;
    }
    return (t);
}


/*
 *    INPUT FILE
 *
 *    This is the file from which the lexical routine read their input.
 */

static FILE *lex_input;


/*
 *    PENDING BUFFER
 *
 *    Pending characters are dealt with by means of this buffer.  pending
 *    is set to the start of the buffer to indicate that there are no
 *    characters pending, otherwise the pending characters are stored in
 *    the buffer.  The buffer may need increasing in size if the look-ahead
 *    required by the lexical analyser increases.
 */

static int pending_buff [12] = { '?' };
static int *pending = pending_buff;


/*
 *    MAPPINGS AND DECLARATIONS FOR AUTOMATICALLY GENERATED SECTION
 *
 *    These macros give the mappings between the actions used in the
 *    automatically generated lexical analyser and the routines defined
 *    in this file.
 */

static int read_char(void) ;
static int read_comment(void) ;
static int read_hex(int) ;
static int read_identifier(int) ;
static int read_number(int) ;
static int read_string(void) ;

#define get_comment(A, B)	read_comment ()
#define get_hex(A, B, C)	read_hex (C)
#define get_identifier(A)	read_identifier (A)
#define get_number(A)		read_number (A)
#define get_string(A)		read_string ()
#define get_stack()		check_stack (lex_stack)
#define get_vec()		check_vec (lex_vec)
#define get_vec_ptr()		check_vec (lex_vec_Hptr)
#define unknown_token(A)	lex_unknown
#define unread_char(A)	*(++pending) = (A)


/*
 *    AUTOMATICALLY GENERATED SECTION
 *
 *    The main body of the lexical analyser is automatically generated.
 */

#include "lexer.h"


/*
 *    GET THE NEXT CHARACTER
 *
 *    This routine reads the next character, either from the pending buffer
 *    or from the input file.
 */

static int
read_char()
{
    int c;
    if (pending != pending_buff) {
		c = *(pending--);
    } else {
		c = fgetc (lex_input);
		if (c == '\n') crt_line_no++;
		if (c == EOF) return (LEX_EOF);
		c &= 0xff;
    }
    return (c);
}


/*
 *    TOKEN BUFFER
 *
 *    This buffer is used by read_token to hold the values of identifiers
 *    and strings.  The variable token_value is also used to hold the
 *    values of numbers.
 */

char token_buff [4000];
static char *token_end = token_buff + sizeof (token_buff);
char *first_comment = NULL;
number token_value;


/*
 *    READ AN IDENTIFIER
 *
 *    This routine reads an identifier beginning with a, returning the
 *    corresponding lexical token.  Keywords are dealt with locally.
 */

static int
read_identifier(int a)
{
    int c = a, cl;
    char *t = token_buff;
    do {
		*(t++) = (char) c;
		if (t == token_end) error (ERROR_FATAL, "Buffer overflow");
		c = read_char ();
		cl = lookup_char (c);
    } while (is_alphanum (cl));
    *t = 0;
    unread_char (c);
	
    /* Check for keywords */
    t = token_buff;
#define MAKE_KEYWORD(A, B)\
    if (streq (t, (A))) return (B);
#include "keyword.h"
    return (lex_identifier);
}


/*
 *    READ A NUMBER
 *
 *    This routine reads a number beginning with a, returning the
 *    corresponding lexical token.  The actual value of the number is built
 *    up in token_value.
 */

static int
read_number(int a)
{
    int c = a, cl;
    number n = 0;
    do {
		n = 10 * n + (number) (c - '0');
		c = read_char ();
		cl = lookup_char (c);
    } while (is_digit (cl));
    unread_char (c);
    token_value = n;
    return (lex_number);
}


/*
 *    READ A HEXADECIMAL NUMBER
 *
 *    This routine reads a hexadecimal number beginning with a, returning the
 *    corresponding lexical token.  The actual value of the number is built
 *    up in token_value.
 */

static int
read_hex(int a)
{
    int c = a, cl;
    number n = 0;
    do {
		number d;
		if (c >= '0' && c <= '9') {
			d = (number ) (c - '0');
		} else if (c >= 'A' && c <= 'Z') {
			d = (number) (c - 'A') + 10;
		} else {
			d = (number) (c - 'a') + 10;
		}
		n = 16 * n + d;
		c = read_char ();
		cl = lookup_char (c);
    } while (is_hexdigit (cl));
    unread_char (c);
    token_value = n;
    return (lex_number);
}


/*
 *    READ A STRING
 *
 *    This routine reads a string.  It is entered after the initial
 *    quote has been read.  Note that there are no escape sequences.
 */

static int
read_string()
{
    int c;
    char *t = token_buff;
    while (c = read_char (), c != '"') {
		if (c == '\n' || c == LEX_EOF) {
			error (ERROR_SERIOUS, "Unexpected end of string");
			break;
		}
		*(t++) = (char) c;
		if (t == token_end) error (ERROR_FATAL, "Buffer overflow");
    }
    *t = 0;
    return (lex_string);
}


/*
 *    READ A COMMENT
 *
 *    This routine reads a C style comment, returning the lexical token
 *    immediately following.  It is entered after the first two characters
 *    have been read.
 */

static int
read_comment()
{
    int state = 0;
    char *t = token_buff;
    *(t++) = '/';
    *(t++) = '*';
    while (state != 2) {
		int c = read_char ();
		if (c == LEX_EOF) {
			error (ERROR_SERIOUS, "End of file in comment");
			return (lex_eof);
		}
		if (c == '*') {
			state = 1;
		} else if (state == 1 && c == '/') {
			state = 2;
		} else {
			state = 0;
		}
		*(t++) = (char) c;
		if (t == token_end) t = token_buff + 2;
    }
    *t = 0;
    if (first_comment == NULL) first_comment = xstrcpy (token_buff);
    return (read_token ());
}


/*
 *    CURRENT TOKEN
 *
 *    These variables are used by the parser to hold the current and former
 *    lexical tokens.
 */

int crt_lex_token;
int saved_lex_token;


/*
 *    PROCESS FILE
 *
 *    This routine processes the input file nm.  If r is true then it is
 *    processed using read_calculus, otherwise extra_calculus is used.
 */

void
process_file(char *nm, int r)
{
    crt_line_no = 1;
    crt_file_name = nm;
    lex_input = fopen (nm, "r");
    if (lex_input == NULL) {
		error (ERROR_SERIOUS, "Can't open input file, '%s'", nm);
		return;
    }
    ADVANCE_LEXER;
    if (r) {
		read_calculus ();
    } else {
		extra_calculus ();
    }
    if (crt_lex_token != lex_eof) {
		error (ERROR_SERIOUS, "Terminating due to syntax error");
    }
    fclose_v (lex_input);
    return;
}
