#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,vector<string> >graph;
map<string,string>parent;
string x,y,u,v;
ll N,len;

void BFS()
{
    queue<string>Q;
    parent[x] = x;
    Q.push(x);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        len = graph[u].size();
        for (ll i=0;i<len;i++)
        {
            v = graph[u][i];
            if (parent[v]=="")
            {
                ///visited[v] = true;
                parent[v] = u;
                if (v==y) return;
                Q.push(v);
            }
        }
    }
}

int main ()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll caseno = 0;
    while(scanf("%lld",&N)==1)
    {
        if (caseno>0)
            printf("\n");
        caseno++;
        graph.clear();
        parent.clear();
        for (ll i=0;i<N;i++)
        {
            cin>>x>>y;
            ///scanf("%s %s",&x,&y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        cin>>x>>y;
        ///scanf("%s %s",&x,&y);
        BFS();
        if (parent[y]=="")
            printf("No route\n");
        else
        {
            vector<string>route;
            u = y;
            while(u!=x)
            {
                v = parent[u];
                route.push_back(u);
                route.push_back(v);
                u = v;
            }
            len = route.size();
            for (ll i=len-1;i>=0;i-=2)
            {
                u = route[i];
                v = route[i-1];
                printf("%s %s\n",u.c_str(),v.c_str());
            }
        }
    }
    return 0;
}
