const int N =100005;
int n;
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
    cin >> n;    
    for(int i=1;i<=n;i++)
    {
        int l,r;cin >> l >> r;
        ranges[i]={l,r};
    }

    sort(ranges+1,ranges+1+n);//按左端点排序

    priority_queue<int,vector<int>,greater<int>> heap;//小根堆
    for(int i=1;i<=n;i++)
    {
        auto r=ranges[i];
        if(heap.empty() || heap.top()>=r.l) heap.push(r.r);
        else 
        {
            heap.pop();
            heap.push(r.r);
        }
    }

    cout << heap.size();
    
    return 0;
}