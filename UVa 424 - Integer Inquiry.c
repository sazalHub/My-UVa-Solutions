#include<stdio.h>
#include<string.h>
int main ()
{
    char s[105][150],str[150];
    long long int sum,i,j,c,b,l,t;
    while(1)
    {
        c=0;b=0;
        for (i=0;;i++)
        {
            scanf("%s",&s[i]);
            if (s[i][0]=='0'&&s[i][1]=='\0')
                {
                    b=1;break;
                }
                c++;
        }
        l=strlen(s[0]);
        if (l==1)
        {
            sum=0;
            for (i=0;i<c;i++)
            {
                sum=sum+s[i]-48;
            }
            printf("%lld\n",sum);
        }
        else
        {
            sum=0;
        for (j=l-1;j>=0;j--)
        {
            for (i=0;i<c;i++)
            {
                sum=sum+s[i][j]-48;
            }
            if (sum>9)
            {
                t=sum%10;
                sum=sum/10;
            }
            else
            {
                t=sum;
                sum=0;
            }
            str[j]=t+48;
        }
        str[l]='\0';
        printf("%s\n",str);
        }
        if (b==1)
            break;
    }
    return 0;
}
