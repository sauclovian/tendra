/* $Id$ */

#ifndef __HACKED_STDDEF_H
#define __HACKED_STDDEF_H

/*
 * glibc does not provide this header; it is expected to be provided by gcc.
 * The definitions here must be compatible.
 */

#if defined(_GLIBC2_5) || defined(_GLIBC2_7) || defined(_GLIBC2_11) \
	|| defined(_GLIBC2_12) || defined(_GLIBC2_14) || defined(_GLIBC2_15) \
	|| defined(_GLIBC2_17) || defined(_GLIBC2_19)

#define NULL 0

typedef unsigned int size_t;

typedef int ptrdiff_t;

typedef long int wchar_t;

#pragma TenDRA begin
#pragma TenDRA keyword __literal for keyword literal
#pragma TenDRA conversion analysis (pointer-int) off
#define offsetof(__s, __m) (__literal (size_t) &(((__s *) 0)->__m))
#pragma TenDRA end

#endif

#if defined(_EGLIBC2_11) || defined(_EGLIBC2_15)

#define NULL 0

typedef unsigned int size_t;

typedef int ptrdiff_t;

typedef int wchar_t;

#pragma TenDRA begin
#pragma TenDRA keyword __literal for keyword literal
#pragma TenDRA conversion analysis (pointer-int) off
#define offsetof(__s, __m) (__literal (size_t) &(((__s *) 0)->__m))
#pragma TenDRA end

#endif

#endif

