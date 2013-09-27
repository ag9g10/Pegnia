IDIR=../include
ODIR=obj
LDIR=../lib

CC=gcc
CFLAGS=-Wall -O2 -I$(IDIR)

LIBS=-lncurses -lm

_DEPS=dungeon.h tile.h
DEPS=$(patsubst %,$(IDIR)/%, $(_DEPS))

_OBJ=dungeon.o test_dungeon.o tile.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: test_dungeon

test_dungeon: $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ core $(INCDIR)/*~
