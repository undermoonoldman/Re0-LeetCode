// 144. Binary Tree Preorder Traversal
// Given a binary tree, return the preorder traversal of its nodes' values. 
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
//Output: [1,2,3]
// 
//
// Follow up: Recursive solution is trivial, could you do it iteratively? 
// Related Topics Stack Tree


//leetcode submit region begin(Prohibit modification and deletion)

import javax.swing.tree.TreeNode;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
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
    public List<Integer> preorderTraversal(TreeNode root) {
    	//储存遍历结果
        List<Integer> ret = new ArrayList<>();

        //判空
        if(root == null){
            return ret;
        }

        //辅助栈
        Stack<TreeNode> helper = new Stack<TreeNode>();
        //入栈根节点
        helper.push(root);

        //循环直到栈为空
        while(!helper.isEmpty()){
        	//取栈顶指针
            TreeNode current = helper.pop();
            //把当前值加入遍历结果
            ret.add(current.val);
            /**
            前序遍历顺序为根左右,因为栈是先进后出,所以要先访问的节点最后入*/
            //先入栈右节点
            if(current.right != null){
                helper.push(current.right);
            }
            //后入栈左节点
            if(current.left != null){
                helper.push(current.left);
            }
        }
        return ret;
    }
}
//leetcode submit region end(Prohibit modification and deletion)