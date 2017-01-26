#include<stdio.h>
#include<string.h>
int main ()
{
    char s[1005],str[1005];
    long int i,j,k,n,l;
    while(gets(s))
    {
        l=strlen(s);
        for (i=0;i<l;i++)
        {
            str[i]=s[i]-7;
        }
        str[i]='\0';
        printf("%s\n",str);
    }
    return 0;
}
