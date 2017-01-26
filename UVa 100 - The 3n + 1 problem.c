#include<stdio.h>
int main ()
{
    long int i,j,k,l,n,m,c,t,p,q;
    while(scanf("%ld%ld",&i,&j)==2)
    {
        p=i;q=j;
        if (p>q)
        {
            t=q;
            q=p;
            p=t;
        }
        m=0;
        for (k=p;k<=q;k++)
        {
            n=k;c=0;
            for(;;)
            {
                if(n==1)
                {
                    c++;break;
                }
                else if (n%2==0)
                {
                    n=n/2;
                    c++;
                }
                else if (n%2!=0)
                {
                    n=3*n+1;
                    c++;
                }
            }
            if (m<c)
                m=c;
        }
       printf("%ld %ld %ld\n",i,j,m);
    }
    return 0;
}
