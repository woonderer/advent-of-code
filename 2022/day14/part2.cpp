#include <bits/stdc++.h>
using namespace std;

set <pair <int, int>> s;
int max_depth = 0;

bool fall()
{
    pair <int, int> pos = {0, 500};
    while (1)
    {
        if (pos.first == max_depth - 1)
        {
            s.insert(pos);
            return true;
        }

        if (s.count({pos.first + 1, pos.second}))
        {
            if (s.count({pos.first + 1, pos.second - 1}))
            {
                if (s.count({pos.first + 1, pos.second + 1}))
                {
                    if (pos.first == 0 && pos.second == 500) return false;

                    s.insert(pos);
                    return true;
                }
                else
                {
                    pos.first++;
                    pos.second++;
                }
            }
            else
            {
                pos.first++;
                pos.second--;
            }
        }
        else
        {
            pos.first++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        vector <pair <int, int>> v;

        string delimiter = " -> ";
        size_t pos = 0;
        string token;
        while ((pos = line.find(delimiter)) != string::npos) {
            token = line.substr(0, pos);
            v.push_back({stoi(token.substr(0, token.find(','))), stoi(token.substr(token.find(',') + 1))});
            line.erase(0, pos + delimiter.length());
        }
        v.push_back({stoi(line.substr(0, line.find(','))), stoi(line.substr(line.find(',') + 1))});

        pair <int, int> cur = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (cur.first == v[i].first)
            {
                for (int j = min(cur.second, v[i].second); j <= max(cur.second, v[i].second); j++)
                {
                    s.insert({j, cur.first});
                }
                cur = v[i];
            }
            else
            {
                for (int j = min(cur.first, v[i].first); j <= max(cur.first, v[i].first); j++)
                {
                    s.insert({cur.second, j});
                }
                cur = v[i];
            }
            max_depth = max(max_depth, cur.second + 2);
        }
    }

    int ans = 0;
    while (fall()) ans++;
    cout << ans + 1;
}