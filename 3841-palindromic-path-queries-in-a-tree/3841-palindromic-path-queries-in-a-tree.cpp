
class Solution {
    int LOG;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth;
    vector<int> bit;
    string s;
    int timer = 0;

    int mask(char c) {
        return 1 << (c - 'a');
    }

    void add(int i, int val) {
        for (; i < (int)bit.size(); i += i & -i)
            bit[i] ^= val;
    }

    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;

        for (int j = 1; j < LOG; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j))
                u = up[u][j];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string str, vector<string>& queries) {
        s = str;
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n, {});
        up.assign(n, vector<int>(LOG, 0));
        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        bit.assign(n + 2, 0);
        timer = 0;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, 0);

        for (int u = 0; u < n; u++) {
            int m = mask(s[u]);
            add(tin[u], m);
            add(tout[u] + 1, m);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int delta = mask(s[u]) ^ mask(c);
                add(tin[u], delta);
                add(tout[u] + 1, delta);
                s[u] = c;
            } else {
                ss >> v;
                int w = lca(u, v);

                int pathMask = sum(tin[u]) ^ sum(tin[v]) ^ mask(s[w]);

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
