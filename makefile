book_requests: readline.o book.o book_requests.o
	gcc -o book_requests readline.o book.o book_requests.o

book_requests.o: book_requests.c
	gcc -c book_requests.c

book.o: book.c
	gcc -c book.c

readline.o: readline.c
	gcc -c readline.c

