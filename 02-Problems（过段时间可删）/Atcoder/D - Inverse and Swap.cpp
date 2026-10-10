#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =500010;
int n,q;
int a[N],b[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    cin >> a[i];

    for(int i=1;i<=n;i++)
    b[a[i]]=i;

    bool isa=true;
    while(q--)
    {
        int t;cin >> t;
        if(t==1)
        {
            int x,y;cin >> x >> y;
           if(isa)
           {
            swap(a[x],a[y]);
            swap(b[a[x]],b[a[y]]);
           }
           else 
           {
            swap(b[x],b[y]);
            swap(a[b[x]],a[b[y]]);
           }
        }
        else 
        {
            isa=!isa;
        }
    }

    if(isa)
    {
        for(int i=1;i<=n;i++)
        cout << a[i] << ' ';
    }
    else 
    {
        for(int i=1;i<=n;i++)
        cout << b[i] << ' ';
    }

    return 0;
}