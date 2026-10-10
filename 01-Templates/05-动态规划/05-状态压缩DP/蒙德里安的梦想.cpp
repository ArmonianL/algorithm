const int N=15;
int n,m;
//f[i][j]：前i-1列已经排好，第i列突出来的状态（二进制）压缩成十进制为j的方案数
ll f[N][1 << N];//第二维不要开小了，一定要开long long!!!
bool a[1 << N];//a[j]：j的二进制表示是否合法（连续的0是否是偶数个）
vector<int> b[1 << N];//b[i]：能与i配对的所有状态

void init()
{
    fill(f[0],f[0]+N*(1 << N),0);
    fill(a,a+(1 << N),0);
    for(int i=0;i<1 << N;i++) b[i].clear();
}

int main()
{   
    while(cin >> n >> m,n || m)
    {
        init();
        //预处理千万不能放在while外面，不然默认每组数据都是N位了，这样不对，比如0这个数，m=2，应该是00，但放外面就是00...0一共15个0
        //预处理a
        for(int i=0;i<1 << m;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                int u=i >> j & 1;//不要写反
                if(u==1)
                {
                    if(cnt%2==1) break;
                    cnt=0;
                }
                else 
                {
                    cnt++;
                }
            }
            if(cnt%2==0) a[i]=true;
        }
        //预处理b
        for(int i=0;i<1 << m;i++)
        {
            for(int j=0;j<1 << m;j++)
            {
                if((i & j)==0) b[i].push_back(j);
            }
        }

        f[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<1 << m;j++)
            {
                
                for(auto k:b[j])
                {
                    if(a[k | j]) f[i][j]+=f[i-1][k];
                }
                
            }
        }
        cout << f[n][0] << '\n';
    }

    return 0;
}