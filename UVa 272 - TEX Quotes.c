#include<stdio.h>
#include<string.h>
int main ()
{
    char str[254];
    int i,b=1,j;
    while(gets(str))
    {
        for (i=0;str[i]!=0;i++)
        {
            if (str[i]=='"'&&(b%2)==1)
            {
                printf("``");
                b++;
            }
             else if (str[i]=='"'&&(b%2)==0)
            {
                printf("''");
                b++;
            }
            else
                printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
