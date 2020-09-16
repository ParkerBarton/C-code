/*Parker Barton
 * this program rsandomly generates and prints 12 spins along with the number of times the user got two or more of the same symbol.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*This function prints the symbol that corresponds to a randomly generated number. */

void pull_lever(int n){
switch (n){
        case 1:
                printf("Heart");
                break;
        case 2:
                printf("Apple");
                break;
        case 3:
                printf("Orange");   
                break;
        case 4:
                printf("Lime");
                break;
        case 5:
                printf("Sun");
                break;
        case 6: 
                printf("mountain");
                break;
        case 7:
                printf("Mickey");
                break;  
        case 8:
                printf("Banana");
                break;         
        case 9:
                printf("Cherry");
                break;
        case 10:
                printf("Garfield");
                break;
        case 11:
                printf("Television");
                break;
        case 12:
                printf("Coolers");
                break;
        case 13:
                printf("Lemonade");
                break;


}
}
int main()
{
srand(time(NULL));
int count = 0;
int a = 0;

for(; a < 3; a++)
{
	int n1 = rand() % (13-1+1)+1;
	int n2 = rand() % (13-1+1)+1;
	int n3 = rand() % (13-1+1)+1;
	if(n1 == n2 || n2 == n3 || n3 == n1) {
         ++count;
	}
 pull_lever(n1);
printf(" ");
pull_lever(n2);
printf(" ");
pull_lever(n3);
printf("\n ");
 }
printf("You have 2 or more same symbols in %d spins.", count);  
return 0;
}


