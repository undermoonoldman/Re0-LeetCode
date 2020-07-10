//124. Binary Tree Maximum Path Sum
//Given a non-empty binary tree, find the maximum path sum. 
//
// For this problem, a path is defined as any sequence of nodes from some starti
//ng node to any node in the tree along the parent-child connections. The path mus
//t contain at least one node and does not need to go through the root. 
//
// Example 1: 
//
// 
//Input: [1,2,3]
//
//       1
//      / \
//     2   3
//
//Output: 6
// 
//
// Example 2: 
//
// 
//Input: [-10,9,20,null,null,15,7]
//
//   -10
//   / \
//  9  20
//    /  \
//   15   7
//
//Output: 42
// 
// Related Topics Tree Depth-first Search 
// 👍 3668 👎 287


/**
 思路，在后序遍历中，对所有节点执行如下操作
 分别计算左右子树的最大路径
 比较三条路径，找出最大的。(1.当前节点到左子树；2.当前节点到右子树；3.左子树当前节点右子树)
 尝试用刚刚找出的当前最大路径，看看能否更新全局最大路径
 返回包含左右子路径中最大值与当前节点路径长度的加和
 **/
class Solution {
	//记录全局最长路径，初始值为整型的最小值
    private int globalMaxSum = Integer.MIN_VALUE;

    //辅助函数，再类似后序遍历的过程中，不断更新全局最大值
    private int helper(TreeNode root){
    	//空节点，返回零
        if(root == null) return 0;

        //取得左右子树的最长路径，如果最长路径为负值，则舍弃取为零
        int left = Math.max(0, helper(root.left));
        int right = Math.max(0, helper(root.right));

        //比较获得左右分支中较长的一条
        int maxSubBranch = Math.max(left, right);

        //如果左右子树的最长路径都为负值，那么当前的最长路径就只包含根节点本身(因为为负的子路径已经被零替代了)
        //通过这一步获得了三条路径中最长的一条
        int tempMax = Math.max(maxSubBranch + root.val, left + right + root.val);
        //尝试更新全局最长路径
        globalMaxSum = Math.max(globalMaxSum, tempMax);

        return maxSubBranch + root.val;
    }

    //从根节点开始，执行一次类似的后序遍历，就获得的全局最长路径
    public int maxPathSum(TreeNode root) {
        helper(root);
        return globalMaxSum;
    }
}