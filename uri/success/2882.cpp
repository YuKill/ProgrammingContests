#include <iostream>
#include <vector>
#include <limits>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;

const int inf = numeric_limits<int>::max();

struct EdgeRef {
    int u;
    int v;
    int weight;
};

struct EdgeRefComp {
    bool operator()(const EdgeRef& lhs, const EdgeRef& rhs) const {
        if (lhs.weight != rhs.weight) return lhs.weight < rhs.weight;
        if (lhs.u != rhs.u) return lhs.u < rhs.u;
        return lhs.v < rhs.v;
    }
};

struct DAGFlowEdge {
    int v;
    int cap;
    int flow;
    int revEdgeIdx;
    bool isValid;
    bool isReverse;
};

struct DAGFlowGraph {
    DAGFlowGraph(int n) :
        source(-1),
        target(-1),
        adj(n, vector<DAGFlowEdge>()),
        level(n, inf) {}

    void markSource(int u);
    void markTarget(int u);
    void markEdgeInvalid(int u, int v);
    void addEdge(int u, int v, int cap);
    void computeLevels();
    int computeMaxFlow();
    int updateUntilBlock(int source, int flow);
    void clearFlowData();

    int source;
    int target;
    vector<vector<DAGFlowEdge>> adj;
    vector<int> level;
};

void DAGFlowGraph::markSource(int u) {
    source = u;
}

void DAGFlowGraph::markTarget(int u) {
    target = u;
}

void DAGFlowGraph::markEdgeInvalid(int u, int v) {
    for (auto& edge : adj[u]) {
        if (edge.v == v) {
            edge.isValid = false;
            adj[v][edge.revEdgeIdx].isValid = false;
            break;
        }
    }
}

void DAGFlowGraph::addEdge(int u, int v, int cap) {
    int uRevIdx = adj[u].size();
    int vRevIdx = adj[v].size();
    adj[u].push_back(DAGFlowEdge { v, cap, 0, vRevIdx, true, false });
    adj[v].push_back(DAGFlowEdge { u,   0, 0, uRevIdx, true, true });
}

void DAGFlowGraph::computeLevels() {
    for (int i = 0; i < adj.size(); ++i) {
        level[i] = inf;
    }

    queue<int> q;

    level[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& edge : adj[u]) {
            if (edge.isValid && level[edge.v] == inf && edge.flow < edge.cap) {
                level[edge.v] = level[u] + 1;
                q.push(edge.v);
            }
        }
    }
}

int DAGFlowGraph::updateUntilBlock(int source, int flow) {
    if (source == target) return flow;

    int totalFlow = 0;

    for (auto& edge : adj[source]) {
        if (edge.isValid && level[edge.v] == level[source] + 1 && edge.flow < edge.cap) {
            int forwardFlow = min(flow - totalFlow, edge.cap - edge.flow);
            int realFlow = updateUntilBlock(edge.v, forwardFlow);

            if (realFlow > 0) {
                edge.flow += realFlow;
                adj[edge.v][edge.revEdgeIdx].flow -= realFlow;
                totalFlow += realFlow;
            }
        }
    }

    return totalFlow;
}

int DAGFlowGraph::computeMaxFlow() {
    computeLevels();

    int flow = 0;

    for (; level[target] != inf; computeLevels()) {
        while (int addFlow = updateUntilBlock(source, inf)) {
            flow += addFlow;
        }
    }

    return flow;
}

void DAGFlowGraph::clearFlowData() {
    for (auto& lst : adj) {
        for (auto& e : lst) {
            e.flow = 0;
            if (e.cap < 0) e.cap = 0;
        }
    }
}

void removeEdgesGT(int wIdx, const vector<vector<EdgeRef>>& edges, DAGFlowGraph& graph) {
    for (int i = wIdx + 1; i < edges.size(); ++i) {
        for (auto& e : edges[i]) {
            graph.markEdgeInvalid(e.u, e.v);
        }
    }
}

int binSearch(int init,
              int end,
              const vector<vector<EdgeRef>>& edges,
              const int baseFlow,
              const DAGFlowGraph& baseGraph) {
    if (init == end) {
        return edges[init][0].weight;
    }

    int mid = (init + end) / 2;
    int flow;

    DAGFlowGraph graph = baseGraph;
    removeEdgesGT(mid, edges, graph);
    flow = graph.computeMaxFlow();

    if (flow < baseFlow) {
        return binSearch(mid + 1, end, edges, baseFlow, baseGraph);
    } else if (flow == baseFlow) {
        return binSearch(init, mid, edges, baseFlow, baseGraph);
    }

    return -1;
}

int main() {
    int p, r, c;
    cin >> p >> r >> c;

    int source = p + r;
    int target = source + 1;
    DAGFlowGraph graph(p + r + 2);
    graph.markSource(source);
    graph.markTarget(target);

    int totalReq = 0;

    for (int i = 0, req; i < p; ++i) {
        cin >> req;
        graph.addEdge(i, target, req);
        totalReq += req;
    }

    for (int i = 0, store; i < r; ++i) {
        cin >> store;
        graph.addEdge(source, p + i, store);
    }

    map<int, vector<EdgeRef>> edgesMap;
    set<EdgeRef, EdgeRefComp> edgeRefSet;

    for (int i = 0; i < c; ++i) {
        int pI, rI, t;
        cin >> pI >> rI >> t;
        --pI;
        --rI;
        graph.addEdge(p + rI, pI, inf);
        edgesMap[t].push_back(EdgeRef { p + rI, pI, t });
    }

    vector<vector<EdgeRef>> edges;

    for (auto& pair : edgesMap) {
        edges.push_back(pair.second);
    }

    int baseFlow = graph.computeMaxFlow();
    graph.clearFlowData();

    if (baseFlow < totalReq) cout << -1 << endl;
    else {
        cout << binSearch(0, edges.size(), edges, baseFlow, graph) << endl;
    }

    // int u = 0;
    // for (auto& l : graph.adj) {
    //     cout << u++ << ": [";
    //     for (auto& e : l) {
    //         cout << " " << e.v;
    //     }
    //     cout << " ]" << endl;
    // }

    // for (auto& ref : edges) {
    //     cout << "(" << ref.u << ", " << ref.v << "): " << ref.weight << "; ";
    // }
    return 0;
}
