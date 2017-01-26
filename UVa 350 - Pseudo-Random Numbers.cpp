#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int Z,I,L,M,t,c,k=1;
    while(cin>>Z>>I>>M>>L)
    {
        if (Z==0 && I==0 && M==0 && L==0)
            break;
        c=1;
        L=(Z*L+I)%M;
        t=L;
        while(1)
        {
            t=(Z*t+I)%M;
            if (t==L)
                break;
            c++;
        }
        cout<<"Case "<<k<<": "<<c<<endl;
        k++;
    }
    return 0;
}
