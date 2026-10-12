//给定若干堆果子，每次合并两堆的代价为两堆数量之和，求将所有果子合成一堆的最小总代价。
//贪心：每次合并最小的两个
const int N =100005;
int n;
int ans;
priority_queue<int,vector<int>,greater<int>> heap;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x;cin >> x;
        heap.push(x);
    }    

    while(heap.size()>1)
    {
        int a=heap.top();heap.pop();
        int b=heap.top();heap.pop();
        ans+=a+b;
        heap.push(a+b);
    }
    cout << ans;

    return 0;
}