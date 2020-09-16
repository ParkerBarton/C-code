#include "book.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct book *append_to_list(struct book *list){
char t[TITLE_LEN+1];
char f[NAME_LEN+1];
char l[NAME_LEN+1];
struct book *new_book, *head;
new_book = malloc(sizeof(struct book));
struct book *p;
int i, q, r, j, n;
double price;

printf("Enter book title: ");
q=read_line(t, TITLE_LEN+1);
printf("Enter author first name: ");
r=read_line(f, NAME_LEN+1);
printf("Enter author last name: ");
j=read_line(l, NAME_LEN+1);

if (list != NULL){
for (p = list; p != NULL; p = p->next){
if ((strcmp(p->title, t)==0) && (strcmp(p->first, f)==0) && (strcmp(p->last, l)==0)){
printf("book already exists, use update function to update the number of requests.");
return list;}}
head = list;
new_book->next = NULL;
while(head->next != NULL){
head = head->next;}
head->next = new_book;
}


printf("Enter price: ");
scanf("%lf", &price);
printf("Enter number of requests: ");
scanf("%d", &n);

for(i=0;i<q;i++){
new_book->title[i] = t[i];}
for(i=0;i<r;i++){
new_book->first[i] = f[i];}
for(i=0;i<j;i++){
new_book->last[i] = l[i];}
new_book->num_requests = n;
new_book->price = price;

if (list == NULL){
list = new_book;
new_book->next = NULL;
return list;}
 return list;

}

void update(struct book *list)
{struct book *p;
char t[TITLE_LEN+1];
char f[NAME_LEN+1];
char l[NAME_LEN+1];
printf("Enter book title: ");
read_line(t, TITLE_LEN+1);
printf("Enter author first name: ");
read_line(f, NAME_LEN+1);
printf("Enter author last name: ");
read_line(l, NAME_LEN+1);

for (p = list; p != NULL; p = p->next){
if ((strcmp(p->title, t)==0) && (strcmp(p->first, f)==0) && (strcmp(p->last, l)==0)){
printf("Enter number of requests: ");
scanf("%d", &p->num_requests);
return;}
}
printf("Book not found.");



}


void printList(struct book *list){
struct book *p;
for (p = list; p != NULL; p = p->next){
printf("Book: %s, Author: %s %s, Number of requests:  %d, Price: %lf", p->title, p->first, p->last, p->num_requests, p->price);
printf("\n");}
}
void clearList(struct book *list)
{struct book *p;
while(list != NULL){
p = list;
list = list->next;
if( p!= NULL){
free(p);}}


}

