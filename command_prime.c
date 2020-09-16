/*Parker Barton, program that displays the prime numbers in its command-line arguments, which are assumed to be integers.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_prime(int n){
int divisor;
if (n<=1){
  return 1;
}
for (divisor = 2; divisor * divisor <= n; divisor++){
  if (n % divisor == 0){
    return 0;}
	}
return 1;
}


int main(int argc, char* argv[])
{
if (argc > 1){
int i;
int nums[argc-1];
if (argc > 1){
for (i=1;i<argc;i++){
nums[i-1] = atoi(argv[i]);
}
}

printf("Prime numbers: ");

for (i=0;i<argc-1;i++){
if (is_prime(nums[i])){
printf("%d ", nums[i]);}
}
}
else{
printf("error: not enough arguments.");}

return 0;
}
