/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, vector<Node*>> ht;
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        
        bfs(node);
        unordered_map<int,Node*> mapOfNodes;
        
        for (auto& pair: ht) {
            mapOfNodes.insert(make_pair(pair.first->val, new Node(pair.first->val)));
        }
        
        for (auto& pair: ht) {
            auto it = mapOfNodes.find(pair.first->val);
            for (auto& neighbor: pair.second) {
                auto it2 = mapOfNodes.find(neighbor->val);
                it->second->neighbors.push_back(it2->second);
            }
        }
        
        return mapOfNodes.find(node->val)->second;
    }
    
    void bfs(Node* node) {
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* curNode = q.front();
            q.pop();
            
            ht.insert(make_pair(curNode, curNode->neighbors));
            
            for (auto& candidate: curNode->neighbors) {
                auto it = ht.find(candidate);
                
                if (it != ht.end())
                    continue;
                else {
                    q.push(candidate);
                }
            }
        }
    }
};