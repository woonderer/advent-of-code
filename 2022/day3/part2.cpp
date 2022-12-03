#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string s1, s2, s3;
    int ans = 0;
    while (cin >> s1 >> s2 >> s3)
    {
        bool f = false;
        for (char a: s1)
        {
            for (char b: s2)
            {
                if (a == b)
                {
                    for (char c: s3)
                    {
                        if (a == c)
                        {
                            if ('a' <= a && a <= 'z') ans += a - 'a' + 1;
                            else ans += a - 'A' + 27;
                            f = true;
                            break;
                        }
                    }
                }
                if (f) break;
            }
            if (f) break;
        }
    }
    cout << ans;
}