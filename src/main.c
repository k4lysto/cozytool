#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M,...)
#else 
#define debug(M,...) fprintf(stderr, "DEBUG %s %d: " M "\n", __FILE__, __LINE__,##__VA_ARGS__)
#endif 

int main(int argc, char* argv[])
{	
	
	if(argc < 2){
		printf("You need to put an argument.");	
	}else{
		if( *argv[2] == 'h')
		{
			printf("Help message");
		}
	}
}
