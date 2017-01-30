#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    char str[100];
    ll h = 0,m = 0,s=0,ns = -1,prens=0,pret = 0;
    double dis = 0.0;
    while(gets(str))
    {
        h = 0,m = 0,s = 0;
        ll i = 0;
        while(str[i]!=':')
            h = h*10 + (str[i]-48),i++;
        i++;

        while(str[i]!=':')
            m = m*10 + (str[i]-48),i++;
        i++;

        while(str[i]!='\0'&&str[i]!=' ')
            s = s*10 + (str[i]-48),i++;

        ll time = h*3600 + m*60 + s;
        ///cout<<time<<" ";
        double speed = (prens*1000.0)/3600.00;
        ///cout<<speed<<" "<<dis<<" ";
        dis = dis + (speed*(time-pret))/1000;
        ///cout<<dis<<endl;
        if (i<strlen(str))
        {
            prens = 0;
            while(str[i])
            {
                if(str[i]==' ')
                {
                    i++;
                    continue;
                }
                ///cout<<str[i]<<endl;
                ///cout<<prens<<endl;
                prens = prens*10 + (str[i]-48);
                i++;
                ///cout<<prens<<endl;
            }
        }
        else
        {
            for (ll i=0;str[i];i++)
                printf("%c",str[i]);
            printf(" %0.2lf km\n",dis);
        }
        pret = h*3600 + m*60 + s;
    }
    return 0;
}
