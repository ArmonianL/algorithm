ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }

    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n;
    cin >> n;

    ll x = 0, m1, a1;
    cin >> m1 >> a1;

    for (int i = 0; i < n - 1; i++)
    {
        ll m2, a2;
        cin >> m2 >> a2;

        ll k1, k2;
        ll d = exgcd(m1, m2, k1, k2);

        if ((a2 - a1) % d)
        {
            x = -1;
            break;
        }

        k1 *= (a2 - a1) / d;
        k1 = (k1 % (m2 / d) + m2 / d) % (m2 / d);

        x = k1 * m1 + a1;

        ll m = abs(m1 / d * m2);

        a1 = k1 * m1 + a1;
        m1 = m;
    }

    if (x != -1)
        x = (a1 % m1 + m1) % m1;

    cout << x << endl;

    return 0;
}