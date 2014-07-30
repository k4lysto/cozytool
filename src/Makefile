DEBUG=yesq
ifeq ($(DEBUG),yes)
#	@echo "Warning target $(BIN) in debug mode"
	CFLAGS += -O0 -g -Wall -DSHOW_DEBUG 
else
	CFLAGS += -O3 -Wall -Werror -std=gnu99 
# -ansi -pedantic 
endif

all: cozytool

cozytool: main.o
	gcc -o cozytool main.o

main.o: main.c dbg.h
	gcc -c $(CFLAGS) main.c

clean:
	rm -f cozytool *.o

