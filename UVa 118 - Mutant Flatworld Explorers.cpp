#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll X,Y,x,y;
char txt[105],str[3];
map<ll,map<ll,bool> >track;

bool check(ll a,ll b)
{
    if (a<0 || b<0 || a>X || b>Y) return true;
    return false;
}

void MOVE(ll &a,ll &b,char D)
{
    if (D=='N') b++;
    if (D=='S') b--;
    if (D=='E') a++;
    if (D=='W') a--;
}

void BACK(ll &a,ll &b,char D)
{
    if (D=='N') b--;
    if (D=='S') b++;
    if (D=='E') a--;
    if (D=='W') a++;
}

char DIR(char ch,char D)
{
    if (ch=='R')
    {
        if (D=='N') return 'E';
        if (D=='E') return 'S';
        if (D=='S') return 'W';
        if (D=='W') return 'N';
    }
    else
    {
        if (D=='N') return 'W';
        if (D=='E') return 'N';
        if (D=='S') return 'E';
        if (D=='W') return 'S';
    }
}

int main ()
{
    scanf("%lld%lld",&X,&Y);
    while(scanf("%lld%lld%s",&x,&y,&str)==3)
    {
        scanf("%s",&txt);
        ///cout<<str<<" "<<txt<<endl;
        char dir = str[0];
        bool flag = false;
        for (int i=0;txt[i];i++)
        {
            ///cout<<"Prev = "<<x<<" "<<y<<" "<<dir<<endl;
            if (txt[i]=='L'||txt[i]=='R')
                dir = DIR(txt[i],dir);
            else if (txt[i]=='F')
            {
                MOVE(x,y,dir);
                if (check(x,y))
                {
                    BACK(x,y,dir);
                    if (!track[x][y])
                    {
                        track[x][y] = flag = true;
                        break;
                    }
                }
            }
            ///cout<<"Then = "<<x<<" "<<y<<" "<<dir<<endl;
            ///cout<<endl;
        }
        printf("%lld %lld %c",x,y,dir);
        if (flag)
            printf(" LOST");
        printf("\n");
    }
    return 0;
}
