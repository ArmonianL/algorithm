int p[N];

int find(int x)//返回x的祖宗结点+路径压缩
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int main()
{
    for(int i=1;i<=n;i++) p[i]=i;//一开始每个数就是根节点，p[i]=i是根节点的标志，不是根节点的点的父亲不可能是自身。可以理解为根节点父亲指向自己

    while(m--)
    {
        char c;cin >> c;
        if(c=='M')//合并
        {
            int a,b;cin >> a >> b;
            p[find(a)]=find(b);
        }
        else if(c=='Q')//查询
        {
            int a,b;cin >> a >> b;
            if(find(a)==find(b)) cout << "Yes\n";
            else cout << "No\n";
        }
    }    

    return 0;
}