#include <bits/stdc++.h>
using namespace std;

bool vis[105][105];
int tree[105][105];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    int idx = 1;
    while (getline(cin, line))
    {
        for (int i = 0; i < line.size(); i++)
        {
            tree[idx][i + 1] = line[i] - '0';
        }
        idx++;
    }

    int cur;
    // left to right
    for (int i = 1; i <= 99; i++)
    {
        cur = -1;
        for (int j = 1; j <= 99; j++)
        {
            if (tree[i][j] > cur)
            {
                vis[i][j] = 1;
                cur = tree[i][j];
            }
        }
    }
    
    // right to left
    for (int i = 1; i <= 99; i++)
    {
        cur = -1;
        for (int j = 99; j >= 1; j--)
        {
            if (tree[i][j] > cur)
            {
                vis[i][j] = 1;
                cur = tree[i][j];
            }
        }
    }

    // up to down
    for (int i = 1; i <= 99; i++)
    {
        cur = -1;
        for (int j = 1; j <= 99; j++)
        {
            if (tree[j][i] > cur)
            {
                vis[j][i] = 1;
                cur = tree[j][i];
            }
        }
    }

    // down to up
    for (int i = 1; i <= 99; i++)
    {
        cur = -1;
        for (int j = 99; j >= 1; j--)
        {
            if (tree[j][i] > cur)
            {
                vis[j][i] = 1;
                cur = tree[j][i];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 99; i++)
    {
        for (int j = 1; j <= 99; j++)
        {
            ans += vis[i][j];
        }
    }
    cout << ans;
}