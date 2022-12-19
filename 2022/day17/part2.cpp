#include <bits/stdc++.h>
using namespace std;

set <pair <long long, int>> s;
set <tuple <vector <long long>, int, int>> c;
map <tuple <vector <long long>, int, int>, int> start;
vector <long long> height(8, 0), high = {0};

vector <pair <long long, int>> create(int pattern, long long cur_max_height)
{
    int h = cur_max_height + 4;
    vector <pair <long long, int>> v;
    if (pattern == 0) v = {{h, 3}, {h, 4}, {h, 5}, {h, 6}};
    else if (pattern == 1) v = {{h + 1, 3}, {h, 4}, {h + 1, 4}, {h + 2, 4}, {h + 1, 5}};
    else if (pattern == 2) v = {{h, 3}, {h, 4}, {h, 5}, {h + 1, 5}, {h + 2, 5}};
    else if (pattern == 3) v = {{h, 3}, {h + 1, 3}, {h + 2, 3}, {h + 3, 3}};
    else if (pattern == 4) v = {{h, 3}, {h + 1, 3}, {h, 4}, {h + 1, 4}};
    return v;
}

bool pos(vector <pair <long long, int>>& v, const pair <int, int> dir)
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

    int dir;
    long long i = 0, h = 0, ans = 0; 
    for (long long r = 1; r <= 1000000000000; r++)
    {
        vector <pair <long long, int>> v = create((r - 1) % 5, h);

        while (true)
        {
            dir = (line[i % line.size()] == '>' ? 1 : -1);
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
                    height[v[x].second] = max(height[v[x].second], v[x].first);
                }
                high.push_back(h);
                break;
            }
        }

        vector <long long> tmp(7);
        for (int i = 1; i <= 7; i++)
            tmp[i - 1] = h - height[i];
        if (c.count({tmp, dir, (i - 1) % line.size()}) && (1000000000000 - start[{tmp, dir, (i - 1) % line.size()}] + 1) % (r - start[{tmp, dir, (i - 1) % line.size()}]) == 0)
        {
            cout << start[{tmp, dir, (i - 1) % line.size()}] << ' ' << r << '\n';
            cout << (1000000000000 - start[{tmp, dir, (i - 1) % line.size()}] + 1) / (r - start[{tmp, dir, (i - 1) % line.size()}]) * (high[r - 1] - high[start[{tmp, dir, (i - 1) % line.size()}] - 1]) + high[start[{tmp, dir, (i - 1) % line.size()}] - 1];
            break;
        }
        else
        {
            c.insert({tmp, dir, (i - 1) % line.size()});
            start[{tmp, dir, (i - 1) % line.size()}] = r;
        }
    }
}