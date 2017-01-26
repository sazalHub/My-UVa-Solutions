#include<bits/stdc++.h>
using namespace std;
int dev (int p)
{
    int j,q,c=0;
    q=sqrt(p);
    for (j=1;j<=q;j++)
    {
        if (p%j==0)
            {
                c+=2;
                if (j*j==p)
                   c--;
            }
    }
    return c;
}

int main ()
{
    int T,t,i,l,u,m,num,temp,n;
    cin>>T;
    for (t=0;t<T;t++)
    {
        temp=0;
        cin>>l>>u;
        for (i=l;i<=u;i++)
        {
            m=dev(i);
            if (temp<m)
            {
                temp=m;
                num=i;
            }
        }
        cout<<"Between "<<l<<" and "<<u<<','<<' '<<num<<' '<<"has a maximum of "<<temp<<" divisors."<<endl;
    }
    return 0;
}
