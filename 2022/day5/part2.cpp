#include <bits/stdc++.h>
using namespace std;

stack <char> s[10];
string crates[9];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;

    for (int i = 1; i <= 8; i++)
    {
        getline(cin, line);
        crates[i] = line;
    }

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 8; j >= 1; j--)
        {
            if (crates[j][1 + 4 * (i - 1)] != ' ')
            {
                s[i].push(crates[j][1 + 4 * (i - 1)]);
            }
            else break;
        }
    }

    getline(cin, line);
    getline(cin, line);

    while (getline(cin, line))
    {
        int move, from, to;
        sscanf(line.c_str(), "move %d from %d to %d", &move, &from, &to);
        while (move--)
        {
            s[0].push(s[from].top()); // s[0] -> unused stack | evolves into temporary stack for data :D
            s[from].pop();
        }

        while (!s[0].empty())
        {
            s[to].push(s[0].top());
            s[0].pop();
        }
    }

    for (int i = 1; i <= 9; i++)
        cout << s[i].top();
}