//给定一个目标区间和n个小区间，从中选出尽可能少的区间，使它们能够完全覆盖目标区间；如果无法完全覆盖，输出-1
//先按左端点从小到大排序；每次在所有左端点不超过当前已覆盖右边界的区间中，选择右端点最远的那个，把覆盖范围尽可能往右推进。
const int N =100005;
const int INF=0x3f3f3f3f;
int s,t;
int n;
int ans;

struct range
{
    int l,r;
    bool operator<(const range &other)const 
    {
        return l<other.l;
    }
}ranges[N];

int main()
{
    cin >> s >> t;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> ranges[i].l >> ranges[i].r;

    sort(ranges+1,ranges+1+n);
    
    if(s==t)//特判
    {
        bool tag=false;
        for(int i=1;i<=n;i++) 
        {
            if(ranges[i].l<=s && ranges[i].r>=s)
            {
                cout << 1;
                return 0;
            }
        }
        cout << -1;
        return 0;
    }

    int k=1;
    int cur=s;
    while(cur<t)
    {
        int maxr=-INF;
        while(k<=n && ranges[k].l<=cur)//防数组越界！！！
        {
            maxr=max(maxr,ranges[k].r);
            k++;
        }
        if(maxr<=cur)
        {
            ans=-1;
            break;
        }
        else 
        {
            cur=maxr;
            ans++;
        }
    }

    cout << ans;

    return 0;
}