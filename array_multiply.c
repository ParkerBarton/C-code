/*Parker Barton, This program multiplies two arrays. The arrays are multiplied on an element-by-element basis*/

#include <stdio.h>
#include <stdlib.h>

/*This function does the multiplication*/
void multiply(int a1[], int n, int a2[], int a3[]){
int i;

for (i=0;i<n;i++){
a3[i] = a1[i]*a2[i];
}

for (i=0;i<n;i++){
printf("%d", a3[i]);
printf(" ");
}
}


int main(void)
{
int n, i;

printf("Enter the length of the arrays: ");
scanf("%d", &n);

int a1[n];
int a2[n];
int a3[n];

printf("Enter the elements of the array#1: ");
for (i=0;i<n;i++){
scanf("%d", &a1[i]);}

printf("Enter the elements of the array#2: ");
for (i=0;i<n;i++){
scanf("%d", &a2[i]);}

multiply(a1, n, a2, a3);



return 0;
}
