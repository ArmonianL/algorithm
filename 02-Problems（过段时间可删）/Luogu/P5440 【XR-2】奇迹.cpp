#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e8;

int t;
string s;
vector<int> res;

int big[] = {1, 3, 5, 7, 8, 10, 12};

bool prime[N + 1];

void sieve()
{
    memset(prime, true, sizeof prime);

    prime[0] = prime[1] = false;

    for (int i = 2; i <= N / i; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

/*
    检查 MMDD 是否可能是合法月日。

    因为此时年份还没有构造出来，
    所以二月暂时允许到 29 日。
*/
bool checkMonthDay(int mmdd)
{
    int month = mmdd / 100;
    int day = mmdd % 100;

    if (month < 1 || month > 12)
    {
        return false;
    }

    if (day < 1)
    {
        return false;
    }

    if (month == 2)
    {
        return day <= 29;
    }

    bool tag = false;

    for (int x : big)
    {
        if (month == x)
        {
            tag = true;
            break;
        }
    }

    if (tag)
    {
        return day <= 31;
    }

    return day <= 30;
}

bool check(int date)
{
    bool run = false;

    int year = date / 10000;
    int month = date / 100 - year * 100;
    int day = date - month * 100 - year * 10000;

    if (!(year >= 1 && year <= 9999))
    {
        return false;
    }

    if (!(month >= 1 && month <= 12))
    {
        return false;
    }

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        run = true;
    }

    if (month == 2)
    {
        if (run)
        {
            if (!(day >= 1 && day <= 29))
            {
                return false;
            }
        }
        else if (!(day >= 1 && day <= 28))
        {
            return false;
        }
    }
    else
    {
        bool tag = false;

        for (int x : big)
        {
            if (month == x)
            {
                tag = true;
                break;
            }
        }

        if (tag)
        {
            if (!(day >= 1 && day <= 31))
            {
                return false;
            }
        }
        else if (!(day >= 1 && day <= 30))
        {
            return false;
        }
    }

    return true;
}

void dfs(int u, int sum, int cnt)
{
    if (u == -1)
    {
        if (check(sum))
        {
            res.push_back(sum);
        }

        return;
    }

    if (s[u] == '-')
    {
        for (int i = 0; i <= 9; i++)
        {
            sum += i * pow(10, cnt);
            cnt++;

            if (cnt == 2 || cnt == 4 || cnt == 8)
            {
                if (!prime[sum])
                {
                    cnt--;
                    sum -= i * pow(10, cnt);
                    continue;
                }
            }

            // 只增加这一处：构造出 MMDD 后检查月日是否合法
            if (cnt == 4 && !checkMonthDay(sum))
            {
                cnt--;
                sum -= i * pow(10, cnt);
                continue;
            }

            dfs(u - 1, sum, cnt);

            cnt--;
            sum -= i * pow(10, cnt);
        }
    }
    else
    {
        sum += (s[u] - '0') * pow(10, cnt);
        cnt++;

        if (cnt == 2 || cnt == 4 || cnt == 8)
        {
            if (!prime[sum])
            {
                return;
            }
        }

        // 只增加这一处：构造出 MMDD 后检查月日是否合法
        if (cnt == 4 && !checkMonthDay(sum))
        {
            return;
        }

        dfs(u - 1, sum, cnt);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    sieve();

    cin >> t;

    while (t--)
    {
        res.clear();

        cin >> s;

        dfs(7, 0, 0);

        cout << res.size() << '\n';
    }

    return 0;
}