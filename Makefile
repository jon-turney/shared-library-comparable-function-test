PROGRAMS=xtest.exe xtest2.exe
CFLAGS=-O2 -g

all: $(PROGRAMS)

xlib.o: xlib.c
	gcc $(DEFINES) $(CFLAGS) -c -o $@ $<

cygxlib.dll: xlib.o
	gcc $(CFLAGS) -shared -Wl,--out-implib=libxlib.dll.a -Wl,--enable-auto-import -Wl,--export-all -Wl,--exclude-libs,ALL -o $@ $<


xtest.o: xtest.c
	gcc $(CFLAGS) -c -o $@ $<

x1.o: x1.c
	gcc $(CFLAGS) -c -o $@ $<

x2.o: x2.c
	gcc $(CFLAGS) -c -o $@ $<

xtest.exe: xtest.o x1.o x2.o cygxlib.dll
	gcc $(CFLAGS) -L. -o $@ xtest.o x1.o x2.o -lxlib

xtest2.exe: xtest.o x1.o x2.o cygxlib.dll 
	gcc $(CFLAGS) -L. -o $@ xtest.o x1.o x2.o -lxlib

dist: *.c *.h Makefile
	tar cjf libtest.tar.bz2 *.c *.h Makefile

clean:
	rm -f $(PROGRAMS) cygxlib.dll libxlib.dll.a *.o *.s *.i
