all: sort_word

sort_word: sort_word.o link_list.o
	gcc -o sort_word sort_word.o link_list.o

sort_word.o: sort_word.c
	gcc -c sort_word.c

link_list.o: link_list.c
	gcc -c link_list.c

clean:
	rm *.o sort_word
