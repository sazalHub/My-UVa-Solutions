#include<bits/stdc++.h>
#define ll int
using namespace std;
ll level[1001][1001];
bool visited[1001][1001];
ll R,C,dr,dc,lr,lc,tx,ty;
ll fx[4] = {-1,0,0,1};
ll fy[4] = {0,-1,1,0};

void BFS()
{
    ll i;
    queue<ll>Q;
    Q.push(lc),Q.push(lr);
    visited[lr][lc] = true;
    level[lr][lc] = 0;
    bool flag = true;

    while(!Q.empty()&&flag)
    {
        ll c = Q.front();
        Q.pop();
        ll r = Q.front();
        Q.pop();
        for (i=0;i<4;i++)
        {
            tx = r + fx[i];
            ty = c + fy[i];
            ///cout<<tx<<" "<<ty<<endl;
            if ((tx>=0 && tx<R)&&(ty>=0 && ty<C)&&!visited[tx][ty])
            {
                ///cout<<tx<<" "<<ty<<endl;
                visited[tx][ty]=true;
                level[tx][ty] = level[r][c] + 1;
                if (tx==dr&&ty==dc)
                {
                    printf("%d\n",level[dr][dc]);
                    flag = false;
                    break;
                }
                Q.push(ty),Q.push(tx);
            }
        }
    }
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll B,col,N,row,i,j;
    while(scanf("%d%d",&R,&C)==2 && R && C)
    {
        memset(visited,false,sizeof(visited));
        scanf("%d",&B);
        for (i=0;i<B;i++)
        {
            scanf("%d%d",&row,&N);
            for (j=0;j<N;j++)
            {
                scanf("%d",&col);
                visited[row][col] = true;
            }
        }
        scanf("%d%d",&lr,&lc);
        scanf("%d%d",&dr,&dc);
        BFS();
        ///printf("%d\n",level[dr][dc]);
    }
    return 0;
}
