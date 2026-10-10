//最大不相交区间数=最大选点数（完全一样的贪心策略）

//贪心算法每次选一个与前面不相交的新区间时，就在它的右端点放一个点
// 区间1：[--------●]
//                  区间2：[------●]
//                               区间3：[----●]
//选出来的k个区间有两个特点：1.k个区间不相交 2.k个右端点覆盖所有区间
//k：区间数/选点数

//1：最大不相交区间数>=区间数=k（用k个点的这个方案合法，所以小于等于最大）
//2：最大不相交区间数<=选点数=k（k个右端点可以覆盖所有区间，肯定覆盖任意数量的不相交的区间）
const int N =100005;
int n;
struct range
{
    int l,r;
    bool operator<(const range& other)const
    {
        return r<other.r;
    }
}ranges[N];

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int l,r;cin >> l >> r;
        ranges[i]={l,r};
    }    

    sort(ranges+1,ranges+1+n);

    int res=0;
    int ed=-2e9;
    for(int i=1;i<=n;i++)
    {
        if(ranges[i].l>ed)
        {
            ed=ranges[i].r;
            res++;
        }
    }

    cout << res;
    
    return 0;
}