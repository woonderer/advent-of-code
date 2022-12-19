#include <bits/stdc++.h>
using namespace std;

set <tuple <int, int, int>> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        int x, y, z;
        sscanf(line.c_str(), "%d,%d,%d", &x, &y, &z);
        s.insert({x, y, z});
    }

    int ans = s.size() * 6;
    for (auto x: s)
    {
        if (s.count({get<0>(x) + 1, get<1>(x), get<2>(x)})) ans--;
        if (s.count({get<0>(x) - 1, get<1>(x), get<2>(x)})) ans--;
        if (s.count({get<0>(x), get<1>(x) + 1, get<2>(x)})) ans--;
        if (s.count({get<0>(x), get<1>(x) - 1, get<2>(x)})) ans--;
        if (s.count({get<0>(x), get<1>(x), get<2>(x) + 1})) ans--;
        if (s.count({get<0>(x), get<1>(x), get<2>(x) - 1})) ans--;
    }

    cout << ans;
}