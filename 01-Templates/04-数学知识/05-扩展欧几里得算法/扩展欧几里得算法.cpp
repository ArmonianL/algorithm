// 裴蜀定理：对整数 a,b（不同时为0），存在整数 x,y，使 ax+by=gcd(a,b)； 
// 且所有形如 ax+by 的整数恰好都是 gcd(a,b) 的倍数。 
// 特别地，gcd(a,b)=1 ⇔ 存在整数 x,y，使 ax+by=1。 
int exgcd(int a,int b,int &x,int &y)//返回gcd，并求出x和y
{ 
    // 递归终点：a*1+0*0=a=gcd(a,0)
    if(b==0) 
    { 
        x=1,y=0; 
        return a; 
    } 
 
    // 递归后：b*y+(a%b)*x=d
    int d=exgcd(b,a%b,y,x); 

    // a%b=a-(a/b)*b
    // b*y+(a%b)*x=d
    // => b*y+[a-(a/b)*b]*x=d
    // => a*x+b*(y-a/b*x)=d
    // 所以 y 要更新为 y-a/b*x
    y-=a/b*x; 

    return d; 
} 
 
int main() 
{ 
    cin >> n; 
    for(int i=1;i<=n;i++) 
    { 
        cin >> a >> b; 
        int x,y; 
        exgcd(a,b,x,y); 
        cout << x << ' ' << y << '\n'; 
    }     

    return 0; 
}
