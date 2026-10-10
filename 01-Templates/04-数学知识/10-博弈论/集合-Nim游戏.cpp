//集合 Nim 游戏：给定若干石子堆和一个可取数集合，每次任选一堆拿走集合中规定数量的石子，无法继续操作者输。
const int N=106,M=100010;
int m,n;
int s[N];
int SG[M];//负责“把算出来的答案存起来”

void init()
{
    memset(SG,-1,sizeof(SG));
}

int sg(int x)//负责“去算”
{
    if(SG[x]!=-1) return SG[x];//记忆化搜索
    
    unordered_set<int> S;
    for(int i=1;i<=m;i++)
    {
        int sum=s[i];
        if(x-sum>=0) S.insert(sg(x-sum));//递归求后继SG值，碰底了就返回0,不需要再显式写 if (x == 0) return 0;
    }
    //求mex
    for(int i=0;;i++)
    {
        if(S.count(i)==0) return SG[x]=i;
    }
} 

int main()
{
    cin >> m;    
    for(int i=1;i<=m;i++) cin >> s[i]; 
    init();

    cin >> n;
    int res=0;
    for(int i=1;i<=n;i++) 
    {
        int x;cin >> x;
        res^=sg(x);
    }
    if(res!=0) cout << "Yes";
    else cout << "No";
    
    return 0;
}