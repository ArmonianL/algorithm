#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =500010;
int n,q;
int a[N];
vector<int> idx;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;

    int ans=0;
    while(q--)
    {
        int t;cin >> t;
        if(t==1)
        {
            int x;cin >> x;
            if(a[x]==0) idx.push_back(x);
            ans=ans^a[x]^(++a[x]);
        }
        else 
        {
            vector<int> next;
            for(int i:idx)
            {
                ans=ans^a[i]^(--a[i]);
                if(a[i]!=0) next.push_back(i);
            }
            idx.swap(next);
        }

         cout << ans << '\n';
    }

   
    return 0;
}
