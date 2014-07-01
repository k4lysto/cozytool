#include "dbg.h"
#include <stdio.h>
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
	test_debug();
	
	test_info_err_warn();

	if(argc < 2){
		printf("You need to put an argument.\n");	
	}else{
		if( *argv[2] == 'h')
		{
			printf("Help message");
		}
	}
	return 0;
}
