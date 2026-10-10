#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N =1e6+3;
double a,b,c,d;
double f(double x)
{
    return a*pow(x,3)+b*pow(x,2)+c*x+d;
} 

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b >> c >> d;
    int k=0;
    for(int i=-100;i<=99;i++)
    {
        if(k==3) break;
        if(f(i)==0)
        {
            k++;
            cout << fixed << setprecision(2) << (double)i << ' ';
            continue;
        }
       if(f(i)*f(i+1)<0)
       {
        double l=i,r=i+1;
        while(r-l>1e-8)
        {
            double mid=(l+r)/2;
            if(f(l)*f(mid)<=0) r=mid;
            else l=mid;
        }
        cout << fixed << setprecision(2) << l << ' ';
       }
    }


    return 0;
}