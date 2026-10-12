#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =25;
int n,m;
ll ans;
int v[N],w[N];



int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> w[i] >> v[i];

    for(int i=0;i<(1 << n);i++)
    {
        ll sumw=0,sumv=0;
        for(int k=0;k<n;k++)
        {
            if(i >> k & 1)
            {
                sumw+=w[k];
                sumv+=v[k];
            }
        }
        if(sumv<=m) ans=max(ans,sumw);
    }
    cout << ans;
    


    return 0;
}