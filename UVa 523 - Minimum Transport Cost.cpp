#include<bits/stdc++.h>
#define ll long long
#define MAX 999999999999999
using namespace std;

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,num,V,u,v;
    string xx;
    getline(cin,xx);
    stringstream xxx(xx);
    xxx>>cases;
    xxx.clear();
    ///cout<<cases<<endl;
    getline(cin,xx);
    while(cases--)
    {
        map<ll,map<ll,ll> >graph;
        V = 1;
        getline(cin,xx);
        ///cout<<xx<<endl;
        xxx.str(xx);
        while(xxx>>num)
        {
            if (num==-1)
                num = MAX;
            graph[1][V++] = num;
        }
        V--;
        ///cout<<V<<endl;
        for (ll i=2;i<=V;i++)
        {
            xxx.clear();
            getline(cin,xx);
            ///cout<<xx<<endl;
            xxx.str(xx);
            for (ll j=1;j<=V;j++)
            {
                xxx>>num;
                if (num==-1)
                    num = MAX;
                graph[i][j] = num;
                ///cout<<num<<" ";
            }
            ///cout<<endl;
        }

        ll taxes[V+5];
        xxx.clear();
        getline(cin,xx);
        ///cout<<xx<<endl;
        xxx.str(xx);
        for (ll i=1;i<=V;i++)
            xxx>>taxes[i];

        ll next[V+5][V+5];
        for (ll i=1;i<=V;i++)
            for (ll j=1;j<=V;j++)
                next[i][j] = j;

        for (ll k=1;k<=V;k++)
        {
            for (ll i=1;i<=V;i++)
            {
                if (graph[i][k]!=-1)
                {
                    for (ll j=1;j<=V;j++)
                    {
                        if (graph[k][j]!=-1)
                        {
                            if (graph[i][k] + graph[k][j] + taxes[k]<graph[i][j])
                            {
                                graph[i][j] = graph[i][k] + graph[k][j] + taxes[k];
                                next[i][j] = next[i][k];
                            }
                        }
                    }
                }
            }
        }

        xxx.clear();
        bool flag = false;
        ///getline(cin,xx);
        while(getline(cin,xx))
        {
            ///cout<<xx<<endl;
            if (xx.size()==0)
                break;
            if (flag)
                printf("\n");
            else
                flag = true;
            xxx.str(xx);
            xxx>>u>>v;
            xxx.clear();
            printf("From %lld to %lld :\n",u,v);
            printf("Path: %lld",u);
            ll from = u,to = v;
            while(from!=to)
            {
                from = next[from][to];
                printf("-->%lld",from);
            }
            ///sum-=taxes[u]+taxes[v];
            printf("\nTotal cost : %lld\n",graph[u][v]);
        }
        if (cases)
            printf("\n");
    }
    return 0;
}
