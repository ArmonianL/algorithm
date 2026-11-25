//线性时间复杂度，找到某个点所在的连通块（连通块中每个点就遍历一遍）
//两层for遍历整张图+bfs

//本题：找图中有多少个连通块（八连通）
const int N =1005;
int n,m;
char g[N][N];
bool vis[N][N];
int cnt;

void bfs(int sx,int sy)
{
    queue<PII> q;

    q.push({sx,sy});
    vis[sx][sy]=true;

    while(q.size())
    {
        auto t=q.front();
        q.pop();
        int x=t.first,y=t.second;

        for(int i=x-1;i<=x+1;i++)
        {
            for(int j=y-1;j<=y+1;j++)
            {
                //continue写法和if写法等价
                if(i==x && j==y) continue;
                if(i<1 || i>n || j<1 || j>m) continue;
                if(g[i][j]=='.') continue;
                if(vis[i][j]) continue;

                q.push({i,j});
                vis[i][j]=true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++)
            cin >> g[i][j];
            
    for(int i=1;i<=n;i++)//遍历所有点，如果没有访问过且点为W就bfs
    {
        for(int j=1;j<=m;j++)
        {
            if(!vis[i][j] && g[i][j]=='W')
            {
                bfs(i,j);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}