/* 
	Topic: Graph (Dijkstra) 
	Difficulty: H
	Time: O(n+elog(n)) 
	Space: O(n)
*/


typedef long long ll;
class Solution {
    vector<ll> dijkstra(int n, vector<pair<int, int>> *graph, int src) {
        vector<ll> distance(n, -1);
        set<pair<ll, ll>> q;
        distance[src] = 0;
        q.insert({0, src});
        while (!q.empty()) {
            ll dist = q.begin()->first;
            int node = q.begin()->second;
            q.erase(q.begin());
            for (auto nbr : graph[node]) {
                if (distance[nbr.first] == -1) {
                    distance[nbr.first] = dist + nbr.second;
                    q.insert({distance[nbr.first], nbr.first});
                } else if (distance[nbr.first] > dist + nbr.second) {
                    q.erase({distance[nbr.first], nbr.first});
                    distance[nbr.first] = dist + nbr.second;
                    q.insert({distance[nbr.first], nbr.first});
                }
            }
        }

        return distance;
    }

public:
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest) {
        vector<pair<int, int>> graph[n];
        vector<pair<int, int>> revGraph[n];
        for (auto edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            revGraph[edge[1]].push_back({edge[0], edge[2]});
        }
        auto src1ToAll = dijkstra(n, graph, src1);
        auto src2ToAll = dijkstra(n, graph, src2);
        auto destToAll = dijkstra(n, revGraph, dest);
        if (destToAll[src1] == -1 || destToAll[src2] == -1) return -1;
        ll dist = LLONG_MAX;
        for (int common = 0; common < n; common++) {
            if (destToAll[common] != -1 && src1ToAll[common] != -1 && src2ToAll[common] != -1)
                dist = min(dist, destToAll[common] + src1ToAll[common] + src2ToAll[common]);
        }
        return dist;
    }
};
