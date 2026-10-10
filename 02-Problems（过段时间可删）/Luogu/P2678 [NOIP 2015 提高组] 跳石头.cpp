#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =1e6+4;
int L,n,m;
int a[N];
bool check(int x)//方案可行,是左性质
{
    int last=0;//最后一个保留的石头离起点的距离
    int cnt=0;//移走的石头数量
    for(int i=1;i<=n;i++)
    {
        if(a[i]-last<x)
        {
            cnt++;
        }
        else
        {
            last=a[i];
        }
    }
    if(L-last<x) cnt++;
    if(cnt>m) return false;
    else return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> L >> n >> m;
    for(int i=1;i<=n;i++)
    cin >> a[i];
    int l=0,r=L;
    while(l<r)
    {
        int mid=(l+r+1) >> 1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout << r;


    return 0;
}