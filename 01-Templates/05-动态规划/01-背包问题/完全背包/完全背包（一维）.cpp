int v[N],w[N];
int dp[N];

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i] >> w[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=v[i];j<=m;j++) 
        {
            dp[j]=max(dp[j],dp[j-v[i]]+w[i]);//1.不选2.至少选一个
        }
    }
    cout << dp[m];

    return 0;
}