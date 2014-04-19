/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#ifndef COMMENT_INCLUDED
#define COMMENT_INCLUDED

#include "exptypes.h"

#include <reader/codetypes.h>
#include <construct/installtypes.h>


extern bool do_comment;
extern void fail(char *);


#ifdef DO_COMMENT

/* Commenting routines */
extern void comment(char *);
extern void comment1(char *, long);
extern void comment2(char *, long, long);
extern void comment3(char *, long, long, long);
extern void comment4(char *, long, long, long, long);

#else /* DO_COMMENT */

/* Dummy commenting macros */
#define comment(s)
#define comment1(s, a)
#define comment2(s, a, b)
#define comment3(s, a, b, c)
#define comment4(s, a, b, c, d)

#endif /* DO_COMMENT */


#ifdef DO_FULLCOMMENT

/* Full comments */
#define FULLCOMMENT(s)		comment(s)
#define FULLCOMMENT1(s, a)		comment1(s, a)
#define FULLCOMMENT2(s, a, b)		comment2(s, a, b)
#define FULLCOMMENT3(s, a, b, c)	comment3(s, a, b, c)
#define FULLCOMMENT4(s, a, b, c, d)	comment4(s, a, b, c, d)

#ifdef DO_PRTDF

/* TDF printing routines */
#define EXP_NUM(x)			(int)(x)
#define SH_NAME(x)			sh_name(x)
#define TAG_NAME(x)			tag_name(x)
#define ANSDISCRIM_NAME(x)		ansdiscrim_name(x)
#define PRTDF(s, e)			prtdf(s, e)

#else /* DO_PRTDF */

/* Dummy TDF printing macros */
#define EXP_NUM(x)			(int)(x)
#define SH_NAME(x)			(0)
#define TAG_NAME(x)			(0)
#define ANSDISCRIM_NAME(x)		(0)
#define PRTDF(s, e)			(0)

#endif /* DO_PRTDF */

#else /* DO_FULLCOMMENT */

/* Dummy full commenting macros */
#define FULLCOMMENT(s)
#define FULLCOMMENT1(s, a)
#define FULLCOMMENT2(s, a, b)
#define FULLCOMMENT3(s, a, b, c)
#define FULLCOMMENT4(s, a, b, c, d)
#define PRTDF(s, e)

#endif /* DO_FULLCOMMENT */

#endif /* COMMENT_INCLUDED */