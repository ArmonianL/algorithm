const int INF=0x3f3f3f3f;
int h[N],e[N],w[N],ne[N],idx;

void init()
{
    memset(h,-1,sizeof(h));
}

void add(int a,int b,int c)
{
    e[idx]=b;w[idx]=c;ne[idx]=h[a];h[a]=idx++;
}

int dis[N];
int cnt[N];
bool vis[N];//防止队列里面有相同的数
bool spfa()
{
    queue<int> q;

    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    q.push(1);
    vis[1]=true;
    /*
    如果题目要求整个图中是否存在负环
    上面的初始化改为：（每个点都可能是源点）
    for(int i=1;i<=n;i++)
    {
        dis[i]=0;
        q.push(i);
        vis[i]=true;
    }
    */
    while(q.size())
    {
        auto t=q.front();
        q.pop();
        vis[t]=false;
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dis[t]+w[i]<dis[j])
            {
                dis[j]=dis[t]+w[i];
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n) return false;
                if(!vis[j])
                {
                    q.push(j);
                    vis[j]=true;
                }
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;init();
    while(m--)
    {
        int a,b,c;cin >> a >> b >> c;
        add(a,b,c);
    }

    if(spfa())
    {
        if(dis[n]==INF) cout << "没有源点可达负环，但是到不了n";
        else cout << "最短路径：" << dis[n];
    }
    else cout << "有源点可达负环";

    return 0;
}