/**
 * @file main.c
 *
 * @brief cozytool main function
 *
 * Copyright (C) 2014-2015 CozyCorp
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "dbg.h"

#define PROGRAM_NAME "cozytool"
#define VERSION_MAJOR 0
#define VERSION_MINOR 1

const char USAGE[] = "\
 Usage : %s  [OPTIONS]\n\
 \n\
 An awsome tool doing a lot of marvelous things\n\
 \n\
 [OPTIONS]\n\
   -h                        Usage help\n\
   -v                        Verbose trace mode\n\
   -f delete:non-ascii       delete non-ascii/printables chars from STDIN input\n\
 \n\
 (Copyright CozyCorp 2014 - Release v%d.%02d - %s)\n\
 ";

void test_debug()
{
	debug("Cozypet tests the debug for the %d time.\n ", 2);
}

void test_info_err_warn()
{
	DEBUG_INFO("Cozypet is testing the debug for the %d time.\n", 2);
	DEBUG_ERR("Cozypet tests the debug for the %d time.\n", 1);
	DEBUG_WARN("Be careful! Cozypet tests the debug for the %d time.\n", 2);
}

void usage(void)
{
    fprintf(stderr, USAGE, PROGRAM_NAME, VERSION_MAJOR, VERSION_MINOR, __DATE__);
    exit(EXIT_FAILURE);
}


int main(int argc, char* argv[])
{	
	int option;
	int flag_filter_non_ascii = 0;
	int n;
	char ch;
	
//	test_debug();
//	test_info_err_warn();
	while ((option = getopt(argc, argv, "hf:")) != -1) {
		switch (option)
		{
		case 'f':
			if (strstr(optarg, "delete:non-ascii")) {
				flag_filter_non_ascii = 1;
				DEBUG_INFO("filter activated: delete:non-ascii");
			} else {
				usage();
			}
			break;
		case 'h':
		default:
			usage();
		}
	}

	
	while (1) {
		n = read(STDIN_FILENO, (void *)&ch, 1);
		if (n <= 0) {
			return 0;
		}
		if (flag_filter_non_ascii && (! isprint(ch))) {
			continue; // do nothing
		}
		write(STDOUT_FILENO, (void *)&ch, 1);
	}

	return 0;
}
