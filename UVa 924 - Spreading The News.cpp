#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool visited[2505];
ll level[2505],E,N,num,cases,u,v,len,MxLvl;
map<ll,vector<ll> >graph;
map<ll,ll>LvL;

void BFS(ll st)
{
    memset(visited,false,sizeof(visited));
    memset(level,0,sizeof(level));
    LvL.clear();
    queue<ll>Q;
    visited[st]=true,level[st]=0;
    Q.push(st);
    MxLvl = 0;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        MxLvl = max(MxLvl,level[u]);
        len = graph[u].size();
        for (ll i=0;i<len;i++)
        {
            v = graph[u][i];
            if (!visited[v])
            {
                visited[v]=true;
                level[v] = level[u] + 1;
                LvL[level[v]]++;
                Q.push(v);
            }
        }
    }
}

int main ()
{
    while(scanf("%lld",&E)==1)
    {
        for (ll i=0;i<E;i++)
        {
            scanf("%lld",&N);
            for (ll j=0;j<N;j++)
            {
                scanf("%lld",&num);
                graph[i].push_back(num);
            }
        }
        scanf("%lld",&cases);
        while(cases--)
        {
            scanf("%lld",&N);
            BFS(N);
            ll ans = 0,days = -1;
            for (ll i=0;i<=MxLvl;i++)
            {
                if (ans<LvL[i])
                {
                    ans = LvL[i];
                    days = i;
                }
            }
            if (days==-1) printf("0\n");
            else
                printf("%lld %lld\n",ans,days);
        }
    }
    return 0;
}
