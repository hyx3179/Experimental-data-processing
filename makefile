objects = main.o library.o

edp : $(objects)
	gcc -o edp $(objects) -lm

mian.o : mian.c
library.o : library.c

.PHONY : clean
clean :
	-rm edp $(objects)