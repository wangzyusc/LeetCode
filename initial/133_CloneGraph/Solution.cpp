#include "../IOLib.hpp"

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        //UndirectedGraphNode* ptr = node;
        unordered_map<int, UndirectedGraphNode*> book;
        queue<UndirectedGraphNode*> line;
        line.push(node);
        while(!line.empty()){
            UndirectedGraphNode* ptr = line.front();
            line.pop();
            if(book.find(ptr->label) != book.end()) continue;
            book[ptr->label] = new UndirectedGraphNode(ptr->label);
            for(auto next: ptr->neighbors){
                if(book.find(next->label) != book.end()) continue;
                line.push(next);
            }
        }
        //line.clear();
        line.push(node);
        unordered_set<int> visited;
        visited.insert(node->label);
        while(!line.empty()){
            auto ptr = line.front();
            line.pop();
            auto cur = book[ptr->label];
            for(auto next: ptr->neighbors){
                cur->neighbors.push_back(book[next->label]);
                if(visited.find(next->label)!=visited.end()) continue;
                visited.insert(next->label);
                line.push(next);
            }
        }
        return book[node->label];
    }
};
