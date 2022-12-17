// Number of Islands

//? leetcode discuss : https://leetcode.com/problems/number-of-islands/solutions/501000/c-simple-dfs-beats-100-in-memory-detailed-explanantion/?orderBy=most_votes&languageTags=cpp

// ??video explanation: https://www.youtube.com/watch?v=muncqlKJrH0&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=8

   

// without visited array traversal is dfs
// time complexity: O(N*M)
// space complexity: O(N*M)
class Solution
{
private:
    // generate 8 directions
    int map[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};

    void dfs(vector<vector<char>> &grid, int row, int col)
    {

        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return; // if the row or col is out of bounds, return and do nothing

        // if the value is 2 or 0, return and do nothing
        if (grid[row][col] == '2' || grid[row][col] == '0')
        {
            return;
        }

        grid[row][col] = '2'; // set the value to 2

        for (int i = 0; i < 8; i++)
        {                                 // for each of the 8 possible directions
            int newRow = row + map[i][0]; // get the row number of the next cell
            int newCol = col + map[i][1]; // get the column number of the next cell
            dfs(grid, newRow, newCol);    // recursively visit the next cell
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        int row = grid.size();
        int col = grid[0].size();
        // go through the grid
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // if we find a land
                if (grid[i][j] == '1')
                {
                    // increase the number of islands
                    islands++;
                    // call the dfs to change all the lands to water
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};

//** with visited array
// time complexity: O(n*m)
// space complexity: O(n*m)
class Solution
{
private:
    int map[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}}; // 8 directions

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int col)
    {

        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) // out of bounds
            return;

        if (visited[row][col] || grid[row][col] == '0')
        { // if already visited or water
            return;
        }

        visited[row][col] = true; // mark as visited

        for (int i = 0; i < 8; i++)
        { // traverse in all 8 directions
            int newRow = row + map[i][0];
            int newCol = col + map[i][1];
            dfs(grid, visited, newRow, newCol);
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        // Create a 2D boolean vector to keep track of the visited nodes.

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid, visited, i, j);
                    // If the node is not visited and is land, increment the count of islands and call the dfs function.
                }
            }
        }

        return islands;
    }
};
