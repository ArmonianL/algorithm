int g[N][N];//存地图
int d[N][N];//存最短距离（离原点）

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void bfs()
{
    queue<PII> q;
    memset(d,-1,sizeof(d));
    d[0][0]=0;

    q.push({0,0});

    while(q.size())
    {
        auto t=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int x=t.first+dx[i];
            int y=t.second+dy[i];

            if(x>=0 && x<n && y>=0 && y<m && g[x][y]==0 && d[x][y]==-1)//能不能走+判重
            {
                d[x][y]=d[t.first][t.second]+1;
                q.push({x,y});
            }
        }
    }
}
