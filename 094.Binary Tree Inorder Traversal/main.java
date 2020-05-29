// 94. Binary Tree Inorder Traversal
// Given a binary tree, return the inorder traversal of its nodes' values.
//
// Example: 
//
// 
//Input: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//Output: [1,3,2] 
//
// Follow up: Recursive solution is trivial, could you do it iteratively? 
// Related Topics Hash Table Stack Tree


//leetcode submit region begin(Prohibit modification and deletion)

import javax.swing.tree.TreeNode;
import java.util.ArrayList;
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
    public List<Integer> inorderTraversal(TreeNode root) {
        //存储遍历结果
        List<Integer> ret = new ArrayList<>();
        //辅助栈
        Stack<TreeNode> helper = new Stack<>();
        //判空
        if(root == null){
            return ret;
        }

        TreeNode p = root;

        while(true){
            //从根节点开始，一直取左孩子压栈
            if(p != null){
                helper.push(p);
                p = p.left;
            } else{
                //左孩子为空时,如果栈也为空就结束遍历
                if(helper.isEmpty()){break;}
                //弹栈取数放入遍历结果
                p = helper.pop();
                ret.add(p.val);
                //对右分支进行尝试
                p = p.right;
            }
        }
        return ret;
    }
}
//leetcode submit region end(Prohibit modification and deletion)