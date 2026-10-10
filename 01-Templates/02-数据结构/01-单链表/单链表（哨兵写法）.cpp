//如果把数组 0 号位固定当 head，就不好扩展成多个单链表；而把 h 本身设计成变量，之后自然可以把它扩展成 h[]（后面的邻接表）。所以建议还是用经典写法
//0是头节点，编号从1开始，编号和第k个插入的数保持相同
int e[N],ne[N],idx;

void init()
{
    ne[0]=-1;
    idx=1;
}

void insert(int k,int x)
{
    e[idx]=x;ne[idx]=ne[k];ne[k]=idx;idx++;
}

void remove(int k)
{
    ne[k]=ne[ne[k]];
}

int main()
{
  
    init();
    
    while(n--)
    {
        char c;cin >> c;
        if(c=='H')
        {
            int x;cin >> x;
            insert(0,x);
        }
        else if(c=='D')
        {
            int k;cin >> k;
            remove(k);
        }
        else if(c=='I')
        {
            int k,x;cin >> k >> x;
            insert(k,x);
        }
    }

    for(int i=ne[0];i!=-1;i=ne[i]) cout << e[i] << ' ';

    return 0;
}