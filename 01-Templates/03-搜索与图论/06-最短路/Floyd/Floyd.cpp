const int N =205;
const int INF=0x3f3f3f3f;
int d[N][N];//距离数组

void init()
{
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++) d[i][i]=0;
}

void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;init();
    while(m--)
    {
        int a,b,c;cin >> a >> b >> c;
        d[a][b]=min(d[a][b],c);//min：考虑重边
    }
    floyd();
    while(k--)
    {
        int a,b;cin >> a >> b;
        if(d[a][b]>INF/2) cout << "impossible\n";//这里一定要注意一下，因为中间计算可能改变INF！！！
        else cout << d[a][b] << '\n';
    }

    return 0;
}