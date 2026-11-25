//O(n + m) 判断是否是二分图
//二分图 <=> 不含奇数环
// 有矛盾=>有奇数环=>不是二分图  
// 没矛盾=>没奇数环=>是二分图
//遍历所有未染色的顶点，通过 DFS 将相邻顶点染成不同颜色
//若发现相邻顶点颜色相同，则说明图中存在奇数环，不是二分图；否则，该图是二分图。
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

bool dfs(int u,int c)//将 u 点染成颜色 c，并判断从该点继续染色是否能够成功
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