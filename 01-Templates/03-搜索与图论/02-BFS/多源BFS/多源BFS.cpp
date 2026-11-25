//线性时间复杂度

// 求每个点到最近源点的最短距离
// -> 转化为求所有源点到每个点的最短距离的最小值（无向图）
// -> 相当于所有源点同时开始BFS
// -> 建立虚拟源点，向所有源点连一条权值为0的边
// -> 转化为以虚拟源点为起点的单源最短路问题
// -> 等价于将所有源点的距离初始化为0并同时入队
// -> 执行多源BFS，首次访问某点时即确定其最短距离
const int N =1005;
int n,m;
char g[N][N];

int d[N][N];//d+vis
void bfs()
{
    int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
    memset(d,-1,sizeof(d));

    queue<PII> q;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(g[i][j]=='1')
            {
                d[i][j]=0;
                q.push({i,j});
            }
        }
    }

    while(q.size())
    {
        auto t=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int x=t.first+dx[i],y=t.second+dy[i];

            if(x<1 || x>n || y<1 || y>m) continue;
            if(d[x][y]!=-1) continue;

            d[x][y]=d[t.first][t.second]+1;
            q.push({x,y});
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) 
            cin >> g[i][j];

    bfs();

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}