
#SRC = main.c 
SRC= $(wildcard *.c)
OBJ = $(SRC:.c=.o)
BIN = cozytool
PREFIX ?= /usr/local
DESTDIR = $(PREFIX)/bin

DEBUG=yes
ifeq ($(DEBUG),yes)
#	@echo "Warning target $(BIN) in debug mode"
	CFLAGS += -O0 -g -DSHOW_DEBUG 
else
	CFLAGS += -O3 -Wall -Werror -std=gnu99 
# -ansi -pedantic 
endif

CFLAGS += -Wall -I../include 
#LDFLAGS += -lpthread -L../lib
#LD =
CC ?= gcc


.PHONY: clean install

all: $(BIN)

$(BIN): $(OBJ)
	@echo Linking $< : 
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c %.h dbg.h
	@echo Compiling $< :
	$(CC) -o $@ -c $(CFLAGS) $<


#.depend: $(SRC) %.h
#        gcc -MM -o .depend $(CFLAGS) $(SRC)
#-include .depend

#.SUFFIXES:            # Delete the default suffixes
#.SUFFIXES: .c .o .h   # Define our suffix list
#.c.o:


clean:
	@echo "Removing files : $(OBJ) $(BIN)"
	@rm -vf $(OBJ) $(BIN) core *~

install:
	@echo "Installing $(BIN) in $(DESTDIR)"
	[ ! -d "$(DESTDIR)" ] && mkdir -p "$(DESTDIR)"
	install -m 755 $(BIN) "$(DESTDIR)"
	ifneq ($(DEBUG),yes)
		strip "$(DESTDIR)/($BIN)"
	endif

uninstall:
	@echo "Unnstalling $(BIN) in $(DESTDIR)"
	rm "$(DESTDIR)/$(BIN)"



###################
# R�gles Makefile #
###################
#cible: dependances...
#	commandes
#
# $@     Le nom de la cible
# $<     Le nom de la premi�re d�pendance
# $^     La liste des d�pendances
# $?     La liste des d�pendances plus r�centes que la cible
# $*     Le nom du fichier sans suffixe
# .PHONY On force les cibles sans regarder le fichier cible et d�pendances
# @      On affiche pas la commande execut�e
#
# $(subst FROM,TO,TEXT) faire une substitution
# $(patsubst PATTERN,REPLACEMENT,TEXT) faire une substitution dans une liste de mots
#
# CPPFLAGS : options pour le préprocesseur (defines ...) ;
# CFLAGS, CXXFLAGS : options pour le compilateur c, ou c++ (chemins pour les includes ...) ;
# LDFLAGS : options pour l'�diteur de liens (chemins pour les bibliothèques) ; et
# LDLIBS : biblioth�ques � utiliser pendant l'�dition de liens.
#
# R�f�rences :
#     http://www.gnu.org/software/make/manual/make.html


