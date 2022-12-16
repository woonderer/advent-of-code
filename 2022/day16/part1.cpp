#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

map <string, vector <string>> m;
map <string, int> s;
map <string, int> r;
vector <int> g[61], av;
bool used[61];
int D[61][61], rate[61], minut = 30, cur = 0, ans = 0, n = 0;

void obl(int node = 1)
{
    for (auto i: av)
    {
        if (!used[i] && minut - D[node][i] - 1 > 0)
        {
            cur += rate[i] * (minut - D[node][i] - 1);
            minut -= D[node][i] + 1;
            used[i] = true;
            obl(i);
            used[i] = false;
            minut += D[node][i] + 1;
            cur -= rate[i] * (minut - D[node][i] - 1);
        }
    }
    ans = max(ans, cur);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);	

    string line;
    while (getline(cin, line))
    {
        string valve;
        int ra;
        vector <string> lead;
        
        valve = line.substr(line.find(' ') + 1, 2);
        s[valve] = 0;
        string tmp = "";
        for (int i = line.find('=') + 1; i < line.find(';'); i++)
            tmp.push_back(line[i]);
        ra = stoi(tmp);
        r[valve] = ra;
        
        int x = 0;
        for (int i = line.size() - 1; i >= 0; i--)
        {
            if (line[i] >= 'a' && line[i] <= 'z')
            {
                x = i + 2;
                break;
            }
        }
        tmp = line.substr(x);
        
        string delimiter = ", ";
        
        size_t pos = 0;
        string token;
        while ((pos = tmp.find(delimiter)) != string::npos) {
            token = tmp.substr(0, pos);
            m[valve].push_back(token);
            tmp.erase(0, pos + delimiter.length());
        }
        m[valve].push_back(tmp);
        n++;
    }
    int x = 0;
    for (auto i: s)
    {
        s[i.first] = ++x;
        rate[s[i.first]] = r[i.first];
        if (r[i.first] != 0) av.push_back(s[i.first]);
    }
        
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) D[i][j] = 0;
            else D[i][j] = INF;
        }
    }
    
    for (auto i: m)
    {
        for (auto j: i.second)
        {
            g[s[i.first]].push_back(s[j]);
            D[s[i.first]][s[j]] = 1;
            D[s[j]][s[i.first]] = 1;
        }
    }
    
    
    for (int u = 1; u <= n; u ++)
        for (int x = 1; x <= n; x ++)
            for (int y = 1; y <= n; y ++)
                D[x][y] = min(D[x][y], D[x][u] + D[u][y]);
    
    obl();
    cout << ans;
}