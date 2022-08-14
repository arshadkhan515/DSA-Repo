class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
    {
        stack<int> temp;
        vector<int> ans(n);
        temp.push(-1);
        for(int i=n-1;i>=0;i--){  
            while(temp.top() != -1 && arr[i]<=arr[temp.top()]){
                temp.pop();
            }
            ans[i] = temp.top();
            temp.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> &arr, int n)
    {
        stack<int> temp;
        vector<int> ans(n);cou
        temp.push(-1);
        for(int i=0;i<n;i++){  
            while(temp.top() != -1 && arr[i]<=arr[temp.top()]){
                temp.pop();
            }
            ans[i] = temp.top();
            temp.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights,n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);
        
        int ans = INT_MIN;
        for(int i=0;i<n;i++){      
            // cout<<next[i] <<" "<< prev[i]<<endl;

            if(next[i] == -1)
                next[i] = n;
            int width = next[i] - prev[i] -1;
            int area = heights[i]*width;
            
            ans = max(ans,area);
        }
        return ans;
        
    }


};