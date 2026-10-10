//0是头节点，1是尾节点，编号从2开始
int e[N],l[N],r[N],idx;

void init()
{
    r[0]=1;
    l[1]=0;
    idx=2;
}

void add(int k,int x)
{
    e[idx]=x;
    r[idx]=r[k];
    l[idx]=k;
    r[k]=idx;
    l[r[idx]]=idx;
    idx++;
}

void remove(int k)//删除k结点本身，不是k后面的了
{
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}

int main()
{
    init();

    return 0;
}