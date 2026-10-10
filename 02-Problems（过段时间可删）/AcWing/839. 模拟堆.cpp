#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =100010;
int n;
int h[N],sz;
int k;
int ph[N],hp[N];

void hswap(int a,int b)
{
    int ka=hp[a];
    int kb=hp[b];
    ph[ka]=b;
    ph[kb]=a;
    hp[a]=kb;
    hp[b]=ka;
    swap(h[a],h[b]);
}

void init()
{
    
}

void up(int p)
{
    while(p>1 && h[p/2]>h[p])
    {
        hswap(p/2,p);
        p=p/2;
    }
}

void down(int p)
{
    while(true)
    {
        int t=p;
        if(p*2<=sz && h[p*2]<h[t]) t=p*2;
        if(p*2+1<=sz && h[p*2+1]<h[t]) t=p*2+1;
        
        if(t==p) break;
        else 
        {
            hswap(p,t);
            p=t;
        }
    }
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;init();
    for(int i=1;i<=n;i++)
    {
        string s;cin >> s;
        if(s=="I")
        {
            int x;cin >> x;
            h[++sz]=x;
            ph[++k]=sz;
            hp[sz]=k;
            up(sz);
        }
        else if(s=="PM")
        {
            cout << h[1] << '\n';
        }
        else if(s=="DM")
        {
            hswap(1,sz);
            sz--;
            down(1);
        }
        else if(s=="D")
        {
            int k;cin >> k;
            
            int idx=ph[k];
            hswap(idx,sz);
            sz--;
            up(idx);down(idx);
           
            
        }
        else if(s=="C")
        {
            int k,x;cin >> k >> x;
            int idx=ph[k];
            h[idx]=x;
            up(idx);down(idx);
        }
    }


    return 0;
}