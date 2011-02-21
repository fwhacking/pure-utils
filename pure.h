/*
 * Copyright (C) 2011 <fwhacking|gmail:com>
 *
 * This is free software, licensed under the GNU General Public License v2.
 * See /LICENSE for more information.
 *
 */

#ifndef _PURE_H_
#define _PURE_H_

typedef struct _PURE_PART
{
	uint32_t name;
	uint32_t offset;
	uint32_t length;
	uint32_t empty;
} PURE_PART;

typedef struct _PURE_HEADER
{
	PURE_PART nvs1;
	PURE_PART ldrs;
	PURE_PART ldlk;
	PURE_PART ldlz;
	PURE_PART lkgz;
	PURE_PART sqfs;
	PURE_PART free;
} PURE_HEADER;

#endif // _PURE_H_
