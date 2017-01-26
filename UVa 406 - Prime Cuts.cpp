#include<bits/stdc++.h>
using namespace std;
#define Max 1005
bool prime[Max];
void seive()
{
    int i,j;
    prime[0]=1;
    for (i=4;i<=Max;i+=2)
        prime[i]=1;
    for (i=3;i<=sqrt(Max);i+=2)
    {
        for (j=i*i;j<Max;j+=2*i)
        {
            prime[j]=1;
        }
    }
}
int main ()
{
    int N,C,p[Max],i,c,j,temp,rc;
    seive();
    while(cin>>N>>C)
    {
        c=0;
        j=0;
        for (i=1;i<=N;i++)
        {
            if (prime[i]==0)
            {
                p[j++]=i;
                c++;
            }
        }
        cout<<N<<' '<<C<<':';
        if (c%2==0)
        {
            rc=C*2;
            if (rc>=c)
            {
                for (i=0;i<c;i++)
                {
                    cout<<' '<<p[i];
                }
            }
            else
            {
                temp=c/2-C;
                while(rc--)
                    cout<<' '<<p[temp++];
            }
        }
        else
        {
            rc=(C*2)-1;
            if (rc>=c)
            {
                for (i=0;i<c;i++)
                {
                    cout<<' '<<p[i];
                }
            }
            else
            {
                temp=(c/2+1)-C;
                while(rc--)
                {
                    cout<<' '<<p[temp++];
                }
            }
        }
        cout<<endl<<endl;
    }
    return 0;
}

