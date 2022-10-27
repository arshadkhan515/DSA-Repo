//********* what is the sliding window technique?
// it is a technique that is used to solve problems that involve finding a subset of data that meets a certain condition
// like finding the longest substring with k unique characters
// or finding the longest substring with sum of elements less than or equal to k
// or finding the longest substring with sum of elements equal to k

//*************** the basic idea is to use two pointers to represent a window
// 1. the left pointer represents the start of the window
// 2. the right pointer represents the end of the window
// we use these two pointers to keep track of the elements that are currently in the window

// we use a hashmap to keep track of the frequency of the elements in the window
// we use a counter to keep track of the number of elements that satisfy the condition

//********** the basic structure of the sliding window technique is as follows
// int left = 0, right = 0;
// while(right < s.size()){
//     // add s[right] to the window
//     // update the hashmap and the counter
//     while(the window has more than k unique elements){
//         // remove s[left] from the window
//         // update the hashmap and the counter
//         left++;
//     }
//     // update the answer if needed
//     right++;
// }

//********** or we can use a while loop instead of a for loop
//  int start =0;
//         int end= 0;
//         long ans = 0;
//         long sum = 0;
        
//         while(end<N){
//             sum += Arr[end];
//             if(end-start+1 < K){
//                 end++;
//             }else if(end-start+1 == K){
//                 ans = max(ans,sum);
//                 sum -= Arr[start];
//                 start++;
//                 end++;
//             }
//         }
//  return ans;


