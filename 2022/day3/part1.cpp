#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string s;
    int ans = 0;
    while (cin >> s)
    {
        string s1 = s.substr(0, s.size() / 2), s2 = s.substr(s.size() / 2);
        bool f = false;
        for (char a: s1)
        {
            for (char b: s2)
            {
                if (a == b)
                {
                    if ('a' <= a && a <= 'z') ans += a - 'a' + 1;
                    else ans += a - 'A' + 27;
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
    }
    cout << ans;
}