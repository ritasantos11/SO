lib:
	gcc -c list.c
	ar -rc liblist.a list.o
	ar -t liblist.a
	
example:
	gcc -Wall use_list.c -o use_list -L. -llist -lm

clean:
	rm *.o use_list
