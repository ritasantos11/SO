lib:
	gcc -c vector.c
	ar -rc libvector.a vector.o
	ar -t libvector.a
	
example:
	gcc -Wall use_vector.c -o use_vector -L. -lvector -lm

clean:
	rm *.o use_vector
