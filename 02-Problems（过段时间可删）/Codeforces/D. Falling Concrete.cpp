//https://codeforces.com/problemset/problem/2266/D
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =200010;
int t,n;
int a[N];
vector<int> b;


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        int n;cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        b.clear();//不要漏！！
        for(int i=1;i<=n;i++) b.push_back(a[i]-i);

        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        n=b.size();
        int i=0,j=1;
        int res=0;
        while(j<n)
        {
            if(b[j]==b[j-1]+1) j++;
            else
            {
                res=max(res,j-i);
                i=j;
                j++;
            }
        }
        res=max(res,j-i);
        cout << res << '\n';

    }
    


    return 0;
}