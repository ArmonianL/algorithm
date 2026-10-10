int v[N],w[N];
int dp[N][N];

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i] >> w[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k*v[i]<=j;k++)//选0个，1个，2个.......
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout << dp[n][m];
    
    return 0;
}