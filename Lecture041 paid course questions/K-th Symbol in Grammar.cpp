// kthGrammar problem solution 
// obsurver this problem to tree structure 
// 1st row 0
// 2nd row 01
// 3rd row 0110

// find the parent of the kth element in the row  and then find the position of the kth element in the parent
// if parent is 0 then if kth element is odd then kth element is 0 else kth element is 1
// if parent is 1 then if kth element is odd then kth element is 1 else kth element is 0

// Time Complexity: O(n)
// Space Complexity: O(n)



class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1){
            return 0;
        }
        //* using two recursive calls to find kth parent
        // int parent = -1;
        // if(k&1 ==0 )
        //   parent = kthGrammar(n-1,k/2);
        // else
        //   parent = kthGrammar(n-1,(k+1)/2); 
            
        //* using one recursive call to find kth parent
        int parent = kthGrammar(n-1,k/2 + k%2);

        if(parent == 1){
            if(k&1){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(k&1){
                return 0;
            }else{
                return 1;
            }
        }
    }
};