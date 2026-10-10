const int N =1010;
const int P=1e9+7;
int ans;
int f[N][N];
//f[i][j]：选了i个数，总和是j的所有方案数
//f[i][j]=f[i-1][j-1]+f[i][j-i];左边=最小值是1的方案数+最小值大于1的方案数
//ans=∑{f[1][n],f[2][n],......f[n][n]}

int main()
{
    cin >> n;
    for(int j=1;j<=n;j++) f[1][j]=1;//想清楚初始条件
    for(int i=2;i<=n;i++)
    {
        for(int j=i;j<=n;j++)  
        {
            f[i][j]=(f[i-1][j-1]+f[i][j-i])%P;
        }
    }

    for(int i=1;i<=n;i++) ans=(ans+f[i][n])%P;
    cout << ans;

    return 0;
}