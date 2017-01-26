#include<stdio.h>
#include<math.h>
double fact(double i);
int main ()
{
    double m,n,c;
    while (scanf("%lf%lf",&n,&m)==2&&n!=0&&m!=0)
    {
        c=fact(n)/(fact(n-m)*fact(m));
        printf("%0.0f things taken %0.0f at a time is %0.0f exactly.\n",n,m,c);
    }
    return 0;
}
double fact(double  i)
{
    double sum=1,j;
    for (j=2;j<=i;j++)
        sum=sum*j;
    return sum;
}
