#include <bits/stdc++.h>
using namespace std;

long long SNAFU_to_Decimal(string s)
{
    long long cur = 0, cur_exp = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        switch (s[i])
        {
            case '2':
                cur += 2 * cur_exp;
                break;
            case '1':
                cur += cur_exp;
                break; 
            case '0':
                break;
            case '-':
                cur += cur_exp * -1;
                break;
            case '=':
                cur += cur_exp * -2;
                break;
        }
        cur_exp *= 5;
    }
    return cur;
}

string Decimal_to_SNAFU(long long n)
{
    string ans = "";
    while (n)
    {
        if (n % 5 <= 2) ans.push_back('0' + n % 5);
        else if (n % 5 == 3) 
        {
            ans.push_back('=');
            n += 2;
        }
        else 
        {
            ans.push_back('-');
            n += 1;
        }
        n /= 5;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    long long ans = 0;
    string line;
    while (cin >> line) ans += SNAFU_to_Decimal(line);
    cout << Decimal_to_SNAFU(ans);
}