#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string s;
    int cur = 0;
    vector <int> v;
    for (int _ = 0; _ < 2262; _++)
    {
        getline(cin, s);
        if (s.size() == 0)
        {
            v.push_back(cur);
            cur = 0;
        }
        else cur += stoi(s);
    }
    v.push_back(cur);
    sort(v.begin(), v.end());

    int ans = 0;

    cout << v[v.size() - 1] + v[v.size() - 2] + v[v.size() - 3];
}