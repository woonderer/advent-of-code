#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        set <char> st;
        for (int j = i; j <= i + 13; j++)
            st.insert(s[j]);

        if (st.size() == 14)
        {
            cout << i + 14;
            return 0;
        }
    }
}