#include <stdio.h>
#include "book.h"
#include "readline.h"

/*Parker Barton, this program maintains a list of book requests from the students for the classroom library. Each book was stored with the title, author’s first name, last name, price, and number of requests*/
/**********************************************************
 *  * main: Prompts the user to enter an operation code,     *
 *   *       then calls a function to perform the requested   *
 *    *       action. Repeats until the user enters the        *
 *     *       command 'q'. Prints an error message if the user *
 *      *       enters an illegal code.                          *
 *       **********************************************************/
int main(void)
{
  char code;

  struct book *book_list = NULL;  
  printf("Operation Code: a for appending to the list, u for updating a book"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': book_list = append_to_list(book_list);
                break;
      case 'u': update(book_list);
                break;
      case 'p': printList(book_list);
                break;
      case 'q': clearList(book_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

