// 145. Binary Tree Postorder Traversal
// Given a binary tree, return the postorder traversal of its nodes' values. 
//
// Example: 
//
// 
//Input: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//Output: [3,2,1]
// 
//
// Follow up: Recursive solution is trivial, could you do it iteratively? 
// Related Topics Stack Tree


//leetcode submit region begin(Prohibit modification and deletion)

import javax.swing.tree.TreeNode;
import java.util.ArrayList;
import java.util.Stack;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        //判空
        if(root == null){
            return ret;
        }
        s1.push(root);

        //按照根右左把节点压入s2中
        while(!s1.isEmpty()){
            TreeNode p = s1.pop();
            s2.push(p);
            if(p.left != null){
                s1.push(p.left);
            }
            if(p.right != null){
                s1.push(p.right);
            }
        }

        //按照之前的入栈顺序，依次弹栈的顺序就是左右根
        while(!s2.isEmpty()){
            ret.add(s2.pop().val);
        }
        return ret;
    }
}
//leetcode submit region end(Prohibit modification and deletion)