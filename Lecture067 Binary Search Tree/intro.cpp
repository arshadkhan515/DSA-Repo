//**** what is a binary search tree?
// A binary search tree (BST) is a node-based binary tree data structure which has the following properties:
// left subtree of a node contains only nodes with keys less than the node's key.
// right subtree of a node contains only nodes with keys greater than the node's key.
// the left and right subtree each must also be a binary search tree.
// There must be no duplicate nodes.
// image: https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png



/**** The time complexity of binary search tree operations is O(h) time or O(log n) time in the average case, where h is the height of the tree.
// and insertion and deletion is O(h) time or O(log n) time in the average case.

//**** in worst case the height of the tree can be n.
// so the time complexity of binary search tree operations is O(n) time.
// and insertion and deletion is O(n) time.

//***** O(H), where 'H' is the height of the given BST.
// In each recursive step, the height of the BST pass in method will reduce by 1. Thus if ‘H’ is the height of this BST then at most it takes O(H) times.  Note ‘H’ can be ‘N’ if the tree is completely skewed, and log(N) if the tree is balanced.