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
            dp[i][j]=dp[i-1][j];
            if(j>=v[i]) dp[i][j]=max(dp[i][j],dp[i][j-v[i]]+w[i]);//1.不选2.至少选一个
        }
    }
    cout << dp[n][m];

    return 0;
}