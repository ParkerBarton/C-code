/*Parker Barton, this program gets a message from a file, encodes it, then stores it in an output file.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 1000

void line_switch(char *s1, char *s2){
int i;
for(i=0; i<strlen(s1); i++){
int val = (int)s1[i];
if(val >= 65 && val <= 90){
 s2[i] = (char)( (25 - (val-65)) + 65 );}
else if(val >= 97 && val <= 122){
s2[i] = (char)( (25 - (val-97)) + 97 );}
else{
s2[i] = s1[i];}
}
s2[i] = '\0';
}


int  main(void)
{
char  str[100];
FILE* pFile;
FILE* pFile2;
char input[100]="";
char s2[100];
printf("Enter the file name: ");
scanf("%s",input);

pFile = fopen(input, "r");
if (pFile == NULL)
{printf("error opening file\n");
return 1;}

int n =18;
input[n+1] = '.';
input[n+2] = 's';
input[n+3] = 'w';
input[n+4] = 't';

pFile2 = fopen(input, "w");
if (pFile2 == NULL){
printf ("Error opening file\n");
return 1;}

while(!feof(pFile)){
fscanf(pFile,"%s", str);

line_switch(str, s2);

fprintf(pFile2, "%s ", s2);

}
fclose(pFile);
fclose(pFile2);

return 0;
}

