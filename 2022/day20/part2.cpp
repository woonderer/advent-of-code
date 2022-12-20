#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> v;
vector <long long> legit;

int find_index(int idx)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i].second == idx)
            return i;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    int a, i = 0;
    while (cin >> a)
    {
        legit.push_back(811589153LL * a);
        v.push_back({a, i++});
    }

    int n = v.size();
    for (int i = 0; i < n; i++)
        v[i].first = (811589153LL * v[i].first) % (n - 1);
    
    int zero_idx;
    for (int m = 1; m <= 10; m++)
    {
        for (int i = 0; i < n; i++)
        {
            int idx = find_index(i);

            if (v[idx].first > 0)
            {
                for (int j = 0; j < v[(idx + j) % n].first; j++)
                {
                    swap(v[(idx + j) % n], v[(idx + j + 1) % n]);
                }
            }
            else if (v[idx].first < 0)
            {
                for (int j = 0; j > v[((idx + j) % n + n) % n].first; j--)
                    swap(v[((idx + j) % n + n) % n], v[((idx + j - 1) % n + n) % n]);
            }
            else zero_idx = i;
        }
    }

    int idx = find_index(zero_idx);
    cout << legit[v[(idx + 1000) % n].second] + legit[v[(idx + 2000) % n].second] + legit[v[(idx + 3000) % n].second];
}