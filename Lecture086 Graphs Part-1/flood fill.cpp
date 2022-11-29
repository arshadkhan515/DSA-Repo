// Flood Fill Algorithm
// Video Link: https://www.youtube.com/watch?v=C-2_uSRli8o&t=749s
// Article Link: https://takeuforward.org/graph/flood-fill-algorithm-graphs/
// Time Complexity: O(n*m) where n is the number of rows and m is the number of columns
// Space Complexity: O(n*m) where n is the number of rows and m is the number of columns

//** Using DFS
class Solution {
private:
    // direction array to store direction
   int direction[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
    // isOutofBound function to check whether the coordinate is out of bound
    bool isOutofBound(vector<vector<int>>& image,int sr,int sc){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int startColor){
        //check if out of bound
        if(isOutofBound(image,sr,sc)){
            return;
        }
        
        //check if it is the old color
        if(image[sr][sc] != startColor){
            return;
        }
        
        //change the color
        image[sr][sc] = color;
        
        //traverse all the neighbors
        for(int dir=0;dir<4;dir++){
            int newRow = sr + direction[dir][0];
            int newCol = sc + direction[dir][1];
            
            dfs(image,newRow,newCol,color,startColor);
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        if(image[sr][sc] != color){
            int startColor = image[sr][sc];
            dfs(ans,sr,sc,color,startColor);
        }
        return ans;
    }
};

//** Using BFS
class Solution {
private:
    int direction[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};
// 8 directions, the first number represents the direction of rows, the second number represents the direction of columns
    bool isOutofBound(vector<vector<int>>& image,int sr,int sc){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()){
            return true;
        }
        return false;
    }
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,int startColor){

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;
        while (!q.empty())
        {
            auto front = q.front(); //get the first element in the queue
            q.pop(); //remove the first element in the queue
            for (int dir = 0; dir < 4; dir++)
            {
                int newRow = front.first + direction[dir][0]; //get the next row
                int newCol = front.second + direction[dir][1]; //get the next column

                if (!isOutofBound(image, newRow, newCol) && image[newRow][newCol] == startColor)
                {
                    image[newRow][newCol] = color; //set the new color
                    q.push({newRow, newCol}); //add the new element in the queue
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // for(int row=0;)
        vector<vector<int>> ans = image;
        if(image[sr][sc] != color){
            int startColor = image[sr][sc];
            bfs(ans,sr,sc,color,startColor);
        }
        return ans;
    }
};
