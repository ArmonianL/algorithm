char a[N],b[N];//两个字符串
int f[N][N];//f[i][j]，操作a[1-i]使得a和b[1-j]相同的最小操作数

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    cin >> m;
    for(int i=1;i<=m;i++) cin >> b[i];
    //初始化边界
    f[0][0]=0;
    for(int i=1;i<=n;i++) f[i][0]=i;
    for(int i=1;i<=m;i++) f[0][i]=i;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //划分最后一次操作
            f[i][j]=min({f[i-1][j]+1,f[i][j-1]+1,f[i-1][j-1]+1});//{删，增，改}
            if(a[i]==b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);//{不操作}：不是每个i，j都有四种情况的，有些情况要加if
        }
    }
    cout << f[n][m];

    return 0;
}