all: a.exe # default target without specifying target

a.exe:	HelloWorld.c # a.exe depends on HelloWorld.c
	gcc HelloWorld.c

run:	a.exe # run depends on a.exe
	.\a.exe

clean: # clean target
	del /Q /F *.exe