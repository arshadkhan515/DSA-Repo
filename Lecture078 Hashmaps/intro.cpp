//** in stl,have two types of maps
// 1. map and it is sorted, and it is implemented using red black tree or Balanced BST, and time complexity is O(logn) for insertion and search and deletion on average case and O(n) in worst case.
// 2. unordered_map and it is not sorted, and it is implemented using hash table, and time complexity is O(1) on average and O(n) in worst case (when collision occurs) and it is implemented using hash table.



//** how unordered_map is implemented using hash table
// hash table is an array of linked list
// hash function is used to generate the index of the array
// hash function is a function which takes a key and returns an index