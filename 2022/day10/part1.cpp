#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    int x = 1, cycle = 1;
    long long ans = 0;

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

            if ((cycle - 20) % 40 == 0)
                ans += cycle * x;
            cycle++;

            if ((cycle - 20) % 40 == 0)
                ans += cycle * x;
            x += n;
            cycle++;
        }
        else
        {
            if ((cycle - 20) % 40 == 0)
                ans += cycle * x;
            cycle++;
        }
    }
    cout << ans;
}