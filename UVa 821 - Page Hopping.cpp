#include<bits/stdc++.h>
#define ll long long
#define MAX 999999999999
using namespace std;
ll graph[105][105],x,y,V,total,com,MX;
double ans;

void sett()
{
    for (ll i=1;i<=101;i++)
        for (ll j=1;j<=101;j++)
            graph[i][j] = MAX;
}

int main ()
{
    ll caseno = 0;
    while(scanf("%lld%lld",&x,&y) && x && y)
    {
        sett();
        set<ll>nodes;
        map<ll,bool>track;
        MX = 0;
        nodes.insert(x),nodes.insert(y);
        track[x] = track[y] = true;
        MX = max(x,y);
        graph[x][y] = 1;
        while(scanf("%lld%lld",&x,&y) && x && y)
            graph[x][y] = 1,nodes.insert(x),nodes.insert(y),track[x] = track[y] = true,MX = max(MX,max(x,y));
        for (ll k=1;k<=MX;k++)
            for (ll i=1;i<=MX;i++)
                for (ll j=1;j<=MX;j++)
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
        V = nodes.size();
        ///cout<<V<<endl;
        com = V*(V-1);
        total = 0;
        for (ll i=1;i<=MX;i++)
            for (ll j=1;j<=MX;j++)
                if (graph[i][j]!=MAX && i!=j && track[i] && track[j])
                    total+=graph[i][j];
        ///cout<<total<<endl;
        ans = (total*1.00)/com;
        printf("Case %lld: average length between pages = %0.3lf clicks\n",++caseno,ans);
    }
    return 0;
}
