const int N =305;
const int INF=0x3f3f3f3f;
int a[N];
int s[N];
int f[N][N];

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];

    for(int len=2;len<=n;len++)//枚举区间长度,这里一定要从2开始，因为第一层已经隐式初始化过了
    {
        for(int i=1;i+len-1<=n;i++)//枚举起点
        {
            int l=i,r=i+len-1;
            f[l][r]=INF;
            for(int j=l;j<r;j++)
            {
                f[l][r]=min(f[l][r],f[l][j]+f[j+1][r]+s[r]-s[l-1]);
            }
        }
    }
    cout << f[1][n];

    return 0;
}