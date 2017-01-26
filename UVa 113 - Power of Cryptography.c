#include<stdio.h>
int main ()
{
    double n,p;
    double k;
    while(scanf("%lf%lf",&n,&p)==2)
    {
        k=pow(p,1/n);
        printf("%.0f\n",k);
    }
    return 0;
}
