/*Parker Barton, program that reads in the lengths of the three sides of a triangle.*/

#include <stdio.h>

int main(void)
{

float s1, s2, s3;

printf("Enter the lengths of three sides of the triangle: ");
scanf("%f %f %f", &s1, &s2, &s3);

if ((s1 + s2) > s3 && (s2 +s3) > s1 && (s1 + s3) > s2){
	if (s1==s2 && s1==s3)
		printf("The three sides form a triangle. The triangle is equilateral.");
	else if ((s1==s2 && s1!=s3) || (s1==s3 && s1!=s2) || (s2==s3 && s2!=s1))
		printf("The three sides form a triangle. The triangle is isosceles.");
	else if (((s1*s1)+(s2*s2))==(s3*s3))
		printf("The three sides form a triangle. The triangle is right-angled.");}
else{
	printf("The three sides do not form a triangle. ");
}


return 0;
}
