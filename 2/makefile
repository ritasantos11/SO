lib:
	gcc -c matrix.c
	ar -rc libmatrix.a matrix.o
	ar -t libmatrix.a
	
example:
	gcc -Wall use_matrix.c -o use_matrix -L. -lmatrix -lm

clean:
	rm *.o use_matrix