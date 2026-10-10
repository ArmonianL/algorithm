int g[N][N];

void init()
{
    memset(g,0x3f,sizeof(g));
}

int dis[N];
bool vis[N];
int prim()
{
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;//自己选择一个点当作起点

    int res=0;
    for(int i=1;i<=n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j] && (t==-1 || dis[j]<dis[t])) t=j;
        }

        if(dis[t]==INF) return INF;

        vis[t]=true;
        res+=dis[t];

        for(int j=1;j<=n;j++)
        {
            dis[j]=min(dis[j],g[t][j]);
        }
    }
    return res;
}

int main()
{
    cin >> n >> m;init();
    while(m--)
    {
        int a,b,c;cin >> a >> b >> c;
        if(a==b) continue;//考虑：自环。不判断自环，通常不会影响最终 MST 权值，但会影响 dis 数组的含义。
        g[a][b]=g[b][a]=min(g[a][b],c);//考虑：无向边，重边
    }

    int t=prim();
    if(t==INF) cout << "impossible";
    else cout << t;

    return 0;
}