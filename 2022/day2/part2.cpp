#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    int ans = 0;
    for (int _ = 0; _ < 2500; _++)
    {
        char a, b;
        cin >> a >> b;
        if (b == 'X')
        {
            if (a == 'A') ans += 3;
            else if (a == 'B') ans += 1;
            else ans += 2;
        }
        else if (b == 'Y')
        {
            if (a == 'A') ans += 4;
            else if (a == 'B') ans += 5;
            else ans += 6;
        }
        else
        {
            if (a == 'A') ans += 8;
            else if (a == 'B') ans += 9;
            else ans += 7;
        }
    }
    cout << ans;
}