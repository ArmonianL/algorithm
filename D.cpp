#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =300010;
const int INF=0x3f3f3f3f;
int n,q;
int l[N],r[N],prel[N],prer[N];


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i=2;i<=n;i++) cin >> l[i];
    for(int i=1;i<=n-1;i++) cin >> r[i];

    prel[1]=INF,prer[n]=INF;
    for(int i=2;i<=n-1;i++) prel[i]=min(prel[i-1],r[i-1]);//左边最小的右代价
    for(int i=n-1;i>=2;i--) prer[i]=min(prer[i+1],l[i+1]);//右边最小的左代价

    while(q--)
    {
        int s,t;cin >> s >> t;
        if(s<t) cout << min(r[s],l[s]+prel[s]) << '\n';
        else cout << min(l[s],r[s]+prer[s]) << '\n';
    }

    return 0;
}