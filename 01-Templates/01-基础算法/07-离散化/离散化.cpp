// -> ：映射
// 大数组下标 -> 小数组下标
// vector<int> alls：alls[小数组下标]=大数组下标
// find二分：大找小，同时注意alls是从0开始的，有时映射需要从1开始
const int N =300005;
vector<int> alls;
int a[N];

int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(alls[mid]<=x) l=mid;
        else r=mid-1;
    }
    return r+1;//偏移了一位
}

int main()
{

    for(int i=1;i<=n;i++)
    {
        int x;cin >> x;
        alls.push_back(x);
    }

    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    return 0;
}