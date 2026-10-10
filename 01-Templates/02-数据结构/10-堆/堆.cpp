//堆就是一个特殊的完全二叉树，根节点是1
int h[N],sz;

void init()
{
    sz=0;
}

void down(int p)
{
    while(true)
    {
        int t=p;
        if(2*p<=sz && h[2*p]<h[t]) t=2*p;
        if(2*p+1<=sz && h[2*p+1]<h[t]) t=2*p+1;
        if(t==p) break;
        swap(h[t],h[p]);
        p=t;
    }
}

void up(int p)
{
    while(p/2>=1 && h[p/2]>h[p])
    {
        swap(h[p/2],h[p]);
        p=p/2;
    }
}

int main()
{
    init();
    while(n--)
    {
        string s;cin >> s;
        if(s=="I")//插入某个数
        {
            int x;cin >> x;
            h[++sz]=x;
            up(sz);
        }
        else if(s=="PM")//打印堆顶
        {
            cout << h[1] << '\n';
        }
        else if(s=="DM")//删除堆顶
        {
            swap(h[1],h[sz]);
            sz--;
            down(1);
        }
        else if(s=="D")//删除某个数(比如删除节点p)
        {
            int p;cin >> p;//这里其实要特判一下p==sz的情况，当然如果不特判也是正确的，因为up和down不会执行
            swap(h[p],h[sz]);
            sz--;
            up(p),down(p);
        }
        else if(s=="C")//修改某个数
        {
            int p,x;cin >> p >> x;
            h[p]=x;
            up(p),down(p);
        }
    }
    
    return 0;
}