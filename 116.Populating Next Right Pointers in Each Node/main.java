//116. Populating Next Right Pointers in Each Node
//You are given a perfect binary tree where all leaves are on the same level, an
//d every parent has two children. The binary tree has the following definition: 
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
//Input: root = [1,2,3,4,5,6,7]
//Output: [1,#,2,3,#,4,5,6,7,#]
//Explanation: Given the above perfect binary tree (Figure A), your function sho
//uld populate each next pointer to point to its next right node, just like in Fig
//ure B. The serialized output is in level order as connected by the next pointers
//, with '#' signifying the end of each level.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the given tree is less than 4096. 
// -1000 <= node.val <= 1000 
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

/**题目中说了完美二叉树(perfect binary tree),一个深度为k(>=-1)且有2^(k+1) - 1个结点的二叉树称为完美二叉树,就是从满二叉树。这样所有的叶子节点都在一层
*/

class Solution {
    public Node connect(Node root) {
    	//根节点为空(输入为空树)，根节点的左孩子为空(输入的树只有一个节点)，这时就可以直接返回
        if(root == null || root.left == null)
            return root;

        //把左孩子的next指向右孩子
        root.left.next = root.right;

        //把右孩子的next指向当前节点next的左孩子(前提是当前节点存在next节点)
        if(root.next != null)
            root.right.next = root.next.left;

        //使用递归方法处理子树时需要用到之前所连接的next指针，所以采用前序遍历的方法

        //对左子树执行相同的操作
        connect(root.left);
        //对右子树执行相同的操作
        connect(root.right);

        //左右子树都处理完成之后，返回根节点即可
        return root;
    }
}
//leetcode submit region end(Prohibit modification and deletion)