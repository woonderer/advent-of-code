#include <bits/stdc++.h>
using namespace std;

pair <int, int> eh(string s)
{
    return make_pair(stoi(s.substr(0, s.find('-'))), stoi(s.substr(s.find('-') + 1)));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    int ans = 0;
    string line;
    while (getline(cin, line))
    {
        pair <int, int> a = eh(line.substr(0, line.find(','))), b = eh(line.substr(line.find(',') + 1));
        if (a.first > b.first || (a.first == b.first && a.second < b.second)) swap(a, b);
        if (a.second >= b.first) ans++;
    }
    cout << ans;
}