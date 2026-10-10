#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =5004;
int n,m;
int b[N][N],s[N][N];

void insert(int x1,int y1,int x2,int y2,int c)
{
    b[x1][y1]+=c;
    b[x1][y2+1]-=c;
    b[x2+1][y1]-=c;
    b[x2+1][y2+1]+=c;
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    while(n--)
    {
        int x1,y1,c;cin >> x1 >> y1 >> c;
        x1++;
        y1++;
        insert(x1,y1,x1,y1,c);
    }

    for(int i=1;i<=5002;i++)
    for(int j=1;j<=5002;j++)
    b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];

    for(int i=1;i<=5002;i++)
    for(int j=1;j<=5002;j++)
    s[i][j]=b[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];

    int ans=0;
    for(int i=1;i<=5002;i++)
    for(int j=1;j<=5002;j++)
    {
        int x2=i+m-1;
        int y2=j+m-1;
        if(x2<=5002&&y2<=5002)
        {
            ans=max(ans,s[x2][y2]-s[x2][j-1]-s[i-1][y2]+s[i-1][j-1]);
        }
    }
    cout << ans;


    return 0;
}