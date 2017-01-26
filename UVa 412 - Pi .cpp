#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if (b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main ()
{
    int N,i,data[55],c,j,p;
    double pi;
    while(cin>>N && N)
    {
        for (i=0;i<N;i++)
        {
            cin>>data[i];
        }
        c=0;
        p=0;
        for (i=0;i<N;i++)
        {
            for (j=i+1;j<N;j++)
            {
                if (gcd(data[i],data[j])==1)
                    c++;
                p++;
            }
        }

        if (c==0)
            cout<<"No estimate for this data set."<<endl;
        else
        {
            pi=(6*double(p))/double(c);
            pi=sqrt(pi);
            cout<<fixed<<setprecision(6)<<pi<<endl;
        }
    }
    return 0;
}
