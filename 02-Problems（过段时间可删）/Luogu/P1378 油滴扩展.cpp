#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using PII=pair<int,int>;
const int N =2002;
const double PI=acos(-1);
int n;
int x1,ya,x2,y2;
vector<PII> v,res;
bool vis[10];
double ans=1e9;


double len(int x1,int ya,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(ya-y2)*(ya-y2));
}


double s(vector<PII> &res)
{
    double R[10]={0};
    double ans=0;
    for(int i=0;i<n;i++)
    {
       
        int x=res[i].first;
        int y=res[i].second;
        double r=min({abs(x-x1),abs(x-x2),abs(y-ya),abs(y-y2)});
        for(int j=0;j<i;j++)
        {
            r=min(r,len(x,y,res[j].first,res[j].second)-R[j]);
            r = max(0.0, r);//之前的油可能已经把这个点覆盖了
            
        }
        R[i]=r;
        ans+=PI*r*r;
    }
    return ans;
}


void dfs(int u)
{
    if(u==n)
    {
        ans=min(ans, abs(x1-x2)*abs(ya-y2)-s(res));
        return;
    }
    

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            res.push_back(v[i]);
            vis[i]=true;
            dfs(u+1);
            res.pop_back();
            vis[i]=false;
        }
    }
}




int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> x1 >> ya >> x2 >> y2;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin >> x >> y;
        v.push_back({x,y});
    }
    dfs(0);

    cout << (ll)round(ans);//round() 的返回类型仍然是 double。cout 默认只保留 6 位有效数字，当答案较大时，会丢失精度



   



   


    return 0;
}