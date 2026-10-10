#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =100010;
int n,m;
int h[N],e[N*2],ne[N*2],idx;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

queue<int> q;
int d[N];
vector<int> res;
bool topsort()
{
    //入度为0的点先进队列
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
        {
            q.push(i);
        }
    }

    while(q.size())
    {
        auto t=q.front();
        q.pop();

        res.push_back(t);

        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];

            d[j]--;//相当于删除这条边，前面的遍历过了
            //和bfs的区别
            if(d[j]==0)
            {
                q.push(j);
            }
        }
    }
    return res.size()==n;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(h,-1,sizeof(h));//这个要放前面
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin >> a >> b;
        add(a,b);
        d[b]++;
    }
    

    if(topsort())
    {
        for(auto i:res)
        cout << i << ' ';
    }
    else 
    cout << -1 << '\n';

    


    return 0;
}