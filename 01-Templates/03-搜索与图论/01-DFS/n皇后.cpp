#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =10;
int n;
char g[N][N];
//同一条对角线上的点的坐标(x,y)，满足x+y和y-x相同，防止y-x是负数，所以统一加上n
bool col[N],dj[2*N],fdj[2*N];//对角线数组一定要开大一点
void dfs(int u)//u代表第几行
{
    if(u==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << g[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
        return ;
    }

    for(int i=0;i<n;i++)//遍历列
    {
        if(!col[i]&&!dj[i+u]&&!fdj[i-u+n])
        {
            g[u][i]='Q';
            col[i]=dj[i+u]=fdj[i-u+n]=true;
            dfs(u+1);
            g[u][i]='.';
            col[i]=dj[i+u]=fdj[i-u+n]=false;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]='.';

    dfs(0);


    return 0;
}