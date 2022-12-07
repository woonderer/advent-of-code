#include <bits/stdc++.h>
using namespace std;

map <string, long long> total_size;
vector <string> cur_dir;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);


    cur_dir.push_back("/");
    total_size["/"] = 0;
    string line;
    while (getline(cin, line))
    {
        if (line[0] == '$')
        {
            if (line[2] == 'c')
            {
                if (line[5] == '/') continue;

                string dir;
                for (char c: line)
                {
                    if (c == ' ') dir.clear();
                    else dir.push_back(c);
                }

                if (dir == "..") cur_dir.pop_back();
                else 
                {
                    dir = cur_dir.back() + dir;
                    total_size[dir] = 0;
                    cur_dir.push_back(dir);
                }
            }
        }
        else if (line[0] != 'd')
        {
            string s;
            for (char c: line)
            {
                if (c == ' ') break;
                s.push_back(c);
            }

            for (string d: cur_dir)
            {
                total_size[d] += stoi(s);
            }
        }
    }

    int ans = 0;
    for (auto x: total_size)
    {
        if (x.second <= 100000) ans += x.second;
    }
    cout << ans;
}