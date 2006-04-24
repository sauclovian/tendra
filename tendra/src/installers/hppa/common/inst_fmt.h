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
$Log: inst_fmt.h,v $
 * Revision 1.1.1.1  1998/01/17  15:56:02  release
 * First version to be checked into rolling release.
 *
 * Revision 1.2  1995/12/18  13:11:40  wfs
 * Put hppatrans uder cvs control. Major Changes made since last release
 * include:
 * (i) PIC code generation.
 * (ii) Profiling.
 * (iii) Dynamic Initialization.
 * (iv) Debugging of Exception Handling and Diagnostics.
 *
 * Revision 5.2  1995/10/20  13:58:40  wfs
 * Declared "reg_name()" and "call_ins()" for gcc compilation.
 *
 * Revision 5.1  1995/09/15  14:09:47  wfs
 * Extra function declarations added to stop gcc complaining.
 *
 * Revision 5.0  1995/08/25  13:42:58  wfs
 * Preperation for August 25 Glue release
 *
 * Revision 3.3  1995/08/25  11:12:16  wfs
 * *** empty log message ***
 *
 * Revision 3.3  1995/08/25  11:12:16  wfs
 * *** empty log message ***
 *
 * Revision 3.1  95/04/10  16:26:57  16:26:57  wfs (William Simmonds)
 * Apr95 tape version.
 *
 * Revision 3.0  95/03/30  11:17:54  11:17:54  wfs (William Simmonds)
 * Mar95 tape version with CRCR95_178 bug fix.
 *
 * Revision 2.0  95/03/15  15:27:41  15:27:41  wfs (William Simmonds)
 * spec 3.1 changes implemented, tests outstanding.
 *
 * Revision 1.1  95/01/11  13:39:09  13:39:09  wfs (William Simmonds)
 * Initial revision
 *
*/


#ifndef INST_FMT_INCLUDED
#define INST_FMT_INCLUDED

#include "addrtypes.h"
#include "hppains.h"

extern char *ext_name(long);

extern void ldmb_ins(ins_p, int, int, int);
extern void ld_ins(ins_p, int, baseoff, int);

extern void st_ins(ins_p, int, baseoff);

extern void riir_ins(ins_p, ins_p, int, long, long, int);

extern void ir_ins(ins_p, ins_p, CONST char*, long, int);

extern void imm_to_r(long, int);

extern void set_ins(char*, baseoff, int);
extern void z_ins(ins_p);

extern void condrr_ins(char, ins_p, int, int, int, int);
extern void condri_ins(ins_p, int, long, int);

extern void extj_special_ins(CONST char *, int, char *, int);
extern void extj_reg_ins(ins_p, int);

extern void ret_ins(ins_p);

extern void ldf_ro_ins(ins_p, baseoff, int);
extern void ldf_rr_ins(ins_p,ins_p, int, int, int);
extern void ldf_ins(ins_p, baseoff, int);
extern void stf_ro_ins(ins_p, int, baseoff);
extern void stf_rr_ins(ins_p, int, int, int);
extern void stf_ins(ins_p, int, baseoff);

extern void rrf_ins(ins_p,ins_p,ins_p, int, int);
extern void rrrf_ins(ins_p, ins_p, int, int, int);

extern void rrf_cmp_ins(ins_p, int, int);
extern void immr_ins(ins_p, char*,char*,long,char*,int);
extern void ld_immr_ins(ins_p, char*,char*,long,char*,int,int);
extern void st_immr_ins(ins_p,int, char*,char*,long,char*,int);
extern void iiir_ins(ins_p,ins_p,int,int,int,int);
extern void bb_in(ins_p,int,int,int);
extern void rr_ins(ins_p, int, int);
extern void rrr_ins(ins_p, ins_p, int, int, int);
extern void ub_ins(CONST char*, int);
extern void cj_ins(CONST char*, int, int, int);
extern void st_ir_ins(ins_p, ins_p, int, ins_p, CONST char*, long, int);
extern void ld_ir_ins(ins_p, ins_p, ins_p, CONST char*, long, int, int);
extern void comb_ins(CONST char*, int, int, int);
extern void cmp_rrf_ins(ins_p, ins_p, ins_p, int, int);
extern void rrir_ins(ins_p, ins_p, int, int, long, int);
extern void cij_ins(CONST char*, long, int, int);
extern void irr_ins(ins_p, ins_p, ins_p, long, int, int);
extern void ld_rr_ins(ins_p, ins_p, int, int, int);
extern void r_ins(ins_p, int);
extern void out_directive(CONST char*, CONST char*);
extern void iir_ins(ins_p, ins_p, int, int, int);
extern void rir_ins(ins_p, ins_p, int, long, int);
extern CONST char* reg_name(int);
extern void call_ins(ins_p, char*, int, char*);
extern void outlab(char*, int);
extern void bl_in(ins_p, char*, int);
extern void ble_in(ins_p, char*, int, int);

int line,lines,nLabels;

#if FS_NO_ANSI_ENVIRON
typedef long FILE_POSN;
#define SET_FILE_POSN(A, B)		fseek((A), (B), SEEK_SET)
#define GET_FILE_POSN(A, B)		(B) = ftell((A))
#else
typedef fpos_t FILE_POSN;
#define SET_FILE_POSN(A, B)		fsetpos((A), & (B))
#define GET_FILE_POSN(A, B)		fgetpos((A), & (B))
#endif

typedef struct {
   FILE_POSN fpos;     /* position in outf  */
   ins_p  ins;        /* instruction       */
   ins_p  cc;        /* condition code    */
   int    op[4];    /* operands          */
   int    lab;     /* label             */
} psuedoIn;

typedef psuedoIn *pIn;

/* #define BLOCK 131072 */

#define BLOCK 65536
#define INCR  4096

pIn *pCode;
int *labIntro;  /*  `labIntro[lab]' will record the line number on
                     which label `lab' was introduced. */



#endif /* INST_FMT_INCLUDED */
