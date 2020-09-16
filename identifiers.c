/*Parker Barton, program that checks if an input is a legal identifierin C */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        char c;
        int count = 0;
        
        char ch[50];
        printf("Input: ");
        c = getchar();
        int flag = 0, i = 0;
        while ((count < 50) && (c != '\n')) {
                ch[count] = c;
                count++;
                c = getchar();
 }/*the first if statement checks if the first letter is not a letter or '_'*/
        if ((ch[0]>='a'&&ch[0]<='z') || (ch[0]>='A'&&ch[0]<='Z') || (ch[0]=='_') ){
                        for(;i<=sizeof(ch);i++){
                                if (!((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] == '_') || (ch[i] >= '0' && ch[i] <= '9'))){
                                        flag++; }
                                
}}
        else{
                flag++;}




        if (flag!=0)
                printf("illegal identifier.");
        else
                printf("legal identifier.");



return 0;
}

