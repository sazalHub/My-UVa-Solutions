#include<stdio.h>
int main ()
{
    int n,i,j,T;
    int a [55],c,t;
    scanf("%d",&T);
    for (t=0;t<T;t++)
    {
        scanf("%d",&n);
        for ( i = 0; i < n; i++ )
            scanf ("%d", &a [i]);

            c=0;
        for ( i = 0; i < n; i++ ) {
            for ( j = i + 1; j < n; j++ )
                if ( a [i] > a [j] )
                    c++;
        }
        printf("Optimal train swapping takes %d swaps.\n",c);
    }
    return 0;
}

