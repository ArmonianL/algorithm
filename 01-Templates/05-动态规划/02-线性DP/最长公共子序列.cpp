char a[N],b[N];
int f[N][N];//f[i][j]：第一个序列前i个字母，第二个序列前j个字母中出现的所有子序列的最大值

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int j=1;j<=m;j++) cin >> b[j];

    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=m;j++)
        {
            
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    }
    cout << f[n][m];

    return 0;
}