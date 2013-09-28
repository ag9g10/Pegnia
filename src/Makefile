IDIR=../include
ODIR=obj
LDIR=../lib

CC=gcc
CFLAGS=-Wall -O2 -I$(IDIR)

LIBS=-lncurses -lm

_DEPS=dungeon.h tile.h character.h mob.h
DEPS=$(patsubst %,$(IDIR)/%, $(_DEPS))

_OBJ=dungeon.o tile.o character.o mob.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: test

test: $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~
