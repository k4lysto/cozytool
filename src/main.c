#include "dbg.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void test_debug(){
	debug("Cozypet tests the debug for the %d time.\n ", 2);

}

void test_info_err_warn(){

	DEBUG_INFO("Cozypet is testing the debug for the %d time.\n", 2);
	DEBUG_ERR("Cozypet tests the debug for the %d time.\n", 1);
	DEBUG_WARN("Be careful! Cozypet tests the debug for the %d time.\n", 2);

}

int main(int argc, char* argv[])
{	
//	char *hvalue = NULL;
	char *fvalue = NULL;
	int index;
	int option;
	opterr = 0;
	test_debug();
	test_info_err_warn();
	while ((option = getopt (argc, argv, "hf:")) != -1)
		switch (option)
			{
			case 'h':
				//hvalue = optarg;
				printf("This tool is a text tool.\n");
			break;
			case 'f':
				fvalue = optarg;	
				if(isalpha(atoi(fvalue))){
					fprintf(stderr,"This is not a alpha num value: %s.\n", fvalue);
				}else fprintf(stderr, "This is a alpha num value: %s.\n", fvalue);
			break;
			case '?':
				if (optopt == 'f')
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint (optopt))
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				else
					fprintf (stderr,"Unknown option character `\\x%x'.\n",optopt);
				return 1;
			default:
			abort ();
			}
	printf (" fvalue = %s\n", fvalue);
	for (index = optind; index < argc; index++)printf ("Non-option argument %s\n", argv[index]);

	return 0;
}
