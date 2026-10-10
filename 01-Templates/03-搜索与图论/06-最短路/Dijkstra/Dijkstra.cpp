const int N =505;
int g[N][N];

void init()
{
    memset(g,0x3f,sizeof(g));
}

int dis[N];
bool vis[N];
int dijkstra()
{
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;

    for(int i=1;i<=n;i++)
    {
        //选最小
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j] && (t==-1 || dis[j]<dis[t])) t=j;
        }
        vis[t]=true;
        //更新
        for(int j=1;j<=n;j++)
        {
            dis[j]=min(dis[j],dis[t]+g[t][j]);
        }
    }

    if(dis[n]==0x3f3f3f3f) return -1;//这里注意一下,不能用vis判断是否到达，vis代表有没有选，无论是否到达所有的数都会被选一遍
    else return dis[n];
}

int main()
{
    cin >> n >> m;init();
    while(m--)
    {
        int a,b,c;cin >> a >> b >> c;
        g[a][b]=min(g[a][b],c);//排除了重边，自环不用显式排除，因为最短路不会走自环
    }
    cout << dijkstra();
    
    return 0;
}