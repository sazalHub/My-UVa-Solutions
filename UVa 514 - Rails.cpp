#include<bits/stdc++.h>
using namespace std;
int main ()
{
    stack<int>rail;
    int N,i,temp,a[1005],t,b;
    while(cin>>N && N)
    {
        while(cin>>temp && temp)
        {
            b=1;
            a[0]=temp;
            for (i=1;i<N;i++)
                cin>>a[i];
            t=1;
            for (i=0;i<N && t<=N;)
            {
                while(t<=a[i])
                {
                    rail.push(t);
                    t++;
                }
                while(!rail.empty()&&rail.top()==a[i])
                {
                    rail.pop();
                    i++;
                }
                if (!rail.empty()&&rail.top()>a[i])
                {
                    b=0;
                    break;
                }
            }
            if (!rail.empty())
            {
                while(rail.top()==a[i])
                {
                    rail.pop();
                    i++;
                }
            }
            if (b==0||!rail.empty())
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
            while(!rail.empty())
                rail.pop();
        }
        cout<<endl;
    }
    return 0;
}
