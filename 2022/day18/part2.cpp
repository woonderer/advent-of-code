#include <bits/stdc++.h>
using namespace std;

bool cubes[30][30][30], used[30][30][30];
struct cube
{
    int x, y, z;
};


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        int x, y, z;
        sscanf(line.c_str(), "%d,%d,%d", &x, &y, &z);
        cubes[x][y][z] = true;
        used[x][y][z] = true;
    }

    queue <cube> q;
    q.push({0, 0, 0});
    int ans = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (used[cur.x][cur.y][cur.z]) continue;
        used[cur.x][cur.y][cur.z] = true;

        if (cur.x - 1 >= 0 && cubes[cur.x - 1][cur.y][cur.z]) ans++;
        if (cur.x + 1 <= 29 && cubes[cur.x + 1][cur.y][cur.z]) ans++;
        if (cur.y - 1 >= 0 && cubes[cur.x][cur.y - 1][cur.z]) ans++;
        if (cur.y + 1 <= 29 && cubes[cur.x][cur.y + 1][cur.z]) ans++;
        if (cur.z - 1 >= 0 && cubes[cur.x][cur.y][cur.z - 1]) ans++;
        if (cur.z + 1 <= 29 && cubes[cur.x][cur.y][cur.z + 1]) ans++;

        if (cur.x - 1 >= 0 && !used[cur.x - 1][cur.y][cur.z]) q.push({cur.x - 1, cur.y, cur.z});
        if (cur.x + 1 <= 29 && !used[cur.x + 1][cur.y][cur.z]) q.push({cur.x + 1, cur.y, cur.z});
        if (cur.y - 1 >= 0 && !used[cur.x][cur.y - 1][cur.z]) q.push({cur.x, cur.y - 1, cur.z});
        if (cur.y + 1 <= 29 && !used[cur.x][cur.y + 1][cur.z]) q.push({cur.x, cur.y + 1, cur.z});
        if (cur.z - 1 >= 0 && !used[cur.x][cur.y][cur.z - 1]) q.push({cur.x, cur.y, cur.z - 1});
        if (cur.z + 1 <= 29 && !used[cur.x][cur.y][cur.z + 1]) q.push({cur.x, cur.y, cur.z + 1});
    }
    cout << ans;
}