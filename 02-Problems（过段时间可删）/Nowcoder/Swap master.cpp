#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 500005;
const ll INF = 4e18;

ll a[N], f[N];
int p, q, k[10];
ll bestleft;
ll ans;
ll s;
int n;

// 5种斜率情况对应
// 斜率   
// -2      a[i-1]+a[i+1]
// 0       abs(a[i+1]-a[i-1])
// 2       -a[i-1]-a[i+1]
// -1      a[i+1]
// 1       -a[i-1]

ll c(int i,int p)
{
    if(i==1) 
    {
        if(p==1) return -a[i+1];
        if(p==-1) return a[i+1];
    }
    else if(i==n) 
    {
        if(p==1) return -a[i-1];
        if(p==-1) return a[i-1];
    }
    else 
    {
        if(p==-2) return a[i-1]+a[i+1];
        if(p==0) return abs(a[i+1]-a[i-1]);
        if(p==2) return -a[i-1]-a[i+1];
    }

    return -INF;
}

ll R(int j)
{
    return p*a[j]+c(j,q)-f[j];
}

ll L(int i)
{
    return q*a[i]+c(i,p)-f[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    k[1]=-2;
    k[2]=0;
    k[3]=2;
    k[4]=-1;
    k[5]=1;

    while(t--)
    {
        s=0;
        ans=0;
        bestleft=-INF;

        cin >> n;

        for(int i=1;i<=n;i++)
            cin >> a[i];

        if(n==2)
        {
            cout << abs(a[2]-a[1]) << '\n';
            continue;
        }

        for(int i=1;i<=n-1;i++)
            s+=abs(a[i+1]-a[i]);

        ans=s;

        for(int i=2;i<=n-1;i++)
        {
            f[i]=max({
                -2*a[i]+a[i-1]+a[i+1],
                abs(a[i+1]-a[i-1]),
                2*a[i]-a[i-1]-a[i+1]
            });
        }

        f[1]=abs(a[1]-a[2]);
        f[n]=abs(a[n]-a[n-1]);


        //处理2-n-1的不相邻的交换

        for(int _i=1;_i<=5;_i++)
        {
            p=k[_i];//这里千万不能写到for里面，int _i=1,p=k[_i];相当于是局部变量p

            for(int _j=1;_j<=5;_j++)
            {
                q=k[_j];//与p同理

                bestleft=-INF;

                for(int j=3;j<=n;j++)
                {
                    int i=j-2;

                    bestleft=max(bestleft,L(i));

                    ans=max(ans,s+bestleft+R(j));
                }
            }
        }


        //处理相邻的情况

        for(int i=1;i<=n-1;i++)
        {
            if(i==1)
            {
                ans=max(
                    ans,
                    s+abs(a[3]-a[1])-abs(a[3]-a[2])
                );
            }
            else if(i==n-1)
            {
                ans=max(
                    ans,
                    s+abs(a[n]-a[n-2])-abs(a[n-1]-a[n-2])
                );
            }
            else
            {
                ans=max(
                    ans,
                    s
                    -abs(a[i]-a[i-1])
                    -abs(a[i+2]-a[i+1])
                    +abs(a[i+1]-a[i-1])
                    +abs(a[i+2]-a[i])
                );
            }
        }

        cout << ans << '\n';
    }

    return 0;
}