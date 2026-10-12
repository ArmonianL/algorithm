#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =300010;
const int INF=0x3f3f3f3f;
int n,q;
int l[N],r[N],prel[N],prer[N];
priority_queue<int,vector<int>,greater<int>> heap1,heap2;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;

    for(int i=2;i<=n;i++) cin >> l[i];
    prer[n]=INF;
    for(int i=n;i>=2;i--)
    {
        heap2.push(l[i]);
        prer[i-1]=heap2.top();
    }

    prel[1]=INF;
    for(int i=1;i<=n-1;i++)
    {
        cin >> r[i];
        heap1.push(r[i]);
        prel[i+1]=heap1.top();
    }

    while(q--)
    {
        int s,t;cin >> s >> t;
        if(s<t) cout << min(r[s],l[s]+prel[s]) << '\n';
        else cout << min(l[s],r[s]+prer[s]) << '\n';
    }

    return 0;
}