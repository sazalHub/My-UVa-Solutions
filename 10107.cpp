#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    ll arr[10005],N,mid;
    arr[0] = -99999999999;
    ll i,cnt = 0;
    while (scanf("%lld",&N)==1)
    {
        i = cnt;
        while(i>=1 && N<arr[i-1])
        {
            arr[i] = arr[i-1];
            i--;
        }
        arr[i] = N;
        cnt++;

        mid = cnt/2;
        if (cnt%2==0)
            printf("%lld\n",(arr[mid]+arr[mid-1])/2);
        else
            printf("%lld\n",arr[mid]);
    }
    return 0;

}

