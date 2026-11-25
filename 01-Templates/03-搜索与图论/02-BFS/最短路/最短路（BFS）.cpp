//线性时间复杂度 
//无权图、边权全为1

//bfs相当于特殊的dijkstra算法，每次选最小就相当于选queue的队头（因为边权都是1，都是最小）
//所以bfs里面的queue相当于是dijkstra里的priority_queue

//求最短路和对应的路径
const int N =1005;
int n;
int g[N][N];
vector<PII> path;

int d[N][N];
int vis[N][N];//其实vis和pre数组可以合成一个，如果pre==-1说明没有vis过，当然也能和d数组合并
PII pre[N][N];
void bfs(int sx,int sy)//起点
{
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    queue<PII> q;

    d[sx][sy]=0;
    vis[sx][sy]=true;
    q.push({sx,sy});

    while(q.size())
    {
        auto t=q.front();
        q.pop();    

        for(int i=0;i<4;i++)
        {
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x<1 || x>n || y<1 || y>n) continue;
            if(g[x][y]==1) continue;
            if(vis[x][y]) continue;

            d[x][y]=d[t.first][t.second]+1;
            pre[x][y]=t;
            vis[x][y]=true;
            q.push({x,y});
        }
    }
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++)
            cin >> g[i][j];

    //如果只要求路径，可以从终点BFS，沿pre从起点直接正序输出
    //如果要求从起点到各点的最短距离d，则应从起点BFS
    bfs(1,1);

    PII end={n,n};

    while(true)
    {
        path.push_back({end.first-1,end.second-1});//图从(0,0)开始的
        if(end.first==1 && end.second==1) break;
        end=pre[end.first][end.second];
    }

    for(int i=path.size()-1;i>=0;i--) cout << path[i].first << ' ' << path[i].second << '\n';

    return 0;
}