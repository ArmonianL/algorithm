#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =100005;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;cin >> n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin >> x;
        if(i&1) ans+=x;
    }
    cout << ans;


    return 0;
}