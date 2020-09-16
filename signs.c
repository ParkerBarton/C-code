/*Parker Barton
 * This program calculates the Chinese animal sign for a year of birth entered by the user.*/

#include <stdio.h>

int main(void)
{
	int year;
	printf("Enter the year of birth: ");
	scanf("%d", &year);

	int n = year % 12;

	switch (n)
	{
    	case 0:
    		printf("The Chinese animal sign for %d is Monkey", year);
    		break;

    	case 1:
    		printf("The Chinese animal sign for %d is Rooster", year);
    		break;

    	case 2:
    		printf("The Chinese animal sign for %d is Dog", year);
    		break;

    	case 3:
    		printf("The Chinese animal sign for %d is Pig", year);
    		break;	

    	case 4:
    		printf("The Chinese animal sign for %d is Rat", year);
    		break;	

    	case 5:
    		printf("The Chinese animal sign for %d is Ox", year);
    		break;
    		
    	case 6:
    		printf("The Chinese animal sign for %d is Tiger", year);
    		break;
    		
    	case 7:
    		printf("The Chinese animal sign for %d is Rabbit", year);
    		break;
    		
    	case 8:
    		printf("The Chinese animal sign for %d is Dragon", year);
    		break;
    		
    	case 9:
    		printf("The Chinese animal sign for %d is Snake", year);
    		break;
    		
    	case 10:
    		printf("The Chinese animal sign for %d is Horse", year);
    		break;						

    	case 11:
    		printf("The Chinese animal sign for %d is Sheep", year);
    		break;
    		

    	default:
    		printf("error, that is nat a valid year.");
    		
    }		

    return 0;

}
