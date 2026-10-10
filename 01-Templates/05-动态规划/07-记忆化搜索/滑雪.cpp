//n*m的山，高低不等，从一个点只能往高度严格减小的地方滑，求滑过的格子数量最大值
const int N =305;
int n,m;
int ans;
int g[N][N];
int f[N][N];
//f[i][j]：从(i,j)开始往下滑到底的经过的个数的最大数量
//每个(i,j)依赖未来的上下左右四个方向的f
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool vis[N][N];//记忆化搜索，把之前已经走过的点数据保留
int dp(int x,int y)//返回更新完的f[x][y]，用递归+记忆化
{
    if(vis[x][y]) return f[x][y];
    vis[x][y]=true;
    
    f[x][y]=1;//因为有可能下面四个方向都不能走，还要再特判，所有这里先提前加上
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=1 && nx<=n && ny>=1 && ny<=m && g[nx][ny]<g[x][y])
        {
            f[x][y]=max(f[x][y],1+dp(nx,ny));
        }
    }
    return f[x][y];
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin >> g[i][j];
    }    
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) ans=max(ans,dp(i,j));
    }

    cout << ans;

    return 0;
}