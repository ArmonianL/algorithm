//O(mlogm) 稀疏图
//（全图）选不形成环的最小边
int p[N];
struct Edge
{
    int a,b,c;
    bool operator < (const Edge &i)const 
    {
        return c<i.c;
    }
}edges[M];

void init()
{
    for(int i=1;i<=n;i++) p[i]=i;
}

int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges+1,edges+1+m);//时间复杂度主要开销
    int res=0;
    int cnt=0;//已选边数
    for(int i=1;i<=m;i++)
    {
        int a=edges[i].a,b=edges[i].b,c=edges[i].c;
        int fa=find(a);
        int fb=find(b);
        if(fa!=fb)
        {
            p[fa]=fb;
            res+=c;
            cnt++;
        }
    }
    if(cnt==n-1) return res;//注意不能用m判断！！！
    else return INF;
}

int main()
{
    cin >> n >> m;init();
    for(int i=1;i<=m;i++)
    {
        int a,b,c;cin >> a >> b >> c;
        //自环不要跳过，不然edges数组会空一个位置，并查集会自行处理自环
        edges[i]={a,b,c};//无向边，重边加进去没关系
    }

    int t=kruskal();
    if(t==INF) cout << "impossible";
    else cout << t;

    return 0;
}