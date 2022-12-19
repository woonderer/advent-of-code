#include <bits/stdc++.h>
using namespace std;

int solve(int costOre, int costClay, int costObs1, int costObs2, int costGeo1, int costGeo2, int time)
{
    int ans = 0;
    // ore, clay, obs, geo, robotOre, robotClay, robotObs, robotGeo, time
    queue <tuple <int, int, int, int, int, int, int, int, int>> q;
    set <tuple <int, int, int, int, int, int, int, int, int>> s;
    
    q.push(make_tuple(0, 0, 0, 0, 1, 0, 0, 0, time));
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int ore, clay, obs, geo, robotOre, robotClay, robotObs, robotGeo, time;
        tie(ore, clay, obs, geo, robotOre, robotClay, robotObs, robotGeo, time) = cur;
        ans = max(ans, geo);

        if (time == 0) continue;
        
        int core = max(costOre, max(costClay, max(costObs1, costGeo1)));

        robotOre = min(robotOre, core);
        robotClay = min(robotClay, costObs2);
        robotObs = min(robotObs, costGeo2);
        ore = min(ore, core * time - robotOre * (time - 1));
        clay = min(clay, costObs2 * time - robotClay * (time - 1));
        obs = min(obs, costGeo2 * time - robotObs * (time - 1));

        cur = make_tuple(ore, clay, obs, geo, robotOre, robotClay, robotObs, robotGeo, time);
        if (s.count(cur)) continue;
        s.insert(cur);

        q.push(make_tuple(ore + robotOre, clay + robotClay, obs + robotObs, geo + robotGeo, robotOre, robotClay, robotObs, robotGeo, time - 1));
        
        if (ore >= costOre)
            q.push(make_tuple(ore - costOre + robotOre, clay + robotClay, obs + robotObs, geo + robotGeo, robotOre + 1, robotClay, robotObs, robotGeo, time - 1));
        
        if (ore >= costClay)
            q.push(make_tuple(ore - costClay + robotOre, clay + robotClay, obs + robotObs, geo + robotGeo, robotOre, robotClay + 1, robotObs, robotGeo, time - 1));
        
        if (ore >= costObs1 && clay >= costObs2)
            q.push(make_tuple(ore - costObs1 + robotOre, clay - costObs2 + robotClay, obs + robotObs, geo + robotGeo, robotOre, robotClay, robotObs + 1, robotGeo, time - 1));
        
        if (ore >= costGeo1 && obs >= costGeo2)
            q.push(make_tuple(ore - costGeo1 + robotOre, clay + robotClay, obs - costGeo2 + robotObs, geo + robotGeo, robotOre, robotClay, robotObs, robotGeo + 1, time - 1));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.in", "r", stdin);

    int ans = 0;
    string line;
    while (getline(cin, line))
    {   
        int id, ore, clay;
        pair <int, int> obs, geo;
        sscanf(line.c_str(), "Blueprint %d: Each ore robot costs %d ore. Each clay robot costs %d ore. Each obsidian robot costs %d ore and %d clay. Each geode robot costs %d ore and %d obsidian.", &id, &ore, &clay, &obs.first, &obs.second, &geo.first, &geo.second);
        ans += id * solve(ore, clay, obs.first, obs.second, geo.first, geo.second, 24);
    }
    cout << ans;
}  