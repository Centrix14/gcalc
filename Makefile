all:
	gcc gcalc.c -o gcalc `pkg-config --cflags --libs gtk+-3.0`
