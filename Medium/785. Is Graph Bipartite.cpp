/*
This problem implements the Depth First Search method to divide nodes into two sets. If any given neighbor nodes are 
in the same set, then this graph is not Bipartite.

Time : O(V+ E)
Space : O(V)
Where V is number of vertexes and E is number of edges
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       
        unordered_map<int, int> hashmap;
        for (int i = 0; i < graph.size(); i++) {
            hashmap[i] = 0;
        }
        
        for (int i = 0; i < graph.size(); i++) {
            
            if (!hashmap[i] || graph[i].empty()) {
                
                if (!dfs(graph, hashmap, i)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, unordered_map<int, int>& hashmap, int i) {
        
        
        for (int neighbor : graph[i]) {
            
            if (!hashmap[neighbor]) {
                
                hashmap[neighbor] = 1 - hashmap[i];
                
                if (!dfs(graph, hashmap, neighbor)) {
                    return false;
                }
            }
            else if(hashmap[neighbor] == hashmap[i]) {
                return false;
            }
        }
        return true;
    }
};
