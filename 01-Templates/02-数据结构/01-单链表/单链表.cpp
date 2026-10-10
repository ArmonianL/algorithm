//编号从0开始
int h,e[N],ne[N],idx;

void add_head(int x)
{
    e[idx]=x,ne[idx]=h,h=idx++;
}

void add(int k,int x)
{
    e[idx]=x,ne[idx]=ne[k],ne[k]=idx++;
}

void remove(int k)
{
    ne[k]=ne[ne[k]];
}

int main()
{
    while(m--)
    {
        char c;cin >> c;
        if(c=='H')
        {
            int x;cin >> x;
            add_head(x);
        }
        else if(c=='D')
        {
            int k;cin >> k;
            if(k==0) h=ne[h];//头节点要特判
            else remove(k-1);//结点编号从0开始的
        }
        else 
        {
            int k,x;cin >> k >> x;
            add(k-1,x);
        }

    }

    return 0;
}
