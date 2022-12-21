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

    m["humn"] = INF;
    int changes = 1;

    while (changes)
    {
        changes = 0;
        for (auto x: m)
        {
            if (x.first == "humn") continue;

            if (x.second == INF && m[get<0>(g[x.first])] != INF && m[get<1>(g[x.first])] != INF)
            {
                changes++;
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

    string cur;
    if (m[get<0>(g["root"])] == INF)
    {
        cur = get<0>(g["root"]);
        m[get<0>(g["root"])] = m[get<1>(g["root"])];
    }
    else
    {
        cur = get<1>(g["root"]);
        m[get<1>(g["root"])] = m[get<0>(g["root"])];
    }

    while (m["humn"] == INF)
    {
        if (m[get<0>(g[cur])] == INF)
        {
            switch (get<2>(g[cur]))
            {
                case '+':
                    m[get<0>(g[cur])] = m[cur] - m[get<1>(g[cur])];
                    break;
            
                case '-':
                    m[get<0>(g[cur])] = m[cur] + m[get<1>(g[cur])];
                    break;

                case '*':
                    m[get<0>(g[cur])] = m[cur] / m[get<1>(g[cur])];
                    break;
                
                case '/':
                    m[get<0>(g[cur])] = m[cur] * m[get<1>(g[cur])];
                    break;
            }
            cur = get<0>(g[cur]);
        }
        else
        {
            switch (get<2>(g[cur]))
            {
                case '+':
                    m[get<1>(g[cur])] = m[cur] - m[get<0>(g[cur])];
                    break;
            
                case '-':
                    m[get<1>(g[cur])] = m[get<0>(g[cur])] - m[cur];
                    break;

                case '*':
                    m[get<1>(g[cur])] = m[cur] / m[get<0>(g[cur])];
                    break;
                
                case '/':
                    m[get<1>(g[cur])] = m[get<0>(g[cur])] / m[cur];
                    break;
            }
            cur = get<1>(g[cur]);
        }
    }
    cout << m["humn"];
}