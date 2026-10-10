#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =100;
string s;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int bfs(string st)//返回从st状态到ed状态的最短距离
{
    queue<string> q;//用字符串来代表状态
    unordered_map<string,int> d;//用map来判重同时记录距离
    string ed="12345678x";

    q.push(st);
    d[st]=0;

    while(q.size())
    {
        auto t=q.front();
        q.pop();

        if(t==ed) return d[t];
        //先把string状态转换成二维地图
        int dis=d[t];
        //一维变二维
        int x=t.find('x')/3;
        int y=t.find('x')%3;
        for(int i=0;i<4;i++)
        {
            int x2=x+dx[i];
            int y2=y+dy[i];
            if(x2>=0 && x2<3 && y2>=0 && y2<3)//能不能走
            {
                swap(t[x*3+y],t[x2*3+y2]);//二维变一维
                if(!d.count(t))//判重
                {
                    d[t]=dis+1;
                    q.push(t);
                }
                swap(t[x*3+y],t[x2*3+y2]);
            }
            
            
        }
        
    }

    return -1;

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i=1;i<=9;i++)
    {
        char c;cin >> c;
        s+=c;
    }

    cout << bfs(s);



    return 0;
}