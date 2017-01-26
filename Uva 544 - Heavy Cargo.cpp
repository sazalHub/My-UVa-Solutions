#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    string from,to;
    ll weight;
}edges[20000];
ll N,E;
string x,y;
map<string,string>parent;

string find_root(string r)
{
    if (parent[r]=="")
        return r;
    return parent[r] = find_root(parent[r]);
}

bool cmp(node a,node b)
{
    return (a.weight>b.weight);
}

ll KRUSKAL()
{
    sort(edges,edges+E,cmp);
    ll ans = 9999999999;
    for (ll i=0;i<E;i++)
    {
        string u = find_root(edges[i].from);
        string v = find_root(edges[i].to);
        if (u!=v)
        {
            parent[u] = v;
            if (ans>edges[i].weight)
                ans = edges[i].weight;
        }
        if (find_root(x)==find_root(y))
        {
            return ans;
        }
    }
    return ans;
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll caseno = 0;
    while(scanf("%lld%lld",&N,&E)==2 && (N+E)!=0)
    {
        parent.clear();
        for (ll i=0;i<E;i++)
            cin>>edges[i].from>>edges[i].to>>edges[i].weight;
        cin>>x>>y;
        ///cout<<x<<" "<<y<<endl;
        printf("Scenario #%lld\n%lld tons\n\n",++caseno,KRUSKAL());
    }
    return 0;
}
