/*
Find shortest path with BFS method

Time : O(N^2)
Space: O(1)
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        

        if (grid[0][0] == 1 || grid[grid.size()-1][grid.size()-1] == 1) {return -1;}

        queue<pair<int, int>> q;
        q.push({0,0}); 
        
        grid[0][0] = 1; 
        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;

            if(row == grid.size() - 1 && col == grid.size() - 1) {return grid[row][col];}
            
            vector<vector<int>> neighbors = findNeighbors(grid, row, col);
            for (auto neighbor : neighbors) {
                
                if (grid[neighbor[0]][neighbor[1]] == 0) {
                    
                    q.push({neighbor[0], neighbor[1]});
                    grid[neighbor[0]][neighbor[1]] = grid[row][col] + 1;
                }
            }
            q.pop(); 
        }
        return -1;
    }
    
    vector<vector<int>> findNeighbors(vector<vector<int>> &grid, int row, int col) {
        
        vector<vector<int>> neighbors;
        
        int numRows = grid.size();
        int numCols = grid.size();

        if (row - 1 >= 0) {
            neighbors.push_back(vector<int>{row - 1, col}); //Up
        }
        if (row + 1 < numRows) {
            neighbors.push_back(vector<int>{row + 1, col}); //Dowm
        }
        if (col - 1 >= 0) {
            neighbors.push_back(vector<int>{row, col - 1}); //Left
        }
        if (col + 1 < numCols) {
            neighbors.push_back(vector<int>{row, col + 1});  //Right
        }
        if (row - 1 >= 0 && col - 1 >= 0) {
            neighbors.push_back(vector<int>{row - 1, col - 1});  //Left Up
        }
        if (row + 1 < numRows && col - 1 >= 0) {
            neighbors.push_back(vector<int>{row + 1, col - 1});  //Left Down
        }
        if (row - 1 >= 0 && col + 1 < numCols) {
            neighbors.push_back(vector<int>{row - 1, col + 1});  //Right Up
        }
        if (row + 1 < numRows && col + 1 < numCols) {
            neighbors.push_back(vector<int>{row + 1, col + 1});  //Right Down
        }
        return neighbors;
    }
};
