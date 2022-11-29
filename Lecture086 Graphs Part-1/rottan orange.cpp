// Rotting Oranges
// Article Link: https://takeuforward.org/data-structure/rotten-oranges/

//  Space Complexity: O(n*m)
//  Time Complexity: O(n*m)

class Solution {
    private:
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isOutofBound(vector<vector<int>>& image,int sr,int sc){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()){
            return true;
        }
        return false;
    }
    void bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int row,int col,int& ans){
        // queue to store the next node to visit and the time taken to reach that node
        queue<pair<pair<int,int>,int>> q;
        int totalFresh = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                // if the current cell is a rotten orange, push it to the queue
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
                // count the total number of fresh oranges
                if(grid[i][j] == 1) totalFresh++;
            }
        }


        while(!q.empty()){
            // get the front element of the queue
            auto front = q.front();
            q.pop();
            int ti = front.second;
            // set the minimum time taken to reach a cell
            ans = max(ans,ti);
            // visit the adjacent cells of the front element
            for(int i=0;i<4;i++){
                // get the next row
                int newRow = front.first.first + direction[i][0];
                // get the next column
                int newCol = front.first.second + direction[i][1];

                // check if the next cell is valid, has a fresh orange and has not been visited
                if(!isOutofBound(grid,newRow,newCol) && grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0){

                    // mark the next cell as visited
                    vis[newRow][newCol] = 2;
                    // decrement the total number of fresh oranges
                    totalFresh--;
                    // push the next cell to the queue
                    q.push({{newRow,newCol},ti+1});
                }
            }
        }
            // check if all the fresh oranges have turned rotten
            if(totalFresh > 0) ans=-1;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
   // create a temp vector to store the grid
        vector<vector<int>> temp = grid;
        // create a variable to store the maximum time taken to rot all the oranges
        int ans = 0;
        // find the number of rows of the grid
        int row = grid.size();
        // find the number of columns of the grid
        int col = grid[0].size();
        // create a 2D vector to store the status of the cells
        vector<vector<int>> vis(row,vector<int>(col));
        // call the bfs function
        bfs(temp,vis,row,col,ans);
        // return the maximum time taken to rot all the oranges
        return ans;
    }
};

