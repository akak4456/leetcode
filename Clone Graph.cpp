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
    vector<Node*> nodes=vector<Node*>(101,nullptr);
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        if(nodes[node->val] == nullptr){
            nodes[node->val] = new Node(node->val);
        }
        for(Node* nb:node->neighbors){
            if(nodes[nb->val] == nullptr){
                nodes[nb->val] = new Node(nb->val);
                cloneGraph(nb);
            }
            nodes[nb->val]->neighbors.push_back(nodes[node->val]);
        }
        return nodes[node->val];
    }
};