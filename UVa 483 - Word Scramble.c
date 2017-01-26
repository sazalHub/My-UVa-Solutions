#include<stdio.h>
#include<string.h>
int main ()
{
    char str1[9999],str[1000],rev[9999];
    long int i,j,k,l;
    while(gets(str1))
        {
            i=0;
            while (str1[i]!='\0')
                {
                    j=0;
                    while(str1[i]!='\0'&&str1[i]!=' ')
                    {
                        rev[j]=str1[i];
                        i++;
                        j++;
                    }
                    rev[j]='\0';
                    l=strlen(rev);
                    j=0;
                    for (k=l-1;k>=0;k--)
                    {
                        str[j]=rev[k];
                        j++;
                    }
                    str[l]='\0';
                    printf("%s",str);
                    if (str1[i]==' ')
                        printf(" ");
                    if (str1[i]=='\0')
                        break;
                    else
                        i++;
                }
                printf("\n");
        }
    return 0;
}

