#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int error[100][100],i,sum,j,row,col,sum_r[100],sum_c[100],c;
    int test,error_c;

    while(cin>>test && test!=0)
    {
        for (row=0;row<test;row++)
        {
            for (col=0;col<test;col++)
            {
                cin>>error[row][col];
            }
        }

        i=0;
        for (row=0;row<test;row++)
        {
            sum=0;
            for (col=0;col<test;col++)
            {
                sum+=error[row][col];
            }
            sum_r[i]=sum;
            i++;
        }

        i=0;
        for (col=0;col<test;col++)
        {
            sum=0;
            for (row=0;row<test;row++)
            {
                sum+=error[row][col];
            }
            sum_c[i]=sum;
            i++;
        }

        c=0;
        j=0;
        error_c=0;
        for (i=0;i<test;i++)
        {
            if (sum_r[i]%2==0)
                c++;
            else
            {
                row=i+1;
                error_c++;
            }
            if (error_c>1)
                break;
        }

        error_c=0;
        for (i=0;i<test;i++)
        {
            if (sum_c[i]%2==0)
                c++;
            else
            {
                col=i+1;
                error_c++;
            }
            if (error_c>1)
                break;
        }
        if (c==2*test)
            cout<<"OK"<<endl;
        else if (error_c>1)
            cout<<"Corrupt"<<endl;
        else
            cout<<"Change bit "<<'('<<row<<','<<col<<')'<<endl;
    }
    return 0;
}
