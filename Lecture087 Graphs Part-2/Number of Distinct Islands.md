# Number of Distinct Islands

## Article Link: https://takeuforward.org/data-structure/number-of-distinct-islands/

## Using DFS

### Time Complexity: O(N x M x log(N x M)) + O(NxMx4) ~ O(N*M)

### Space Complexity: O(N*M)

```cpp
class Solution {
  private:

    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isOutofBound(vector<vector<int>>& image,int sr,int sc){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()){
            return true;
        }
        return false;
    }
  void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int row,int col,vector<pair<int,int>> &island,int baseRow,int baseCol){


      visited[row][col] = true;
      // mark this cell as visited
      island.push_back({ row - baseRow, col - baseCol});
      // the relative position of this cell to the top left cell of the island
      // for example, if the top left cell is (1,1), then this cell is (row -1,col - 1)

    // iterate through all 4 directions
    for(int it=0;it<4;it++){
        // calculate the new row and new column
        int newRow = row + direction[it][0];
        int newCol = col + direction[it][1];
        // if the new position is not out of bound and not visited and is a land
        if(!isOutofBound(grid,newRow,newCol) && !visited[newRow][newCol] && grid[newRow][newCol] == 1){
        // do dfs from the new position
        dfs(grid,visited,newRow,newCol,island,baseRow,baseCol);
        }
    }

  }

  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // N = number of rows
        // M = number of columns
        int N = grid.size();
        int M = grid[0].size();
        // visited[i][j] = true if we have visited grid[i][j]
        vector<vector<bool>> visited(N,vector<bool>(M,false));
        // ans = set of islands
        set<vector<pair<int,int>>> ans;

        for(int i=0;i<N;i++){
          for(int j=0;j<M;j++){
              // if we haven't visited grid[i][j] and it is land
              if (!visited[i][j] && grid[i][j] == 1) {
                // island = current island
                vector<pair<int,int>> island;
                // dfs to find connected land
                dfs(grid,visited,i,j,island,i,j);
                // add island to ans
                ans.insert(island);
              }
        }
      }
      // return number of distinct islands
      return ans.size();
    }
};
```
