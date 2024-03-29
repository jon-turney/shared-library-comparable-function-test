# with -O0, things appear to work correctly...
CFLAGS=-O2 -g --save-temps
# -fverbose-asm
# -mcmodel=large

all: xtest.exe

xlib.o: xlib.c
	gcc $(CFLAGS) -c -o $@ $<

cygxlib.dll: xlib.o
	gcc $(CFLAGS) -shared -Wl,--out-implib=libxlib.dll.a -o $@ $<
	objdump -p cygxlib.dll | grep ImageBase

xaw.o: xaw.c
	gcc $(CFLAGS) -c -o $@ $<

cygxaw.dll: xaw.o cygxlib.dll
	gcc $(CFLAGS) -shared -Wl,--out-implib=libxaw.dll.a -o $@ $<  -L. -lxlib
	objdump -p cygxaw.dll | grep ImageBase

xtest.o: xtest.c
	gcc $(CFLAGS) -c -o $@ $<

xtest.exe: xtest.o cygxlib.dll cygxaw.dll
	gcc $(CFLAGS) -L. -o $@ xtest.o -lxlib -lxaw

dist: *.c *.h Makefile
	tar cjf libtest.tar.bz2 *.c *.h Makefile

clean:
	rm -f xtest.exe cygxlib.dll libxlib.dll.a *.o *.s *.i

test: xtest.exe
	@rebase -v -b 0x400000000 cygxaw.dll
	@rebase -v -b 0x410000000 cygxlib.dll
	@./xtest
	@rebase -v -b 0x400000000 cygxaw.dll
	@rebase -v -b 0x600000000 cygxlib.dll
	@./xtest
