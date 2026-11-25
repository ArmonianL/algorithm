//给定农夫和牛在数轴上的位置，农夫每次可移动到相邻位置或当前位置的两倍位置，每次耗时 1 分钟，求抓到牛的最短时间。

const int N =200010;//估计的不能超过的最右端
int a,b;//农夫位置，牛位置

int d[N];//d+vis
int bfs()
{
    memset(d,-1,sizeof(d));

    queue<int> q;

    d[a]=0;
    q.push(a);

    while(q.size())
    {
        auto t=q.front();
        q.pop();

        if(t==b) return d[t];

        if(t+1<N && d[t+1]==-1)
        {
            d[t+1]=d[t]+1;
            q.push(t+1);
        }
        if(t-1<N && d[t-1]==-1)
        {
            d[t-1]=d[t]+1;
            q.push(t-1);
        }
        if(t*2<N && d[t*2]==-1)
        {
            d[t*2]=d[t]+1;
            q.push(t*2);
        }
    }
    return -1;
}

int main()
{
    cin >> a >> b;
    
    cout << bfs();
    
    return 0;
}