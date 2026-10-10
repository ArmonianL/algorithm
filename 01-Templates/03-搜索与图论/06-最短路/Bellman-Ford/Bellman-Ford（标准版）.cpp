//标准bellman-ford算法
const int N =505;
const int M=100010;
const int INF=0x3f3f3f3f;
int n,m;

struct Edge
{
    int a,b,c;
}edges[M];

int dis[N];
int last[N];
bool bellman_ford()
{
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    //n-1轮
    for(int i=1;i<=n-1;i++)
    {
        memcpy(last,dis,sizeof(dis));//严格用上一轮的dis，防止本轮前面更新过的dis影响后面的dis的更新
        for(int j=1;j<=m;j++)
        {
            int a=edges[j].a;
            int b=edges[j].b;
            int c=edges[j].c;
            if(last[a]<INF && last[a]+c<dis[b])//无穷不更新
            {
                dis[b]=last[a]+c;
            }
        }

    }
    //判断有没有负环
    for(int i=1;i<=m;i++)
    {
        int a=edges[i].a;
        int b=edges[i].b;
        int c=edges[i].c;
        if(last[a]<INF && last[a]+c<dis[b]) return false;
    }

    return true;
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;cin >> a >> b >> c;
        edges[i]={a,b,c};
    }    

    if(bellman_ford()) 
    {
        if(dis[n]==INF) cout << "无源点可达的负环并且1到达不了n";
        else cout << "最短路径距离：" << dis[n];
    }
    else cout << "有源点可达的负环";

    return 0;
}