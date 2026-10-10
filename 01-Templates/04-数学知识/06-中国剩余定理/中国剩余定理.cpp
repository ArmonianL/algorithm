// 中国剩余定理（CRT）：
// 若模数 m1,m2,...,mn 两两互质，则同余方程组
//      x ≡ a1 (mod m1)
//      x ≡ a2 (mod m2)
//      ...
//      x ≡ an (mod mn)
// 在模 M=m1*m2*...*mn 意义下有唯一解。
//
// 令：
//      M=m1*m2*...*mn
//      Mi=M/mi
//      Mi^(-1) 表示 Mi 在模 mi 意义下的逆元，即：
//      Mi*Mi^(-1) ≡ 1 (mod mi)
//
// 则：
//      x ≡ a1*M1*M1^(-1)
//         +a2*M2*M2^(-1)
//         +...
//         +an*Mn*Mn^(-1) (mod M) 这个满足同余方程组的每一项

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL exgcd(LL a,LL b,LL &x,LL &y)
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
    int n;
    cin >> n;

    /*
        当前维护一个合并后的同余方程：

            x ≡ a1 (mod m1)

        一开始先读入第一组：
            x ≡ a1 (mod m1)
    */
    LL x = 0, m1, a1;
    cin >> m1 >> a1;

    // 每次把当前方程和下一条方程合并
    for (int i = 0; i < n - 1; i ++ )
    {
        LL m2, a2;
        cin >> m2 >> a2;

        /*
            当前有两个方程：

                x ≡ a1 (mod m1)
                x ≡ a2 (mod m2)

            第一条可以写成：

                x = k1 * m1 + a1

            第二条可以写成：

                x = k2 * m2 + a2

            因为它们表示的是同一个 x，所以：

                k1*m1 + a1 = k2*m2 + a2

            移项：

                k1*m1 - k2*m2 = a2 - a1

            因此问题变成求解一个线性丢番图方程。
        */

        LL k1, k2;

        /*
            exgcd 求出：

                k1*m1 + k2*m2 = d

            其中：
                d = gcd(m1, m2)

            注意这里虽然是加号，
            但 k2 本身可以是负数，
            所以和上面的减号形式本质相同。
        */
        LL d = exgcd(m1, m2, k1, k2);

        /*
            方程：

                k1*m1 - k2*m2 = a2-a1

            有解的充要条件是：

                gcd(m1,m2) | (a2-a1)

            即：
                (a2-a1) % d == 0

            如果不能整除，说明整个同余方程组无解。
        */
        if ((a2 - a1) % d)
        {
            x = -1;
            break;
        }

        /*
            原来 exgcd 得到：

                k1*m1 + k2*m2 = d

            两边乘：

                (a2-a1)/d

            得：

                k1*m1 + k2*m2 = a2-a1

            所以要把 k1 乘上这个倍数。
        */
        k1 *= (a2 - a1) / d;

        /*
            k1 的所有解为：

                k1 = k1_0 + t * (m2/d)

            因此可以把 k1 取到：

                [0, m2/d)

            范围内。

            C++ 中负数 % 正数可能为负，
            所以写成：

                (k1 % mod + mod) % mod

            保证最终非负。
        */
        k1 = (k1 % (m2 / d) + m2 / d) % (m2 / d);

        /*
            根据：

                x = k1*m1 + a1

            得到当前两个同余方程的一个解。
        */
        x = k1 * m1 + a1;

        /*
            合并后的新模数是：

                lcm(m1, m2)

            即：

                m1 / gcd(m1,m2) * m2
        */
        LL m = abs(m1 / d * m2);

        /*
            合并：

                x ≡ a1 (mod m1)
                x ≡ a2 (mod m2)

            得到新的一个同余方程：

                x ≡ 新a1 (mod 新m1)

            其中：

                新a1 = k1*m1 + a1
                新m1 = lcm(m1,m2)
        */
        a1 = k1 * m1 + a1;
        m1 = m;
    }

    /*
        如果没有出现无解情况，
        最后将答案调整到最小非负整数范围：

            0 <= x < m1

        即：
            x = a1 mod m1

        因为 C++ 取模可能得到负数，
        所以再加一次 m1 后取模。
    */
    if (x != -1)
        x = (a1 % m1 + m1) % m1;

    /*
        如果有解：
            输出最小非负整数解

        如果无解：
            输出 -1
    */
    cout << x << endl;

    return 0;
}