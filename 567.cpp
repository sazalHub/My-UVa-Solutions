#include<bits/stdc++.h>
#define ll int
using namespace std;
map<ll,vector<ll> >graph;
bool vis[25];
ll level[25],X,num;

void BFS(ll st,ll nd)
{
    queue<ll>Q;
    Q.push(st);
    level[st]=0;
    vis[st]=true;
    while(!Q.empty())
    {
        ll node = Q.front();
        Q.pop();
        ll len = graph[node].size();
        for (ll i=0;i<len;i++)
        {
            ll v = graph[node][i];
            if (!vis[v])
            {
                vis[v] = true;
                level[v] = level[node] + 1;
                if (v==nd)
                    return;
                Q.push(v);
            }
        }
    }
}

int main ()
{
    ll caseno=0,N,x,y;
    ///freopen("in.txt","r",stdin);
    while(scanf("%d",&X)==1)
    {
        graph.clear();
        for (ll i=1;i<=19;i++)
        {
            if (i>1)
                scanf("%d",&X);
            for (ll j=0;j<X;j++)
            {
                scanf("%d",&num);
                graph[i].push_back(num);
                graph[num].push_back(i);
            }
        }
        scanf("%d",&N);
        printf("Test Set #%d\n",++caseno);
        for (ll i=0;i<N;i++)
        {
            scanf("%d%d",&x,&y);
            memset(level,0,sizeof(level));
            memset(vis,false,sizeof(vis));
            BFS(x,y);
            ll ans = level[y];
            printf("%2d to %2d: %d\n",x,y,ans);
        }
        printf("\n");
    }
    return 0;
}
