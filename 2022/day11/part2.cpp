#include <bits/stdc++.h>
using namespace std;

const int M = 8;
deque <long long> items[M];
pair <int, int> operation[M], to[M];
int divisable[M], ans[M], MOD = 1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    for (int monkey = 0; monkey < M; monkey++)
    {
        getline(cin, line);
        for (int i = 0; i < 5; i++)
        {
            getline(cin, line);
            if (i == 0)
            {
                line = line.substr(line.find(':') + 2);
                size_t pos = 0;
                string token;
                while ((pos = line.find(", ")) != string::npos) {
                    token = line.substr(0, pos);
                    items[monkey].push_back(stoi(token));
                    line.erase(0, pos + 2);
                }
                items[monkey].push_back(stoi(line));
            }
            else if (i == 1) operation[monkey] = {(line[23] == '*' ? 1 : 0), (line.substr(line.rfind(' ') + 1) == "old" ? -1 : stoi((line.substr(line.rfind(' ') + 1))))};
            else if (i == 2) divisable[monkey] = stoi(line.substr(line.rfind(' ') + 1));
            else if (i == 3) to[monkey].first = stoi(line.substr(line.rfind(' ') + 1));
            else if (i == 4) to[monkey].second = stoi(line.substr(line.rfind(' ') + 1));
        }
        getline(cin, line);
    }

    for (int i = 0; i < M; i++)
        MOD *= divisable[i];

    for (int i = 1; i <= 10000; i++)
    {
        for (int m = 0; m < M; m++)
        {
            while (!items[m].empty())
            {
                ans[m]++;
                long long cur = items[m].front();
                items[m].pop_front();
                if (operation[m].first == 0)
                {
                    if (operation[m].second != -1) cur = (cur + operation[m].second) % MOD;
                    else cur = (cur + cur) % MOD;
                }
                else
                {
                    if (operation[m].second != -1) cur = (cur * operation[m].second) % MOD;
                    else cur = (cur * cur) % MOD;
                }
                if (cur % divisable[m] == 0) items[to[m].first].push_back(cur);
                else items[to[m].second].push_back(cur);
            }
        }
    }

    sort(ans, ans + M);
    cout << ans[M - 1] * 1LL * ans[M - 2];
}