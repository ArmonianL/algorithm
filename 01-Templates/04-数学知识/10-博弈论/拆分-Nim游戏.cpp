//给定若干堆石子，双方轮流将一堆替换为两堆规模更小的石子，无法操作者输，判断最优策略下先手是否必胜。
const int N =105;
int n;
int a[N];
int f[N];

void init()
{
    memset(f,-1,sizeof(f));
}

int sg(int x)
{
    if(f[x]!=-1) return f[x];

    unordered_set<int> s;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<=i;j++)
        {
            s.insert(sg(i)^sg(j));//一个局面分成了两个局面
        }
    }

    for(int i=0;;i++)
    {
        if(s.count(i)==0) return f[x]=i;
    }
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    init();

    int res=0;
    for(int i=1;i<=n;i++) res^=sg(a[i]);

    if(res!=0) cout << "Yes";
    else cout << "No";
    
    return 0;
}