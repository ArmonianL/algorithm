const int N =150010;
int h[N],e[N],w[N],ne[N],idx;

void init()
{
    memset(h,-1,sizeof(h));
}

void add(int a,int b,int c)
{
    e[idx]=b;w[idx]=c;ne[idx]=h[a];h[a]=idx++;
}

bool vis[N];
int dis[N];
int dijkstra()
{
    priority_queue<PII,vector<PII>,greater<PII>> pq;

    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    pq.push({0,1});

    while(pq.size())
    {
        auto t=pq.top();
        pq.pop();

        int ver=t.second;//pq.first在代码中用不到,但是是用来形成小根堆的

        if(vis[ver]) continue;
        vis[ver]=true;

        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dis[ver]+w[i]<dis[j])
            {
                dis[j]=dis[ver]+w[i];
                pq.push({dis[j],j});
            }
        }
    }

    if(dis[n]==0x3f3f3f3f) return -1;
    else return dis[n];
}

int main()
{
    cin >> n >> m;init();
    while(m--)
    {
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
    }
    cout << dijkstra();

    return 0;
}