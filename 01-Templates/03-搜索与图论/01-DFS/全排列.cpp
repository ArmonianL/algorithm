#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =10;
int n;
int a[N];
bool vis[N];

void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++)
        cout << a[i] << ' ';
        cout << '\n';
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            a[u]=i;
            vis[i]=true;
            dfs(u+1);
            a[u]=0;
            vis[i]=false;
        }
    }
   
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    dfs(0);
    

    return 0;
}