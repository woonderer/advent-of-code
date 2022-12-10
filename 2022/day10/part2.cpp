#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    int x = 1, cycle = 1, pos = 0;
    vector <vector <char>> ans;
    vector <char> cur;

    while (getline(cin, line))
    {
        if (line[0] != 'n')
        {
            string tmp;
            for (char c: line)
            {
                if (c == ' ') tmp.clear();
                else tmp.push_back(c);
            }
            int n = stoi(tmp);

            cur.push_back((abs(x - pos++) <= 1 ? '#' : '.'));
            if (pos > 39)
            {
                pos = 0;
                ans.push_back(cur);
                cur.clear();
            }
            cycle++;

            cur.push_back((abs(x - pos++) <= 1 ? '#' : '.'));
            if (pos > 39)
            {
                pos = 0;
                ans.push_back(cur);
                cur.clear();
            }
            x += n;
            cycle++;
        }
        else
        {
            cur.push_back((abs(x - pos++) <= 1 ? '#' : '.'));
            if (pos > 39)
            {
                pos = 0;
                ans.push_back(cur);
                cur.clear();
            }
            cycle++;
        }
    }

    for (auto x: ans)
    {
        for (auto i: x)
            cout << i << ' ';
        cout << '\n';
    }
}