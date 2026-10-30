
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, LLONG_MAX)
        );

        using State = tuple<long long, int, int>;

        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, node, count] = pq.top();
            pq.pop();

            if (cost != dist[node][count])
                continue;

            if (node == n - 1)
                return (int)cost;

            for (auto [next, weight] : adj[node]) {

                int newCount = (labels[node] == labels[next])
                               ? count + 1 : 1;

                if (newCount > k)
                    continue;

                long long newCost = cost + weight;

                if (newCost < dist[next][newCount]) {
                    dist[next][newCount] = newCost;

                    pq.push({
                        newCost,
                        next,
                        newCount
                    });
                }
            }
        }

        return -1;
    }
};
