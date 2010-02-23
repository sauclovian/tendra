/*
 * Copyright (c) 2002-2006 The TenDRA Project <http://www.tendra.org/>.
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


#ifndef EXP_INCLUDED
#define EXP_INCLUDED


/*
    TDF EXP ENCODING ROUTINES

    The routines in this module are concerned with the encoding of TDF
    EXPs and related sorts.
*/

#if TDF_OUTPUT
extern BITSTREAM *enc_exp(BITSTREAM *, EXP);
extern BITSTREAM *enc_addr_exp(BITSTREAM *, TYPE, EXP);
extern BITSTREAM *enc_cont_exp(BITSTREAM *, TYPE, EXP);
extern BITSTREAM *enc_null_exp(BITSTREAM *, TYPE);
extern BITSTREAM *enc_make_int(BITSTREAM *, TYPE, int);
extern BITSTREAM *enc_make_snat(BITSTREAM *, int);
extern BITSTREAM *enc_condition(BITSTREAM *, EXP, ulong, ulong);
extern BITSTREAM *enc_assign_op(BITSTREAM *, TYPE, int *);
extern BITSTREAM *enc_cont_op(BITSTREAM *, TYPE, int *);
extern BITSTREAM *enc_ntest(BITSTREAM *, NTEST);
extern BITSTREAM *enc_exp_list(BITSTREAM *, LIST(EXP));
extern BITSTREAM *enc_dummy_exp(BITSTREAM *, TYPE, ulong, OFFSET, int, int);
extern BITSTREAM *enc_compare(BITSTREAM *, EXP, EXP, NTEST, ulong, ulong);
extern BITSTREAM *enc_error_treatment(BITSTREAM *, TYPE);
extern EXP simplify_cond(EXP, int *);
#endif


#endif