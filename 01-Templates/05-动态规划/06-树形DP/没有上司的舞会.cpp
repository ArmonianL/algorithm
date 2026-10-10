//每个人有快乐指数，去参加舞会的人不能有上司下属关系，求快乐指数最大值
const int N=6005;
int happy[N];
int f[N][2];
//f[u][0]：以u为根且不选u的子树的快乐指数和的最大值，f[u][0]=∑max{f[si][0],f[si][1]};
//f[u][1]：以u为根且选u的子树的快乐指数和的最大值，f[u][1]=∑f[si][0];
int h[N],e[N],ne[N],idx;
bool has_father[N];

void init()
{
    memset(h,-1,sizeof(h));
}

void add(int a,int b)
{   
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u)
{
    f[u][1]=happy[u];

    for(int i=h[u];i!=-1;i=ne[i])   
    {
        int j=e[i];
        dfs(j);
        f[u][0]+=max(f[j][0],f[j][1]);
        f[u][1]+=f[j][0];
    }
}

int main()
{
    cin >> n;init();
    for(int i=1;i<=n;i++) cin >> happy[i];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;cin >> a >> b;
        add(b,a);
        has_father[a]=true;
    }

    int root=1;
    while(has_father[root]) root++;//找到第一个根（随便找一个就行，因为dfs都能遍历到）

    dfs(root);

    cout << max(f[root][0],f[root][1]);

    return 0;
}