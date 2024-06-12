simul.out: Client.o Func.o
	gcc -o simul.out Client.o Func.o

Client.o : Client.c
	gcc -c -o Client.o Client.c

Func.o : ClientFunc.c
	gcc -c -o Func.o ClientFunc.c

clean :
	rm *.o app.out