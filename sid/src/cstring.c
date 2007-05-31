/*
 * Copyright (c) 2002-2005 The TenDRA Project <http://www.tendra.org/>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of The TenDRA Project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific, prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
/*
    		 Crown Copyright (c) 1997

    This TenDRA(r) Computer Program is subject to Copyright
    owned by the United Kingdom Secretary of State for Defence
    acting through the Defence Evaluation and Research Agency
    (DERA).  It is made available to Recipients with a
    royalty-free licence for its use, reproduction, transfer
    to other parties and amendment for any purpose not excluding
    product development provided that any such use et cetera
    shall be deemed to be acceptance of the following conditions:-

        (1) Its Recipients shall ensure that this Notice is
        reproduced upon any copies or amended versions of it;

        (2) Any amended version of it shall be clearly marked to
        show both the nature of and the organisation responsible
        for the relevant amendment or amendments;

        (3) Its onward transfer from a recipient to another
        party shall be deemed to be that party's acceptance of
        these conditions;

        (4) DERA gives no warranty or assurance as to its
        quality or suitability for any purpose and DERA accepts
        no liability whatsoever in relation to any use to which
        it may be put.
*/


/*
 * cstring.c - C string manipulation.
 *
 * This file implements the C string manipulation facility specified in the
 * file "cstring.h".  See that file for more details.
 */

#include <stddef.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#include "cstring.h"
#include "syntax.h"

char *
cstring_duplicate(char * cstring)
{
    unsigned length = cstring_length(cstring);
    char * tmp    = ALLOCATE_VECTOR(char, length + 1);

  (void)strcpy(tmp, cstring);
    return(tmp);
}

char *
cstring_duplicate_prefix(char * cstring, unsigned prefix)
{
    unsigned length = cstring_length(cstring);

    if (length <= prefix) {
	char * tmp = ALLOCATE_VECTOR(char, length + 1);

	(void)strcpy(tmp, cstring);
	return(tmp);
    } else {
	char * tmp = ALLOCATE_VECTOR(char, prefix + 1);

	(void)memcpy((void *)tmp, (void *)cstring, (size_t)prefix);
	tmp[prefix] = '\0';
	return(tmp);
    }
}

unsigned
cstring_hash_value(char * cstring)
{
    unsigned value = 0;

    while (*cstring) {
	value += ((unsigned)(*cstring++));
    }
    return(value);
}

unsigned
cstring_length(char * cstring)
{
    return((unsigned)strlen(cstring));
}

BoolT
cstring_equal(char * cstring1, char * cstring2)
{
    return(strcmp(cstring1, cstring2) == 0);
}

BoolT
cstring_ci_equal(char * cstring1, char * cstring2)
{
    char c1;
    char c2;

    do {
	c1 = toupper((unsigned char)*cstring1++);
	c2 = toupper((unsigned char)*cstring2++);
    } while ((c1) && (c2) && (c1 == c2));
    return(c1 == c2);
}

BoolT
cstring_to_unsigned(char * cstring, unsigned *num_ref)
{
    unsigned number = 0;

    if (*cstring == '\0') {
	return(FALSE);
    }
    do {
	int value = syntax_value(*cstring);

	if ((value == SYNTAX_NO_VALUE) || (value >= 10) ||
	    (((UINT_MAX - (unsigned)value) / (unsigned)10) < number)) {
	    return(FALSE);
	}
	number *= (unsigned)10;
	number += (unsigned)value;
    } while (*++ cstring);
    *num_ref = number;
    return(TRUE);
}

BoolT
cstring_starts(char * cstring, char * s)
{
    return(strncmp(cstring, s, strlen(s)) == 0);
}

BoolT
cstring_contains(char * cstring, char c)
{
    return(strchr(cstring, c) != NULL);
}

char *
cstring_find(char * cstring, char c)
{
    return(strchr(cstring, c));
}

char *
cstring_find_reverse(char * cstring, char c)
{
    return(strrchr(cstring, c));
}

char *
cstring_find_basename(char * cstring)
{
    char * bstring = cstring_find_reverse(cstring, '/');
    if (bstring != NULL) {
	cstring = bstring + 1;
    }
    return(cstring);
}
