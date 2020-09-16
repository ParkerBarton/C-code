/*Parker Barton, this program reads in data from a file, sort the customers by the number of items purchased, and write the top 10 (by thenumber of items) customers to the output file.*/

#include <stdio.h>
#include <string.h>

struct customer {
char email[100];
int items;
char name[100];
};

void selection_sort(struct customer list[], int n)
{
  int i, largest = 0; 
struct customer temp;
 
  
 
  if (n == 1)
    return;

  for (i = 1; i < n; i++)
    if (list[i].items > list[largest].items)
      largest = i;

  if (largest < n - 1) {
    temp = list[n-1];
    list[n-1] = list[largest];
    list[largest] = temp;
  }
  
  selection_sort(list, n - 1);
}



int main(void)
{

FILE* fp;
fp  = fopen("customers.txt", "r" );


struct customer people[200];

int i = 0;

while (!feof(fp)){
fscanf(fp, "%s %d %[^\n]\n" , people[i].email, &people[i].items, people[i].name);
i++;}

selection_sort(people, 32);
int j;
FILE* fp2 = fopen("top10_customers.txt", "w" );

for(j=32;j>21;j--){
fprintf(fp2, "%s %d %s" , people[j].email, people[j].items, people[j].name);
fprintf(fp2, "\n");

}
return 0;
}
