#include <bits/stdc++.h>
using namespace std;

set <pair <int, int>> pos;
vector <pair <int, int>> dir[4];
vector <pair <pair <int, int>, pair <int, int>>> propose;
int prio = 0; // 0 -> NORTH  1 -> SOUTH  2 -> WEST  3 -> EAST

pair <int, int> add_pairs(pair <int, int> p1, pair <int, int> p2)
{
    return {p1.first + p2.first, p1.second + p2.second};
}

bool good(pair <int, int> p, int direction)
{
    for (auto x: dir[direction])
        if (pos.count({add_pairs(p, x)}))
            return false;
    return true;
}

bool is_open(pair <int, int> p)
{
    for (int i = p.first - 1; i <= p.first + 1; i++)
    {
        for (int j = p.second - 1; j <= p.second + 1; j++)
        {
            if (i == p.first && j == p.second) continue;

            if (pos.count({i, j}))
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    int i = 0;
    string line;
    while (getline(cin, line))
    {
        for (int j = 0; j < line.size(); j++)
            if (line[j] == '#')
                pos.insert({i, j});
        i++;
    }

    dir[0] = {{-1, -1}, {-1, 0}, {-1, 1}};
    dir[1] = {{1, -1}, {1, 0}, {1, 1}};
    dir[2] = {{-1, -1}, {0, -1}, {1, -1}};
    dir[3] = {{-1, 1}, {0, 1}, {1, 1}};

    int rounds = 10;
    while (rounds--)
    {
        for (auto x: pos)
        {
            if (is_open(x))
            {
                propose.push_back({x, x});
            }
            else
            {
                for (int j = 0; j < 4; j++)
                {
                    if (good(x, (prio + j) % 4))
                    {
                        switch ((prio + j) % 4)
                        {
                            case 0:
                                propose.push_back({add_pairs(x, {-1, 0}), x});
                                break;
                            case 1:
                                propose.push_back({add_pairs(x, {1, 0}), x});
                                break;
                            case 2:
                                propose.push_back({add_pairs(x, {0, -1}), x});
                                break;
                            case 3:
                                propose.push_back({add_pairs(x, {0, 1}), x});
                                break;
                        }
                        break;
                    }
                    if (j == 3) propose.push_back({x, x});
                }
            }
        }

        sort(propose.begin(), propose.end());
        i = 0;
        pos.clear();
        while (i < propose.size())
        {
            if (i + 1 < propose.size())
            {
                if (propose[i].first != propose[i + 1].first)
                    pos.insert(propose[i++].first);
                else
                {
                    int j = i;
                    while (j < propose.size())
                    {
                        pos.insert(propose[j].second);
                        if (j + 1 < propose.size())
                        {
                            if (propose[j].first == propose[j + 1].first) 
                                j++;
                            else break;
                        }
                        else break;
                    }
                    i = j + 1;
                }
            }
            else 
            {
                pos.insert(propose[i++].first);
            }
        }
        propose.clear();
        prio = (prio + 1) % 4;
    }

    int minx = 1e9, maxx = -1e9, miny = 1e9, maxy = -1e9;
    for (auto x: pos)
    {
        cout << x.first << ' ' << x.second << '\n';
        minx = min(minx, x.second);
        maxx = max(maxx, x.second);
        miny = min(miny, x.first);
        maxy = max(maxy, x.first);
    }
    cout << maxy << ' ' << miny << ' ' << maxx << ' ' << minx << '\n';
    cout << (maxy - miny + 1) * (maxx - minx + 1) - pos.size();
}