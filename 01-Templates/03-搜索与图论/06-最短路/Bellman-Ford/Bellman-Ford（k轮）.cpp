//要求最多k条路
const int N =505;
const int M=100010;
const int INF=0x3f3f3f3f;
int n,m,k;
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

    for(int i=1;i<=k;i++)
    {
        memcpy(last,dis,sizeof(dis));
        for(int j=1;j<=m;j++)
        {
            int a=edges[j].a;int b=edges[j].b;int c=edges[j].c;
            if(last[a]<INF && last[a]+c<dis[b])
            {
                dis[b]=last[a]+c;
            }
        }
    }

    if(dis[n]==INF) return false;
    else return true;
}   

int main()
{
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;cin >> a >> b >> c;
        edges[i]={a,b,c};
    }

    if(bellman_ford()) cout << dis[n];
    else cout << "impossible";

    return 0;
}