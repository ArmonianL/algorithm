#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =100010;
int n,k;
int ans;
int p[N],d[N];//d[i]表示i和父亲的相对关系。0：同类，1：吃，2：被吃

int find(int x)//返回根节点并更新关系
{
    if(p[x]!=x) 
    {
        int father=p[x];
        p[x]=find(p[x]);
        d[x]=(d[x]+d[father])%3;
    }
    return p[x];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    //初始化并查集！！！！！！！！
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        d[i]=0;
    }

    while(k--)
    {
        int t;cin >> t;
        if(t==1)
        {
            int a,b;cin >> a >> b;
            if(a>n || b>n) 
            {
                ans++;
                continue;
            }

            if(find(a)!=find(b)) 
            {
                //这里一定要先提前保存，因为后面会修改
                int fa=find(a);
                int fb=find(b);
                p[fa]=fb;
                d[fa]=(3-d[a]+0+d[b])%3;
            }
            else 
            {
                if((d[a]+3-d[b])%3!=0) 
                ans++;
                continue; 
            }
        }
        else if(t==2)
        {
            int a,b;cin >> a >> b;
            if(a>n || b>n) 
            {
                ans++;
                continue;
            }
            
            if(find(a)==find(b))
            {
                if((d[a]+3-d[b])%3!=1)
                {
                    ans++;
                    continue;
                }
            }
            else 
            {
                //这里一定要先提前保存，因为后面会修改
                int fa=find(a);
                int fb=find(b);
                p[fa]=fb;
                d[fa]=(3-d[a]+1+d[b])%3;
            }
        }

    }
    cout << ans;

    return 0;
}