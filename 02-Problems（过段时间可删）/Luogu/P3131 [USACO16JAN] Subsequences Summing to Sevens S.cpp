#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =50002;
ll a[N],s[N],first[10];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;cin >> n;
    for(ll i=1;i<=n;i++)
    cin >> a[i];
    ll ans=0;
    memset(first,-1,sizeof(first));
    first[0]=0;
    for(ll i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        if(first[s[i]%7]!=-1)
        {
            ans=max(ans,i-(first[s[i]%7]+1)+1);
        }
        else 
        first[s[i]%7]=i;
    }
    cout << ans;
    


    return 0;
}