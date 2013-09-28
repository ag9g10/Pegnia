IDIR=../include
ODIR=obj
LDIR=../lib

CC=gcc
CFLAGS=-g -Wall -O2 -I$(IDIR)

LIBS=-lncurses -lm

_DEPS=dungeon.h tile.h character.h mob.h generator.h utils.h mt19937ar.h p_math.h
DEPS=$(patsubst %,$(IDIR)/%, $(_DEPS))

_OBJ=dungeon.o tile.o character.o mob.o generator.o utils.o mt19937ar.o p_math.o test_dungeon.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: test

test: $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~
