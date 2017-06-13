all:
	gcc -o vtimer vtimer.c -lcurses
install:
	cp vtimer /usr/bin
