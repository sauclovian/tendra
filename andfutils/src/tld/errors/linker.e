#   		 Crown Copyright (c) 1997
#   
#   This TenDRA(r) Computer Program is subject to Copyright
#   owned by the United Kingdom Secretary of State for Defence
#   acting through the Defence Evaluation and Research Agency
#   (DERA).  It is made available to Recipients with a
#   royalty-free licence for its use, reproduction, transfer
#   to other parties and amendment for any purpose not excluding
#   product development provided that any such use et cetera
#   shall be deemed to be acceptance of the following conditions:-
#   
#       (1) Its Recipients shall ensure that this Notice is
#       reproduced upon any copies or amended versions of it;
#   
#       (2) Any amended version of it shall be clearly marked to
#       show both the nature of and the organisation responsible
#       for the relevant amendment or amendments;
#   
#       (3) Its onward transfer from a recipient to another
#       party shall be deemed to be that party's acceptance of
#       these conditions;
#   
#       (4) DERA gives no warranty or assurance as to its
#       quality or suitability for any purpose and DERA accepts
#       no liability whatsoever in relation to any use to which
#       it may be put.
#


header $[
#include <exds/common.h>
#include <exds/exception.h>
#include <exds/dstring.h>
#include "adt/name-key.h"
]$;

header(c) $[
#include "adt/solve-cycles.h"
]$;

error "cannot hide shape" {
    "there are no external ${shape name} names to hide",
    {
	"shape name" : "NStringT *" $[
	    write_nstring (ostream, closure->shape_name);
	]$
    }
};

error "cannot hide" {
    "there is no external ${shape name} named '${name}' to hide",
    {
	"shape name" : "NStringT *" $[
	    write_nstring (ostream, closure->shape_name);
	]$
    }, {
	"name" : "NameKeyT *" $[
	    write_name_key (ostream, closure->name);
	]$
    }
};

error "cannot hide undefined" {
    "cannot hide undefined external ${shape name} named '${name}'",
    {
	"shape name" : "NStringT *" $[
	    write_nstring (ostream, closure->shape_name);
	]$
    }, {
	"name" : "NameKeyT *" $[
	    write_name_key (ostream, closure->name);
	]$
    }
};

error "cannot keep shape" {
    "there are no external ${shape name} names to keep",
    {
	"shape name" : "NStringT *" $[
	    write_nstring (ostream, closure->shape_name);
	]$
    }
};

error "cannot keep" {
    "there is no external ${shape name} named '${name}' to keep",
    {
	"shape name" : "NStringT *" $[
	    write_nstring (ostream, closure->shape_name);
	]$
    }, {
	"name" : "NameKeyT *" $[
	    write_name_key (ostream, closure->name);
	]$
    }
};
