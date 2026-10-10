//贪心算法每次选一个与前面不相交的新区间时，就在它的右端点放一个点
// 区间1：[--------●]
//                  区间2：[------●]
//                               区间3：[----●]
//选出来的k个区间有两个特点：1.k个区间不相交 2.k个右端点覆盖所有区间
//k：区间数/选点数

//1：最少选点数>=区间数=k（任何覆盖方案至少得给这k个区间各安排一个点）
//2：最少选点数<=选点数=k（用k个点的这个方案合法，所以大于等于最少）
const int N =100005;
int n;
struct range
{
    int l,r;

    bool operator<(const range& other)const
    {
        return r<other.r;
    }

}range[N];

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int l,r;cin >> l >> r;
        range[i]={l,r};
    }
    sort(range+1,range+1+n);

    int res=0;
    int ed=-2e9;
    for(int i=1;i<=n;i++)
    {
        if(range[i].l>ed)//这里看的是左端点
        {
            ed=range[i].r;
            res++;
        }
    }
    cout << res;
    
    return 0;
}