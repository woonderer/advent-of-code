#include <bits/stdc++.h>
using namespace std;

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

    int ans = 0;
    for (int i = 1; i <= 99; i++)
    {
        for (int j = 1; j <= 99; j++)
        {
            int up = 0, down = 0, left = 0, right = 0;
            
            // up
            for (int y = i - 1; y >= 1; y--)
            {
                up++;
                if (tree[y][j] >= tree[i][j]) break;
            }

            // down
            for (int y = i + 1; y <= 99; y++)
            {
                down++;
                if (tree[y][j] >= tree[i][j]) break;
            }

            // left
            for (int x = j - 1; x >= 1; x--)
            {
                left++;
                if (tree[i][x] >= tree[i][j]) break;
            }

            // right
            for (int x = j + 1; x <= 99; x++)
            {
                right++;
                if (tree[i][x] >= tree[i][j]) break;
            }

            ans = max(ans, up * down * left * right);
        }
    }

    cout << ans;
}