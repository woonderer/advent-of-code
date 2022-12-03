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
            ans += 1;
            if (a == 'A') ans += 3;
            else if (a == 'C') ans += 6;
        }
        else if (b == 'Y')
        {
            ans += 2;
            if (a == 'B') ans += 3;
            else if (a == 'A') ans += 6;
        }
        else 
        {
            ans += 3;
            if (a == 'C') ans += 3;
            else if (a == 'B') ans += 6;
        }
    }
    cout << ans;
}