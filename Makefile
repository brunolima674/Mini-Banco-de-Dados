all: lista_ordenada

run:
	./lista

lista_ordenada: main.o sorted_linked_list.o
	gcc -g -o lista main.o sorted_linked_list.o

main.o: main.c sorted_linked_list.h
	gcc -g -o main.o main.c -c

lista.o: sorted_linked_list.c sorted_linked_list.h
	gcc -g -o sorted_linked_list.o sorted_linked_list -c

clean:
	rm -rf *.o

zip:
	zip -r lista.zip Makefile ./*c ./*h
