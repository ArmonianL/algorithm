vector<int> get_divisors(int n)
{
    vector<int> res;
    for(int i=1;i<=n/i;i++)//从1开始！！！
    {
        if(n%i==0)
        {
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);//放if里面！！！
        }
    }
    sort(res.begin(),res.end());
    return res;
}