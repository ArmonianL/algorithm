const int N =20;//这里不能多开，不然f数组会大的离谱
int w[N][N];
int f[1 << N][N];//第一维别开错
//f[i][j]:走的状态是i，走到j的所有方案的最短路径（i的二进制01代表走没走）
//从倒数第二个点走到终点j，将倒数第二个点进行分类

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin >> w[i][j];
    }

    memset(f,0x3f,sizeof(f));
    f[1][0]=0;//起点是0
    for(int i=1;i<1<<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i >> j & 1)//i里面的j一定要走过
            {
                for(int k=0;k<n;k++)
                {
                    if((i >> k & 1) && (k!=j))//倒数第二个点一定要走过且不能是终点
                    {
                        f[i][j]=min(f[i][j],f[i-(1 << j)][k]+w[k][j]);
                    }

                }
            }
        }
    }
    cout << f[(1 << n)-1][n-1];
    
    return 0;
}