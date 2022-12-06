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
        for (int j = i; j <= i + 3; j++)
            st.insert(s[j]);

        if (st.size() == 4)
        {
            cout << i + 4;
            return 0;
        }
    }
}