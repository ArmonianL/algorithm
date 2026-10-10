#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =200010;
const ll MOD=998244353;
ll n,k;
ll a[N];
ll fac[N];
ll ifac[N];

ll qpow(ll a, ll b)
{
    ll res = 1;

    while (b)
    {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

void init()//预处理
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
    {
        fac[i]=(fac[i-1]*i)%MOD;
    }

    ifac[n]=qpow(fac[n],MOD-2);
    for(int i=n;i>=1;i--)
    {
        ifac[i-1]=(ifac[i]*i)%MOD;
    }


}

ll C(ll n,ll k)
{
    if(n<0 || k<0 || k>n) return 0;
    return fac[n]*ifac[n-k]%MOD*ifac[k]%MOD;
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];

    init();
    ll s1=0,s2=0;

    for(int i=1;i<=n;i++)
    {
        ll x=a[i]%MOD;
        s1=(s1+x*x%MOD)%MOD;
        s2=(s2+x)%MOD;
    }


    ll ans=(C(n-1,k-1)*s1)%MOD+(C(n-2,k-2)*(s2*s2%MOD-s1+MOD))%MOD;
    cout << ans%MOD;
    



    return 0;
}