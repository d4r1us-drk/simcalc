all: simcalc

WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2

simcalc: Makefile main.c
	$(CC) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) main.c

clean:
	rm -f simcalc

install:
	echo "Installing is not supported"

run:
	./simcalc

