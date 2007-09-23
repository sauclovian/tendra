/*
 * The lexical analyser for Sid's C actions parser.
 * $Id$
 */

/*
 *  AUTOMATICALLY GENERATED BY lexi VERSION 2.0
 */


#include <assert.h>
#include <stdint.h>

/* LOOKUP TABLE */

typedef uint8_t lexi_lookup_type;
static lexi_lookup_type lookup_tab[257] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00,
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
	0x44, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46,
	0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46,
	0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46, 0x46,
	0x46, 0x46, 0x46, 0x00, 0x00, 0x00, 0x00, 0x46,
	0x00, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e,
	0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e,
	0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e,
	0x5e, 0x5e, 0x5e, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00
};

#ifndef LEX_EOF
#define LEX_EOF		256
#endif

/*
 * Lexi's buffer is a simple stack. The size is calculated as
 * max(mapping) - 1 + max(token) - 1
 */
static int lexi_buffer[2 - 1];
static int lexi_buffer_index;

/* Push a character to lexi's buffer */
static void lexi_push(const int c) {
	assert(lexi_buffer_index < sizeof lexi_buffer / sizeof *lexi_buffer);
	lexi_buffer[lexi_buffer_index++] = c;
}

/* Pop a character from lexi's buffer */
static int lexi_pop(void) {
	assert(lexi_buffer_index > 0);
	return lexi_buffer[--lexi_buffer_index];
}

/* Flush lexi's buffer */
static void lexi_flush(void) {
	lexi_buffer_index = 0;
}

/* Read a character */
static int lexi_readchar(void) {
	if(lexi_buffer_index) {
		return lexi_pop();
	}

	return read_char();
}

#define lookup_char(C)	((int)lookup_tab[(C)])
#define is_white(T)	((T) & 0x01)
#define is_identstart(T)	((T) & 0x02)
#define is_identbody(T)	((T) & 0x04)
#define is_builtinstart(T)	((T) & 0x08)
#define is_builtinbody(T)	((T) & 0x10)
#define is_builtindlmt(T)	((T) & 0x20)
#define is_act_identbody(T)	((T) & 0x40)



/* lexer_state_definition */

typedef struct lexer_state_tag {
	int (*zone_function)(struct lexer_state_tag*);
	} lexer_state;


int read_token(lexer_state*);


/* ZONES PASS ANALYSER PROTOTYPES*/

int
read_token_zone_act(struct lexer_state_tag* state);
int
read_token_zone_singleline_comment(struct lexer_state_tag* state);
int
read_token_zone_bracketed_comment(struct lexer_state_tag* state);
int
read_token_zone_global(struct lexer_state_tag* state);


/* ZONES PASS ANALYSER */

/* MAIN PASS ANALYSER for zone act*/

int
read_token_zone_act(struct lexer_state_tag* state)
{
	start: {
	int c0 = lexi_readchar(), t0;
	t0 = lookup_char(c0);
	if (is_white(t0)) goto start;
	if (c0 == '@') {
	    int c1 = lexi_readchar(), t1;
	    switch (c1) {
		case '!': {
		    return(C_TOK_ACT_EXCEPTION);
		}
		case '&': {
		    return(c_lexer_act_read_reference(c0, c1));
		}
		case '.': {
		    return(C_TOK_ACT_TERMINAL);
		}
		case ':': {
		    return(c_lexer_act_read_label(c0, c1));
		}
		case '=': {
		    return(c_lexer_act_read_modifiable(c0, c1));
		}
		case '>': {
		    return(C_TOK_ACT_ADVANCE);
		}
		case '@': {
		    return(C_TOK_ACT_AT);
		}
		case '}': {
		    state->zone_function=&read_token_zone_global;
		    return(C_TOK_ACT_CODEEND);
		}
	    }
	    t1 = lookup_char(c1);
	    if (is_identstart(t1)) {
		return(c_lexer_act_read_identifier(c0, c1));
	    }
	    lexi_push(c1);
	} else if (c0 == LEX_EOF) {
	    return(C_TOK_ACT_EOF);
	}
	return(c_lexer_act_read_string(c0));
	}
}
/* MAIN PASS ANALYSER for zone singleline_comment*/

int
read_token_zone_singleline_comment(struct lexer_state_tag* state)
{
	start: {
	int c0 = lexi_readchar(), t0;
	t0 = lookup_char(c0);
	if (is_white(t0)) goto start;
	if (c0 == '\n') {
	    state->zone_function=&read_token_zone_global;
	    return(read_token(state));
	}
	return(read_token(state));
	}
}
/* MAIN PASS ANALYSER for zone bracketed_comment*/

int
read_token_zone_bracketed_comment(struct lexer_state_tag* state)
{
	start: {
	int c0 = lexi_readchar(), t0;
	t0 = lookup_char(c0);
	if (is_white(t0)) goto start;
	if (c0 == '*') {
	    int c1 = lexi_readchar();
	    if (c1 == '/') {
		state->zone_function=&read_token_zone_global;
		return(read_token(state));
	    }
	    lexi_push(c1);
	}
	return(read_token(state));
	}
}
/* MAIN PASS ANALYSER for zone global*/

int
read_token_zone_global(struct lexer_state_tag* state)
{
	start: {
	int c0 = lexi_readchar(), t0;
	t0 = lookup_char(c0);
	if (is_white(t0)) goto start;
	switch (c0) {
	    case '&': {
		return(C_TOK_REFERENCE);
	    }
	    case '(': {
		return(C_TOK_OPEN_TUPLE);
	    }
	    case ')': {
		return(C_TOK_CLOSE_TUPLE);
	    }
	    case ',': {
		return(C_TOK_SEPARATOR);
	    }
	    case '-': {
		int c1 = lexi_readchar();
		if (c1 == '>') {
		    return(C_TOK_ARROW);
		}
		lexi_push(c1);
		break;
	    }
	    case '/': {
		int c1 = lexi_readchar();
		if (c1 == '*') {
		    state->zone_function=&read_token_zone_bracketed_comment;
		    return(read_token(state));
		} else if (c1 == '/') {
		    state->zone_function=&read_token_zone_singleline_comment;
		    return(read_token(state));
		}
		lexi_push(c1);
		break;
	    }
	    case ':': {
		return(C_TOK_TYPEMARK);
	    }
	    case ';': {
		return(C_TOK_TERMINATOR);
	    }
	    case '<': {
		return(C_TOK_BEGIN_ACTION);
	    }
	    case '=': {
		return(C_TOK_DEFINE);
	    }
	    case '>': {
		return(C_TOK_END_ACTION);
	    }
	    case '@': {
		int c1 = lexi_readchar();
		if (c1 == '{') {
		    state->zone_function=&read_token_zone_act;
		    return(C_TOK_ACT_CODESTART);
		}
		lexi_push(c1);
		break;
	    }
	}
	if (is_identstart(t0)) {
	    return(c_lexer_read_identifier(c0));
	} else if (is_builtindlmt(t0)) {
	    int c1 = lexi_readchar(), t1;
	    t1 = lookup_char(c1);
	    if (is_builtinstart(t1)) {
		return(c_lexer_read_builtin(c0, c1));
	    }
	    lexi_push(c1);
	}
	return(unknown_token(c0));
	}
}
lexer_state current_lexer_state_v={&read_token_zone_global};
lexer_state* current_lexer_state=&current_lexer_state_v;

read_token(lexer_state* state)
{
	return((*(state->zone_function))(state));
}
