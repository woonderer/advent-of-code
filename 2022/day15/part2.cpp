#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> ranges[4000001];

bool intersection(const pair <int, int>& p1, const pair <int, int>& p2)
{
    return p1.second >= p2.first;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        int x1, x2, y1, y2;
        sscanf(line.c_str(), "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d", &x1, &y1, &x2, &y2);

        int x = abs(x1 - x2) + abs(y1 - y2);
        for (int i = 0; i <= x; i++)
        {
            if (y1 + i <= 4000000) ranges[y1 + i].push_back({(x1 - (x - i) <= 0 ? 0 : x1 - (x - i)), (x1 + (x - i) >= 4000000 ? 4000000: x1 + (x - i))});
            if (i == 0) continue;
            if (y1 - i >= 0) ranges[y1 - i].push_back({(x1 - (x - i) <= 0 ? 0 : x1 - (x - i)), (x1 + (x - i) >= 4000000 ? 4000000 : x1 + (x - i))});
        }
    }

    for (int i = 0; i <= 4000000; i++)
    {
        sort(ranges[i].begin(), ranges[i].end());
        pair <int, int> cur = {0, 0};
        for (auto j: ranges[i])
        {
            if (intersection(cur, j))
                cur.second = max(cur.second, j.second);
            else
            {
                if (cur.second == 0) cout << i;
                else cout << (cur.second + 1) * 1LL * 4000000 + i;
                return 0;
            }
        }
        if (cur.second != 4000000)
        {
            cout << 4000000 * 1LL * 4000000 + i;
            return 0;
        }
    }
}