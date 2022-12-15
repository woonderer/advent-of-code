#include <bits/stdc++.h>
using namespace std;

set <pair <int, int>> s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        int x1, x2, y1, y2;
        sscanf(line.c_str(), "Sensor at x=%d, y=%d: closest beacon is at x=%d, y=%d", &x1, &y1, &x2, &y2);

        int x = abs(x1 - x2) + abs(y1 - y2) - abs(2000000 - y1);
        if (x >= 0)
        {
            for (int i = 0; i <= x; i++)
            {
                if (!(2000000 == y2 && x1 + i == x2)) s.insert({2000000, x1 + i});
                if (!(2000000 == y2 && x1 - i == x2)) s.insert({2000000, x1 - i});
            }
        }
    }

    cout << s.size();
}