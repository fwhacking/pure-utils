/*
 * Copyright (C) 2011 <fwhacking|gmail:com>
 *
 * This is free software, licensed under the GNU General Public License v2.
 * See /LICENSE for more information.
 *
 */

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "pure.h"

static void print_usage(const char *name)
{
	printf("Usage: %s PURE-FIRMWARE\n", name);
}

int main(int argc, char **argv)
{
	FILE *fd;
	PURE_HEADER *header;
	uint32_t *start;
	long size;

	if (argc != 2)
	{
		print_usage(argv[0]);
		exit(1);
	}

	fd = fopen(argv[1], "rb");
	if (fd == NULL)
	{
		printf("Could not read the firmware file '%s'\n", argv[1]);
		print_usage(argv[0]);
		exit(1);
	}

	size = fseek(fd, 0L, SEEK_END);
	size = ftell(fd);
	printf("Firmware file size '%s' : %ld bytes\n", argv[1], size);
	fseek(fd, 0L, SEEK_SET);

	start = malloc(size);

	fread(start, size, 1, fd);
	fclose(fd);

	header = (PURE_HEADER *) start;

	printf("----------------------------------------\n");
	printf("\t%s\t%10s\t%8s\n", "NAME", "OFFSET", "LENGTH");
	printf("----------------------------------------\n");

	printf("[0x%02lX]\tNVS1\t0x%08X\t%8d\n", offsetof(PURE_HEADER, nvs1), header->nvs1.offset, header->nvs1.length);
	printf("[0x%02lX]\tLDRS\t0x%08X\t%8d\n", offsetof(PURE_HEADER, ldrs), header->ldrs.offset, header->ldrs.length);
	printf("[0x%02lX]\tLDLK\t0x%08X\t%8d\n", offsetof(PURE_HEADER, ldlk), header->ldlk.offset, header->ldlk.length);
	printf("[0x%02lX]\tLDLZ\t0x%08X\t%8d\n", offsetof(PURE_HEADER, ldlz), header->ldlz.offset, header->ldlz.length);
	printf("[0x%02lX]\tLKGZ\t0x%08X\t%8d\n", offsetof(PURE_HEADER, lkgz), header->lkgz.offset, header->lkgz.length);
	printf("[0x%02lX]\tSQFS\t0x%08X\t%8d\n", offsetof(PURE_HEADER, sqfs), header->sqfs.offset, header->sqfs.length);
	printf("[0x%02lX]\tFREE\t0x%08X\t%8d\n", offsetof(PURE_HEADER, free), header->free.offset, header->free.length);

	printf("----------------------------------------\n");

	free(start);

	exit(0);
}
