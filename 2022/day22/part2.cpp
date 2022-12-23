// Z dedykacją dla Macieja
#include <bits/stdc++.h>
using namespace std;

int cubes[7][55][55];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    for (int i = 1; i <= 50; i++)
    {
        getline(cin, line);

        for (int j = 51; j <= 100; j++)
            cubes[2][i][j - 50] = line[j - 1] == '.' ? 0 : 1;
        
        for (int j = 101; j <= 150; j++)
            cubes[3][i][j - 100] = line[j - 1] == '.' ? 0 : 1;
    }
    for (int i = 1; i <= 50; i++)
    {
        getline(cin, line);

        for (int j = 51; j <= 100; j++)
            cubes[1][i][j - 50] = line[j - 1] == '.' ? 0 : 1;
    }
    for (int i = 1; i <= 50; i++)
    {
        getline(cin, line);

        for (int j = 1; j <= 50; j++)
            cubes[5][i][j] = line[j - 1] == '.' ? 0 : 1;
        
        for (int j = 51; j <= 100; j++)
            cubes[4][i][j - 50] = line[j - 1] == '.' ? 0 : 1;
    }
    for (int i = 1; i <= 50; i++)
    {
        getline(cin, line);

        for (int j = 1; j <= 50; j++)
            cubes[6][i][j] = line[j - 1] == '.' ? 0 : 1;
    }
    getline(cin, line);
    getline(cin, line);
    
    bool num = true;
    int i = 0, cube = 2, dir = 0;
    pair <int, int> cur = {1, 1};
    while (i < line.size())
    {
        if (num)
        {
            string number = "";
            while (i < line.size() && line[i] >= '0' && line[i] <= '9') 
                number.push_back(line[i++]);

            int n = stoi(number);
            while (n--)
            {
                if (dir == 0)
                {
                    if (cur.second + 1 <= 50)
                    {
                        if (cubes[cube][cur.first][cur.second + 1] == 0) cur.second++;
                    }
                    else
                    {
                        if (cube == 1 && cubes[3][50][cur.first] == 0)
                        {
                            cube = 3;
                            cur = {50, cur.first};
                            dir = 3;
                        }
                        else if (cube == 2 && cubes[3][cur.first][1] == 0)
                        {
                            cube = 3;
                            cur = {cur.first, 1};
                            dir = 0;
                        }
                        else if (cube == 3 && cubes[4][50 - cur.first + 1][50] == 0)
                        {
                            cube = 4;
                            cur = {50 - cur.first + 1, 50};
                            dir = 2;
                        }
                        else if (cube == 4 && cubes[3][50 - cur.first + 1][50] == 0)
                        {
                            cube = 3;
                            cur = {50 - cur.first + 1, 50};
                            dir = 2;
                        }
                        else if (cube == 5 && cubes[4][cur.first][1] == 0)
                        {
                            cube = 4;
                            cur = {cur.first, 1};
                            dir = 0;
                        }
                        else if (cube == 6 && cubes[4][50][cur.first] == 0)
                        {
                            cube = 4;
                            cur = {50, cur.first};
                            dir = 3;
                        }
                    }
                }
                else if (dir == 1)
                {
                    if (cur.first + 1 <= 50)
                    {
                        if (cubes[cube][cur.first + 1][cur.second] == 0) cur.first++;
                    }
                    else
                    {
                        if (cube == 1 && cubes[4][1][cur.second] == 0)
                        {
                            cube = 4;
                            cur = {1, cur.second};
                            dir = 1;
                        }
                        else if (cube == 2 && cubes[1][1][cur.second] == 0)
                        {
                            cube = 1;
                            cur = {1, cur.second};
                            dir = 1;
                        }
                        else if (cube == 3 && cubes[1][cur.second][50] == 0)
                        {
                            cube = 1;
                            cur = {cur.second, 50};
                            dir = 2;
                        }
                        else if (cube == 4 && cubes[6][cur.second][50] == 0)
                        {
                            cube = 6;
                            cur = {cur.second, 50};
                            dir = 2;
                        }
                        else if (cube == 5 && cubes[6][1][cur.second] == 0)
                        {
                            cube = 6;
                            cur = {1, cur.second};
                            dir = 1;
                        }
                        else if (cube == 6 && cubes[3][1][cur.second] == 0)
                        {
                            cube = 3;
                            cur = {1, cur.second};
                            dir = 1;
                        }
                    }
                }
                else if (dir == 2)
                {
                    if (cur.second - 1 >= 1)
                    {
                        if (cubes[cube][cur.first][cur.second - 1] == 0) cur.second--;
                    }
                    else
                    {
                        if (cube == 1 && cubes[5][1][cur.first] == 0)
                        {
                            cube = 5;
                            cur = {1, cur.first};
                            dir = 1;
                        }
                        else if (cube == 2 && cubes[5][50 - cur.first + 1][1] == 0)
                        {
                            cube = 5;
                            cur = {50 - cur.first + 1, 1};
                            dir = 0;
                        }
                        else if (cube == 3 && cubes[2][cur.first][50] == 0)
                        {
                            cube = 2;
                            cur = {cur.first, 50};
                            dir = 2;
                        }
                        else if (cube == 4 && cubes[5][cur.first][50] == 0)
                        {
                            cube = 5;
                            cur = {cur.first, 50};
                            dir = 2;
                        }
                        else if (cube == 5 && cubes[2][50 - cur.first + 1][1] == 0)
                        {
                            cube = 2;
                            cur = {50 - cur.first + 1, 1};
                            dir = 0;
                        }
                        else if (cube == 6 && cubes[2][1][cur.first] == 0)
                        {
                            cube = 2;
                            cur = {1, cur.first};
                            dir = 1;
                        }
                    }
                }
                else if (dir == 3)
                {
                    if (cur.first - 1 >= 1)
                    {
                        if (cubes[cube][cur.first - 1][cur.second] == 0) cur.first--;
                    }
                    else
                    {
                        if (cube == 1 && cubes[2][50][cur.second] == 0)
                        {
                            cube = 2;
                            cur = {50, cur.second};
                            dir = 3;
                        }
                        else if (cube == 2 && cubes[6][cur.second][1] == 0)
                        {
                            cube = 6;
                            cur = {cur.second, 1};
                            dir = 0;
                        }
                        else if (cube == 3 && cubes[6][50][cur.second] == 0)
                        {
                            cube = 6;
                            cur = {50, cur.second};
                            dir = 3;
                        }
                        else if (cube == 4 && cubes[1][50][cur.second] == 0)
                        {
                            cube = 1;
                            cur = {50, cur.second};
                            dir = 3;
                        }
                        else if (cube == 5 && cubes[1][cur.second][1] == 0)
                        {
                            cube = 1;
                            cur = {cur.second, 1};
                            dir = 0;
                        }
                        else if (cube == 6 && cubes[5][50][cur.second] == 0)
                        {
                            cube = 5;
                            cur = {50, cur.second};
                            dir = 3;
                        }
                    }
                }
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

    int row = cur.first, col = cur.second;
    switch (cube)
    {
        case 1:
            row += 50;
            col += 50;
            break;
        case 2:
            col += 50;
            break;
        case 3:
            col += 100;
            break;
        case 4:
            row += 100;
            col == 50;
            break;
        case 5:
            row += 100;
            break;
        case 6:
            row += 150;
            break;
    }
    cout << 1000 * row + 4 * col + dir;
}