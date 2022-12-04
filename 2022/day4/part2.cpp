#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    int ans = 0;
    string line;
    while (getline(cin, line))
    {
        pair <int, int> a, b;
        sscanf(line.c_str(), "%d-%d,%d-%d", &a.first, &a.second, &b.first, &b.second);
        if (a.first > b.first || (a.first == b.first && a.second < b.second)) swap(a, b);
        if (a.second >= b.first) ans++;
    }
    cout << ans;
}