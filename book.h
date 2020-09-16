#ifndef BOOK_H
#define TITLE_LEN 100
#define NAME_LEN 30

struct book{
        char title[TITLE_LEN+1];
        char first[NAME_LEN+1];
        char last[NAME_LEN+1];
        double price;
        int num_requests;
        struct book *next;
};


struct book *append_to_list(struct book *list);
void update(struct book *list);
void printList(struct book *list);
void clearList(struct book *list);
int read_line(char str[], int n);
 #endif                                          
