vector<PII> v,res;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int l,r;cin >> l >> r;
        v.push_back({l,r});
    }
    sort(v.begin(),v.end());

    int st=-2e9,ed=-2e9;
    for(auto i:v)
    {
        if(ed<i.first)
        {
            if(st!=-2e9) res.push_back({st,ed});//排除第一个
            st=i.first;
            ed=i.second;
        }
        else ed=max(ed,i.second);
    }
    res.push_back({st,ed});//加入最后一个

    return 0;
}