// 线性同余方程：a * x ≡ b (mod m)
//
// 等价于：a * x + m * y = b
// 设 d = gcd(a, m)
//
// exgcd 可求出：a * x0 + m * y0 = d
//
// 若 b % d != 0，则无解
//
// 若 d | b，两边同乘 b / d：
// a * (x0 * b / d) + m * (y0 * b / d) = b
//
// 所以：x = x0 * b / d 是一个特解
ll a,b,m;

int exgcd(int a,int b,int &x,int &y)
{
    if(b==0) 
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a >> b >> m;
        int x,y;
        int d=exgcd(a,m,x,y);//这里不是a和b！！！
        if(b%d!=0) cout << "impossible\n";
        else cout << (ll)x*b/d%m << '\n';
        // exgcd 求出 ax + my = d 的一个特解 x
        // 两边乘 b / d 后，可得原同余方程
        //      aX ≡ b (mod m)
        // 的一个解 X = b / d * x
        //
        // 由于同余方程的解相差 m 仍然是解：
        //      a(X + km) ≡ aX ≡ b (mod m)
        // 所以最后对 m 取模，可以把答案缩小到一个较小的等价解。
        // 注意：真正的解周期其实是 m / d，% m 也不会影响正确性。
    }

    return 0;
}