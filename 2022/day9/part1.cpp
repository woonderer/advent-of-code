#include <bits/stdc++.h>
using namespace std;

pair <int, int> rope[2];
set <pair <int, int>> s;

bool is_adj(int n)
{
    return abs(rope[n].first - rope[n - 1].first) <= 1 && abs(rope[n].second - rope[n - 1].second) <= 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        char dir;
        int m;
        sscanf(line.c_str(), "%c %d", &dir, &m);

        if (dir == 'R')
        {
            while (m--)
            {
                rope[0].second++;
                if (!is_adj(1))
                {
                    if (rope[0].second > rope[1].second) rope[1].second++;
                    else if (rope[0].second < rope[1].second) rope[1].second--;

                    if (rope[0].first > rope[1].first) rope[1].first++;
                    else if (rope[0].first < rope[1].first) rope[1].first--;
                }
                s.insert(rope[1]);
            }
        }
        else if (dir == 'L')
        {
            while (m--)
            {
                rope[0].second--;
                if (!is_adj(1))
                {
                    if (rope[0].second > rope[1].second) rope[1].second++;
                    else if (rope[0].second < rope[1].second) rope[1].second--;

                    if (rope[0].first > rope[1].first) rope[1].first++;
                    else if (rope[0].first < rope[1].first) rope[1].first--;
                }
                s.insert(rope[1]);
            }
        }
        else if (dir == 'U')
        {
            while (m--)
            {
                rope[0].first--;
                if (!is_adj(1))
                {
                    if (rope[0].first > rope[1].first) rope[1].first++;
                    else if (rope[0].first < rope[1].first) rope[1].first--;

                    if (rope[0].second > rope[1].second) rope[1].second++;
                    else if (rope[0].second < rope[1].second) rope[1].second--;
                }
                s.insert(rope[1]);
            }
        }
        else if (dir == 'D')
        {
            while (m--)
            {
                rope[0].first++;
                if (!is_adj(1))
                {
                    if (rope[0].first > rope[1].first) rope[1].first++;
                    else if (rope[0].first < rope[1].first) rope[1].first--;

                    if (rope[0].second > rope[1].second) rope[1].second++;
                    else if (rope[0].second < rope[1].second) rope[1].second--;
                }
                s.insert(rope[1]);
            }
        }
    }
    cout << s.size();
}