// 浮点数二分：O(log((R-L)/eps))
// 保留k为小数，eps=10^-(k+2)

//求三次方根
double l=-10000,r=10000;
while(r-l>1e-8)
{
    double mid=(l+r)/2;
    if(mid*mid*mid<=x) l=mid;
    else r=mid;
}
cout << fixed << setprecision(6) << l;