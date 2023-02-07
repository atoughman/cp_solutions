// problem link
// 

#include<bits/stdc++.h>
using namespace std;

// dfs
class Codec {
public:
    const char D = ',';
    int ind;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "N";
        return to_string(root->val) + D + serialize(root->left) + D + serialize(root->right);
    }

    TreeNode* helper(string &data) {
        if(data[ind] == 'N') {
            ind += 2; // skipping N and ,
            return NULL;
        }

        string ts = "";
        while(data[ind] != D) {
            ts += data[ind];
            ++ind;
        }
        ++ind;  // skiping ,

        stringstream ss;
        ss << ts;
        int num;
        ss >> num;

        TreeNode* node = new TreeNode(num);
        node->left = helper(data);
        node->right=  helper(data);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        ind = 0;
        return helper(data);
    }
};


// bfs
class Codec {
public:
    const char DELIM = '#';
    const int EMPTY = 3000;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string ans = "";
        char buffer[33];

        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;
        ss << root->val;
        ans += ss.str();
        ans += DELIM;

        while(!q.empty()) {
            TreeNode* u = q.front();
            q.pop();
            if(u->left != NULL) {
                stringstream ss;
                ss << u->left->val;
                ans += ss.str();
                q.push(u->left);
            } else ans += ' ';
            ans += DELIM;

            if(u->right != NULL) {
                stringstream ss;
                ss << u->right->val;
                ans += ss.str();
                q.push(u->right);
            } else ans += ' ';
            ans += DELIM;
        }

        // trim last spaces
        while(ans[(int)ans.size()-1] == DELIM and ans[(int)ans.size()-2] == ' ') {
            ans.pop_back();
            ans.pop_back();
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        vector<int> v = {EMPTY}; // dummy value
        vector<int> offset = {EMPTY};

        int i=0;
        int num;
        int ct = 0;

        while(i<data.size()) {
            ++ct;
            string tmp = "";
            while(data[i] != DELIM) {
                tmp += data[i];
                ++i;
            }
            ++i;
            if(tmp == " ") {
                ct -= 2;
                offset.push_back(ct);
                v.push_back(EMPTY);
                continue;
            }
            stringstream ss;
            ss << tmp;
            ss >> num;
            v.push_back(num);
            offset.push_back(ct);
        }
        
        TreeNode* root = new TreeNode(v[1]);
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while(!q.empty()) {
            pair<TreeNode*, int> front = q.front();
            q.pop();

            TreeNode* u = front.first;
            int ind = front.second;

            int left_ind = ind + offset[ind];
            int right_ind = ind + offset[ind] + 1;

            if(left_ind < v.size() and v[left_ind] != EMPTY) {
                TreeNode* l = new TreeNode(v[left_ind]);
                u->left = l;
                q.push({l, left_ind});
            }
            if(right_ind < v.size() and v[right_ind] != EMPTY) {
                TreeNode* r = new TreeNode(v[right_ind]);
                u->right = r;
                q.push({r, right_ind});
            }
        }

        return root;
    }
};