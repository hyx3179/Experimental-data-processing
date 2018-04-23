objects = main.o definearray.o uncertaintyassessment.o \
differenceaverage.o library.o svbmp.o

edp : $(objects)
	gcc -s -o edp $(objects) -lm

mian.o : mian.c
definearray.o : definearray.c
uncertaintyassessment.o : uncertaintyassessment.c
differenceaverage.o : differenceaverage.c
svbmp.o : svbmp.c
library.o : library.c

.PHONY : clean
clean :
	-rm edp $(objects)
