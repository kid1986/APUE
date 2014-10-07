3 : 3.o err_exit.o
	cc -o 3 3.o err_exit.o -lpthread

3.o : 3.c err_exit.h
	cc -c 3.c 
err_exit.o : err_exit.c err_exit.h
	cc -c err_exit.c

