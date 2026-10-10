//滑动窗口
int n,k;
int a[N];
deque<int> dq;//和单调栈不同这里的dq存的是下标，为了方便判断窗口合不合法

int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++)
    {
        if(!dq.empty() && i-dq.front()>=k) dq.pop_front();
        while(!dq.empty() && a[dq.back()]>=a[i]) dq.pop_back();

        dq.push_back(i);
        if(i>=k) cout << a[dq.front()] << ' ';    
    }
    cout << '\n';
    dq.clear();//这个不要忘记！！！
    for(int i=1;i<=n;i++)
    {
        if(!dq.empty() && i-dq.front()>=k) dq.pop_front();
        while(!dq.empty() && a[dq.back()]<=a[i]) dq.pop_back();

        dq.push_back(i);
        if(i>=k) cout << a[dq.front()] << ' ';    
    }

    return 0;
}