#include <bits/stdc++.h>
using namespace std;

int g[205][205];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    for (int i = 0; i < 205; i++)
        for (int j = 0; j < 205; j++)
            g[i][j] = -1;

    string line;
    int i = 1;
    pair <int, int> cur;
    while (getline(cin, line))
    {
        if (line == "") break;
        if (i == 1) cur = {1, line.find('.') + 1};

        for (int j = 0; j < line.size(); j++)
        {
            if (line[j] == '.') g[i][j + 1] = 0;
            else if (line[j] == '#') g[i][j + 1] = 1;
        }
        i++;
    }

    cin >> line;

    int dir = 0;
    bool num = true;
    i = 0;
    while (i < line.size())
    {
        if (num)
        {
            string number = "";
            while (line[i] >= '0' && line[i] <= '9') 
                number.push_back(line[i++]);

            bool blocked = false;
            int n = stoi(number);
            while (n--)
            {
                if (dir == 0)
                {
                    if (g[cur.first][cur.second + 1] == 0) cur.second++;
                    else if (g[cur.first][cur.second + 1] == -1)
                    {
                        int other_side = 1;
                        while (g[cur.first][other_side] == -1) other_side++;

                        if (g[cur.first][other_side] == 0) cur.second = other_side;
                        else blocked = true;
                    }
                    else blocked = true;
                }
                else if (dir == 1)
                {
                    if (g[cur.first + 1][cur.second] == 0) cur.first++;
                    else if (g[cur.first + 1][cur.second] == -1)
                    {
                        int other_side = 1;
                        while (g[other_side][cur.second] == -1) other_side++;

                        if (g[other_side][cur.second] == 0) cur.first = other_side;
                        else blocked = true;
                    }
                    else blocked = true;
                }
                else if (dir == 2)
                {
                    if (g[cur.first][cur.second - 1] == 0) cur.second--;
                    else if (g[cur.first][cur.second - 1] == -1)
                    {
                        int other_side = 200;
                        while (g[cur.first][other_side] == -1) other_side--;

                        if (g[cur.first][other_side] == 0) cur.second = other_side;
                        else blocked = true;
                    }
                    else blocked = true;
                }
                else if (dir == 3)
                {
                    if (g[cur.first - 1][cur.second] == 0) cur.first--;
                    else if (g[cur.first - 1][cur.second] == -1)
                    {
                        int other_side = 200;
                        while (g[other_side][cur.second] == -1) other_side--;

                        if (g[other_side][cur.second] == 0) cur.first = other_side;
                        else blocked = true;
                    }
                    else blocked = true;
                }
                if (blocked) break;
            }
            
            num = false;
        }
        else
        {
            if (line[i++] == 'L')
                dir = dir - 1 >= 0 ? dir - 1 : 3;
            else
                dir = dir + 1 <= 3 ? dir + 1 : 0;
            num = true;
        }
    }

    cout << 1000 * cur.first + 4 * cur.second + dir;
}