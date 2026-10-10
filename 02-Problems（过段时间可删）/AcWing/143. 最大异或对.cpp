#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =100010;
int n;
int ans;
int son[N*32][2],idx;

void insert(ll x)
{
    int p=0;
    for(int i=31;i>=0;i--)
    {
        int u=x >> i & 1;
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
}

int query(int x)//返回已存在的和x异或最大的结果
{
    int p=0;
    int res=0;
    for(int i=31;i>=0;i--)
    {
        int u=x >> i & 1;
        if(son[p][u^1]) 
        {
            p=son[p][u^1];
            res+=1 << i;//一定不是 res+=pow(2,i)*(son[p][u^1] ^ u);因为son[p][u^1]存的是idx！！
        } 
        else 
        {
            p=son[p][u];
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        ll x;cin >> x;
        ans=max(ans,query(x));
        insert(x);
    }
    
    cout << ans;


    return 0;
}