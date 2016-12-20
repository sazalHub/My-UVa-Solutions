#include<bits/stdc++.h>
using namespace std;
#define Max 2147483647
int main ()
{
    long b[10],i,c,m[10];
    char s[10][5]={"BCG","BGC","CBG","CGB","GBC","GCB"},s1[5];
    while(cin>>b[0]&&b[0]!=EOF)
    {
        for (i=1;i<9;i++)
            cin>>b[i];
        m[0]=b[1]+b[2]+b[3]+b[4]+b[6]+b[8];

        m[1]=b[1]+b[2]+b[3]+b[5]+b[6]+b[7];

        m[2]=b[8]+b[5]+b[0]+b[6]+b[1]+b[4];

        m[3]=b[8]+b[5]+b[1]+b[7]+b[0]+b[3];

        m[4]=b[4]+b[7]+b[0]+b[6]+b[2]+b[5];

        m[5]=b[4]+b[7]+b[2]+b[8]+b[0]+b[3];

        c=Max;
        for (i=0;i<6;i++)
        {
            if (m[i]<c)
            {
                c=m[i];
                strcpy(s1,s[i]);
            }
        }
        cout<<s1<<' '<<c<<endl;
    }
    return 0;
}
