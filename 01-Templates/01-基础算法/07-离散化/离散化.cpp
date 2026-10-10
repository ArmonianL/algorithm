vector<int> alls;//坐标数组
int a[N],s[N];//数据数组
vector<PII> add,query;

int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=(l+r) >> 1;
        if(alls[mid]>=x) r=mid;
        else l=mid+1;
    }
    return l;
}

int main()
{
    cin >> n >> m;
    //初始化坐标数组
    for(int i=1;i<=n;i++)
    {
        int x,c;cin >> x >> c;
        alls.push_back(x);
        add.push_back({x,c});
    }    
    for(int i=1;i<=m;i++)
    {
        int l,r;cin >> l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    //排序去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    //初始化数据数组
    for(auto i:add)
    {
        int x=find(i.first)+1;
        a[x]+=i.second;
    }

    return 0;
}