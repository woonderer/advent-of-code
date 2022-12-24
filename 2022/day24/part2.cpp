#include <bits/stdc++.h>
using namespace std;

struct blizzard
{
    int row, col;
    char dir;
};
vector <blizzard> blizzards;
int n = 0, m;

vector <blizzard> move()
{
    vector <blizzard> ans;
    for (auto x: blizzards)
    {
        if (x.dir == '>')
        {
            if (x.col + 1 < m) ans.push_back({x.row, x.col + 1, x.dir});
            else ans.push_back({x.row, 2, x.dir});
        }
        else if (x.dir == '<')
        {
            if (x.col - 1 > 1) ans.push_back({x.row, x.col - 1, x.dir});
            else ans.push_back({x.row, m - 1, x.dir});
        }
        else if (x.dir == '^')
        {
            if (x.row - 1 > 1) ans.push_back({x.row - 1, x.col, x.dir});
            else ans.push_back({n - 1, x.col, x.dir});
        }
        else if (x.dir == 'v')
        {
            if (x.row + 1 < n) ans.push_back({x.row + 1, x.col, x.dir});
            else ans.push_back({2, x.col, x.dir});
        }
    }
    return ans;
}

bool find_blizz(int i, int j)
{
    for (auto x: blizzards)
        if (x.row == i && x.col == j)
            return true;
    return false;
}

int solve(pair <int, int> start, pair <int, int> end)
{
    int ans = 0;
    set <pair <int, int>> pos = {start}, tmp;
    while (true)
    {
        ans++;
        blizzards = move();
        for (auto x: pos)
        {
            if (end == make_pair(n, m - 1) && x.first == n - 1 && x.second == m - 1) return ans;
            if (end == make_pair(1, 2) && x.first == 2 && x.second == 2) return ans;

            if (start == make_pair(1, 2) && x.first == 1 && x.second == 2)
            {
                tmp.insert(x);
                if (x.first + 1 < n && !find_blizz(x.first + 1, x.second)) tmp.insert({x.first + 1, x.second});
                continue;
            }
            if (start == make_pair(n, m - 1) && x.first == n && x.second == m - 1)
            {
                tmp.insert(x);
                if (x.first - 1 > 1 && !find_blizz(x.first - 1, x.second)) tmp.insert({x.first - 1, x.second});
                continue;
            }

            if (!find_blizz(x.first, x.second)) tmp.insert(x);
            if (x.first - 1 > 1 && !find_blizz(x.first - 1, x.second)) tmp.insert({x.first - 1, x.second});
            if (x.first + 1 < n && !find_blizz(x.first + 1, x.second)) tmp.insert({x.first + 1, x.second});
            if (x.second - 1 > 1 && !find_blizz(x.first, x.second - 1)) tmp.insert({x.first, x.second - 1});
            if (x.second + 1 < m && !find_blizz(x.first, x.second + 1)) tmp.insert({x.first, x.second + 1});
        }

        pos = tmp;
        tmp.clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        ++n;
        for (int i = 0; i < line.size(); i++)
            if (line[i] != '.' && line[i] != '#') blizzards.push_back({n, i + 1, line[i]});
    }
    m = line.size();
    
    cout << solve({1, 2}, {n, m - 1}) + solve({n, m - 1}, {1, 2}) + solve({1, 2}, {n, m - 1});
}