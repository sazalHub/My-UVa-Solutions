#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll byte,N,num,total_sec,rem,caseno=0;
    double rate;
    while(scanf("%lld",&byte)==1)
    {
        if (byte==0)
            break;
        ll sum = 0,tsum = 0,temp = byte;
        total_sec = 0;
        printf("Output for data set %lld, %lld bytes:\n",++caseno,byte);
        for (total_sec = 1;;total_sec++)
        {
            scanf("%lld",&N);
            sum+=N;
            tsum+=N;
            if (total_sec%5==0)
            {
                ///cout<<sum<<endl;
                if (sum==0)
                {
                    printf("   Time remaining: stalled\n");
                    continue;
                }
                temp = temp - sum;
                rate = (temp*5.0)/sum;
                rem = (ll)rate;
                if (rate>(ll)rate)
                    rem = ((ll)rate+1);
                printf("   Time remaining: %lld seconds\n",rem);
                sum = 0;
            }
            if (tsum==byte)
                break;
        }

        printf("Total time: %lld seconds\n",total_sec);
        printf("\n");
    }
    return 0;
}
