const int N =100010;
int h[N],e[N*2],ne[N*2],idx;
int color[N];//0表示没有染色，1,2表示已经染色

void init()
{
    memset(h,-1,sizeof(h));
}

void add(int a,int b)
{
    e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}

bool dfs(int u,int c)//返回u点开始染色会不会出现矛盾
{
    color[u]=c;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!color[j])
        {
            if(!dfs(j,3-c)) return false;
        }
        else if(color[j]==c) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;init();
    for(int i=1;i<=m;i++)    
    {
        int a,b;cin >> a >> b;
        add(a,b);add(b,a);
    }

    bool tag=true;
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1)) tag=false;
        }
    }

    if(tag) cout << "Yes";
    else cout << "No";

    return 0;
}