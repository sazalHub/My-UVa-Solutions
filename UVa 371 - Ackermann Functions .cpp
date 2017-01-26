#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long a,b,n,m,c,i,M;
    while(cin>>a>>b)
    {
        if (a==0 && b==0)
            break;
        if (a>b)
        {
            n=b;
            b=a;
            a=n;
        }
        M=0;
        for (i=a;i<=b;i++)
        {
            m=i;
            c=0;
            while(m!=0)
            {
                if (m%2==0)
                    m=m/2;
                else
                    m=m*3+1;
                c++;
                if (m==1)
                    break;
            }
            if (M<c)
            {
                M=c;
                n=i;
            }
        }
        cout<<"Between "<<a<<" and "<<b<<", "<<n<<" generates the longest sequence of "<<M<<" values."<<endl;
    }
    return 0;
}
