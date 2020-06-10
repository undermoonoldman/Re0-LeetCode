// 117. Populating Next Right Pointers in Each Node II
// Given a binary tree
//
// 
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
// 
//
// Populate each next pointer to point to its next right node. If there is no ne
//xt right node, the next pointer should be set to NULL. 
//
// Initially, all next pointers are set to NULL. 
//
// 
//
// Follow up: 
//
// 
// You may only use constant extra space. 
// Recursive approach is fine, you may assume implicit stack space does not coun
//t as extra space for this problem. 
// 
//
// 
// Example 1: 
//
// 
//
// 
//Input: root = [1,2,3,4,5,null,7]
//Output: [1,#,2,3,#,4,5,7,#]
//Explanation: Given the above binary tree (Figure A), your function should popu
//late each next pointer to point to its next right node, just like in Figure B. T
//he serialized output is in level order as connected by the next pointers, with '
//#' signifying the end of each level.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the given tree is less than 6000. 
// -100 <= node.val <= 100 
// 
// Related Topics Tree Depth-first Search


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

/***
 * 与前一题的区别就是输入的树从完美二叉树变成了普通二叉树
 */
class Solution {
    public Node connect(Node root) {
        //根节点为空(输入为空树)，根节点的左孩子为空(输入的树只有一个节点)，这时就可以直接返回
        if(root == null || (root.left == null && root.right == null))
            return root;

        //因为输入的不是完美二叉树，所以要找到与左右子树处于同一层的第一个右边的节点
        Node p = root.next;
        
        //同层移动查找
        while(p != null){
            if(p.left != null){
                p = p.left;
                break;
            }

            if(p.right != null){
                p = p.right;
                break;
            }

            p = p.next;
        }

        //右节点存在的话，next只能指向p
        if(root.right != null){
            root.right.next = p;
        }

        //左节点存在的话，next看情况指向p或指向右节点
        if(root.left != null){
            root.left.next = root.right != null ? root.right : p;
        }

        //由于上述操作需要不断取next节点，所以对先对右子树进行遍历可以维持更多的next节点信息，这里与前一题不同
        connect(root.right);
        connect(root.left);


        return root;
    }
}
//leetcode submit region end(Prohibit modification and deletion)