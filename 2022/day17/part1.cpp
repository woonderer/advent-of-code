#include <bits/stdc++.h>
using namespace std;

set <pair <int, int>> s;

vector <pair <int, int>> create(int pattern, int cur_max_height)
{
    int h = cur_max_height + 4;
    vector <pair <int, int>> v;
    if (pattern == 0) v = {{h, 3}, {h, 4}, {h, 5}, {h, 6}};
    else if (pattern == 1) v = {{h + 1, 3}, {h, 4}, {h + 1, 4}, {h + 2, 4}, {h + 1, 5}};
    else if (pattern == 2) v = {{h, 3}, {h, 4}, {h, 5}, {h + 1, 5}, {h + 2, 5}};
    else if (pattern == 3) v = {{h, 3}, {h + 1, 3}, {h + 2, 3}, {h + 3, 3}};
    else if (pattern == 4) v = {{h, 3}, {h + 1, 3}, {h, 4}, {h + 1, 4}};
    return v;
}

bool pos(vector <pair <int, int>>& v, const pair <int, int> dir)
{
    if (dir.first == -1)
    {
        for (auto i: v)
            if (i.first - 1 == 0 || s.count({i.first - 1, i.second}))
                return false;
    }
    else if (dir.second == -1)
    {
        for (auto i: v)
            if (i.second - 1 == 0 || s.count({i.first, i.second - 1}))
                return false;
    }
    else if (dir.second == 1)
    {
        for (auto i: v)
            if (i.second + 1 == 8 || s.count({i.first, i.second + 1}))
                return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    cin >> line;

    int i = 0, h = 0; 
    for (int r = 1; r <= 2022; r++)
    {
        vector <pair <int, int>> v = create((r - 1) % 5, h);

        while (true)
        {
            int dir = (line[i % line.size()] == '>' ? 1 : -1);
            i++;
            if (pos(v, {0, dir}))
                for (int x = 0; x < v.size(); x++)
                    v[x].second += dir;

            if (pos(v, {-1, 0}))
            {
                for (int x = 0; x < v.size(); x++)
                    v[x].first--;
            }
            else
            {
                for (int x = 0; x < v.size(); x++)
                {
                    s.insert(v[x]);
                    h = max(h, v[x].first);
                }
                break;
            }
        }
    }
    cout << h;
}