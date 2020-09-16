/*Parker Barton, This program adds a range(by start index and end index) of numbers from array#1 to array#2at a given position(index)while removing them from array #1 . */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int n, n2, i, start, end, index;
int *a1;
int *a2;

printf("Enter the length of the array#1: ");
scanf("%d", &n);
a1 = malloc(sizeof(int)*n);

printf("Enter the elements of the array#1: ");
for (i = 0; i < n; i++){  
scanf("%d", &a1[i]);}

printf("Enter the length of the array#2: ");
scanf("%d", &n2);
a2 = malloc(sizeof(int)*n2);

printf("Enter the elements of the array#2: ");
for (i = 0; i < n2; i++){  
scanf("%d", &a2[i]);}

printf("Enter the start and end indexof array #1 to be removed: ");
scanf("%d %d", &start, &end);

int a3[(end-start)+1];

printf("Enter the position(index)of the array #2 to be added before: ");
scanf("%d", &index);



/*--------------------------------*/
for (i=0;i<=end;i++){
a3[i] = a1[start+i];
}
/*--------------------------------*/


/*--------------------------------*/
/*This chunk of code 'deletes' the elements from array 1*/

for (i=0;i < (n - end - 1);i++){
a1[start + i] = a1[end + i + 1];
a1[end + i + 1] = 0;
}
printf("Output array1: ");


for (i=0;i < (n - (end-start+1));i++){
printf("%d", a1[i]);
printf(" ");
}

/*--------------------------------*/
/*This chunk of code inserts the range of elements into array 2.*/

int n3 = (n2+(end-start+1));
int a4[n3];

for (i=0;i<index;i++){
a4[i] = a2[i];
}
int k = 0;
for (i=index;i<(index+(end-start+1));i++){
a4[i] = a3[k++];
} 

for (i=0;i<n3;i++){
a4[(index+(end-start+1))+i] = a2[index + i];
}

/*---------------------------------*/
printf("\n");
printf("Output array2: ");
for (i=0;i<(n3);i++){
printf("%d", a4[i]);
printf(" ");
}





return 0;
}
