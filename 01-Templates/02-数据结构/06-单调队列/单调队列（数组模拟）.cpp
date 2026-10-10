//解决滑动窗口最值问题
int q[N],hh,tt;

void init()
{
    hh=0;//这个不要漏
    tt=-1;
}

int main()
{

    init();
    for(int i=1;i<=n;i++) cin >> a[i];
    //建议遍历每个数，不要遍历窗口，用if(i>=k)判断是否合法
    for(int i=1;i<=n;i++)
    {
        if(tt>=hh && i-q[hh]+1>k) hh++;

        while(tt>=hh && a[q[tt]]>=a[i]) tt--;
        q[++tt]=i;

        if(i>=k) cout << a[q[hh]] << ' ';
    }

    cout << '\n';
    init();

    for(int i=1;i<=n;i++)
    {
        if(tt>=hh && i-q[hh]+1>k) hh++;

        while(tt>=hh && a[q[tt]]<=a[i]) tt--;
        q[++tt]=i;

        if(i>=k) cout << a[q[hh]] << ' ';
    }

    return 0;
}