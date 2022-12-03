#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string s;
    int ans = 0, cur = 0;
    for (int _ = 0; _ < 2262; _++)
    {
        getline(cin, s);
        if (s.size() == 0)
        {
            ans = max(ans, cur);
            cur = 0;
        }
        else cur += stoi(s);
    }
    ans = max(ans, cur);

    cout << ans;
}