#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =1005;
int n;
ll c;
ll a[N],s[N];
ll res;
void dfs(int u,ll sum)
{
    if(u==0)
    {
        res=max(res,sum);
        return ;
    }
    if(s[u]+sum<=c) 
    {
        res=max(res,s[u]+sum);
        return ;
    }

    if(sum+a[u]>c) dfs(u-1,sum);
    else 
    {
        dfs(u-1,sum);
        dfs(u-1,sum+a[u]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> c;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];

    dfs(n,0);
    cout << res;




    return 0;
}