const int N =505;
const int INF=0x3f3f3f3f;
int a[N][N],f[N][N];

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cin >> a[i][j];
    }
    //初始化
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i+1;j++)//注意j的范围
        {
            f[i][j]=-INF;
        }
    }   
    f[1][1]=a[1][1];

    for(int i=2;i<=n;i++)  
    {
        for(int j=1;j<=i;j++)
        {
            f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);
        }
    }

    int ans=-INF;
    for(int i=1;i<=n;i++) ans=max(ans,f[n][i]);

    cout << ans;

    return 0;
}
