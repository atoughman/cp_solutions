// problem link
// https://leetcode.com/problems/clone-graph/description/

class Solution {
public:
    void dfs(Node* node, map<int,Node*> &vis, Node* ans) {
        // process
        Node* tmp = new Node(node->val);
        vis[node->val] = tmp;

        // neighbours
        for(auto v: node->neighbors) {
            // process
            if(!vis[v->val]) dfs(v, vis, ans);
            tmp->neighbors.push_back(vis[v->val]);
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        Node* ans = NULL;
        map<int,Node*> vis;
        dfs(node, vis, ans);
        return vis[node->val];
    }
};