#include<stdio.h>
#include<string.h>
#define max 100000
int main ()
{
    char s[max];
    int i,c,b;
    while (gets(s))
    {
        c=0;
        b=0;
        for (i=0;;i++)
        {
            while((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
            {
                i++;
                b=1;
            }
            if (b==1)
            {
                c++;
                b=0;
            }
            if (s[i]=='\0')
                {
                    break;
                }
        }
        printf("%d\n",c);
    }
    return 0;
}
