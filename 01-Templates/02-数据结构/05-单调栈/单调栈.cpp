//求某个数左边比它小的离它最近的那个数（下标最近）
int stk[N],tt;

int main()
{
    while(n--)
    {
        int x;cin >> x;
        while(tt && stk[tt]>=x) tt--;
        if(tt)cout << stk[tt] << ' ';
        else cout << -1 << ' ';
        stk[++tt]=x;
    }

    return 0;
}