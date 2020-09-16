/*Parker Barton, program that checks for all thetriple keystrokes(three consecutive identical characters)in a line of input. */

#include <stdio.h>
#include <stdlib.h>

/*Gets input from user and stores it in a string.*/
int read_line(char *str, int n)
{int ch, i = 0;
while ((ch = getchar()) != '\n'){
	if (i < n){
          *str++= ch;
          i++;
                 }
                 }
*str = '\0';   
return i;        
}
/*Searches the string*/
int search_keystrokes(char *s1, char *s2){
int count= 0;
while ((*s1) != '\0')
{
if(*s1 == *(s1 + 1) && *s1 == *(s1 + 2)){
*s2 = *s1;
s2++;
count +=1;
}
s1++;

}
*s2 = '\0';
if (count >= 1){
return 1;}
else{
return 0;}
}


int main(void)
{

char triple[1000]; 
char word[1000];
printf("Input: ");
read_line(word, 1000);
int flag = search_keystrokes(word, triple);
if (flag == 1){
printf("error: Found three consecutive identical characters: %s ", triple);}
else
{
printf("no triple keystrokes");
}

return 0;
}
