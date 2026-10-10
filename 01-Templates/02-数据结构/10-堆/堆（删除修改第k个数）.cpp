int h[N],sz;
int ph[N],hp[N];//因为本题要求修改和删除第k个插入的数，所以需要建立一个k与下标直接的双向映射，ph[i]=a：第i个插入的数下标为a hp[a]=i;

//因为每次交换完h[a]和h[b]后对应的映射也要换所以要重写交换函数
void hswap(int a,int b)//后面注意，参数是下标了，表示同时交换h和映射。后面的参数不要再写h[a],h[b]了
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}

void down(int u)
{
    while(true)
    {
        int t=u;
        if(2*u<=sz && h[2*u]<h[t]) t=2*u;
        if(2*u+1<=sz && h[2*u+1]<h[t]) t=2*u+1;
        
        if(t==u) break;

        hswap(t,u);
        u=t;
    }
}

void up(int u)
{
    while(u/2>=1 && h[u/2]>h[u])
    {
        hswap(u/2,u);
        u/=2;
    }
}

int main()
{
    int k=0;//表示第k个插入的数
    for(int i=1;i<=n;i++)
    {
        string s;cin >> s;
        if(s=="I")//插入一个数
        {
            int x;cin >> x;
            h[++sz]=x;
            ph[++k]=sz,hp[sz]=k;
            up(sz);
        }
        else if(s=="PM")//输出堆顶
        {
            cout << h[1] << '\n';
        }
        else if(s=="DM")//删除堆顶
        {
            hswap(1,sz);
            sz--;
            down(1);
        }
        else if(s=="D")//删除某个数（本题是第k个插入的数）
        {
            int k;cin >> k;
            k=ph[k];
            hswap(k,sz);
            sz--;
            down(k),up(k);
        }
        else if(s=="C")//修改某个数（本题是第k个插入的数）
        {
            int k,x;cin >> k >> x;
            k=ph[k];
            h[k]=x;
            down(k),up(k);
        }
    }

    return 0;
}