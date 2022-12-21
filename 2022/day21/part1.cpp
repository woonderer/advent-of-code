#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18 + 7;

map <string, long long> m; 
map <string, tuple <string, string, char>> g;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        string name = line.substr(0, 4);
        if (line.size() == 17)
        {
            m[name] = INF;
            g[name] = make_tuple(line.substr(6, 4), line.substr(13, 4), line[11]);
        }
        else
        {
            m[name] = stoi(line.substr(6));
        }
    }

    while (m["root"] == INF)
    {
        for (auto x: m)
        {
            if (x.second == INF && m[get<0>(g[x.first])] != INF && m[get<1>(g[x.first])] != INF)
            {
                switch (get<2>(g[x.first]))
                {
                    case '+':
                        m[x.first] = m[get<0>(g[x.first])] + m[get<1>(g[x.first])];
                        break;
                
                    case '-':
                        m[x.first] = m[get<0>(g[x.first])] - m[get<1>(g[x.first])];
                        break;

                    case '*':
                        m[x.first] = m[get<0>(g[x.first])] * m[get<1>(g[x.first])];
                        break;
                    
                    case '/':
                        m[x.first] = m[get<0>(g[x.first])] / m[get<1>(g[x.first])];
                        break;
                }
            }
        }
    }

    cout << m["root"];
}