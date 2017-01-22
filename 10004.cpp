#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,vector<ll> >graph;
bool vis[205];
ll level[205],color[205],V,E,x,y;

bool BFS()
{
    ll u,v,len;
    queue<ll>Q;
    Q.push(0);
    level[0] = 0;
    color[0] = 1;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        len = graph[u].size();
        for (ll i=0;i<len;i++)
        {
            v = graph[u][i];
            if (!vis[v])
            {
                vis[v] = true;
                level[v] = level[u] + 1;
                color[v] = !color[u];
                Q.push(v);
            }
            else if (color[v]==color[u])
                return false;
        }
    }
    return true;
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    while(scanf("%lld",&V)==1 && V!=0)
    {
        scanf("%lld",&E);
        graph.clear();
        memset(vis,false,sizeof(vis));
        memset(level,0,sizeof(level));
        memset(color,-1,sizeof(color));
        for (int i=0;i<E;i++)
        {
            scanf("%lld%lld",&x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        bool flag = BFS();
        if (flag)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
