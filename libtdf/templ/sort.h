/* $Id$ */

/*
 * Copyright 2015, The TenDRA Project.
 *
 * See doc/copyright/ for the full copyright terms.
 */

@use all
#ifndef TDF_SORT_H
#define TDF_SORT_H

/* AUTOMATICALLY GENERATED BY %ZX VERSION %ZV FROM TDF %VA.%VB */

enum tdf_sort {
@loop sort
@if sort.basic
	SORT_%20ST      %48t= %SCE,
@endif
@end

	SORT_FOREIGN    %48t= -1,
	SORT_UNKNOWN    %48t=  0
};

#endif

