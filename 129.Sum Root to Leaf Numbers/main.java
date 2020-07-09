//129.Sum Root to Leaf Numbers
// Given a binary tree containing digits from 0-9 only, each root-to-leaf path co
//uld represent a number. 
//
// An example is the root-to-leaf path 1->2->3 which represents the number 123. 
//
//
// Find the total sum of all root-to-leaf numbers. 
//
// Note: A leaf is a node with no children. 
//
// Example: 
//
// 
//Input: [1,2,3]
//    1
//   / \
//  2   3
//Output: 25
//Explanation:
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//Therefore, sum = 12 + 13 = 25. 
//
// Example 2: 
//
// 
//Input: [4,9,0,5,1]
//    4
//   / \
//  9   0
// / \
//5   1
//Output: 1026
//Explanation:
//The root-to-leaf path 4->9->5 represents the number 495.
//The root-to-leaf path 4->9->1 represents the number 491.
//The root-to-leaf path 4->0 represents the number 40.
//Therefore, sum = 495 + 491 + 40 = 1026. 
// Related Topics Tree Depth-first Search 
// 👍 1488 👎 42


//leetcode submit region begin(Prohibit modification and deletion)
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
/*使用栈来辅助，从根节点到叶子节点不断压栈，遇到叶子节点时进行一次计算
并更新累加器，当一次递归调用返回时，执行弹栈操作*/
class Solution1 {
    private int sum = 0;
    private Stack<String> helper = new Stack<>();

    private void traverse(TreeNode root) {
        if(root == null) return;

        //当前节点不为空，执行压栈
        helper.push(Integer.toString(root.val));

        //当前节点为叶子节点，更新累加器
        if(root.left == null && root.right == null){
            String tempStr = helper.toString();
            tempStr = tempStr.substring(1, tempStr.length()-1);
            tempStr = tempStr.replace(",", "");
            tempStr = tempStr.replace(" ", "");
            int tempInt = Integer.parseInt(tempStr);
            sum += tempInt;
        }

        //递归处理左右孩子
        traverse(root.left);
        traverse(root.right);
        //递归返回时执行弹栈
        if(!helper.empty()) helper.pop();
    }

    public int sumNumbers(TreeNode root) {
        if(root == null) return sum;

        traverse(root);
        return sum;
    }
}


/**从根到叶子的路径加和不需要记录递归的层数，而是每次都把父节点传来的值乘以10与当前值相加，然后传递到下一层递归调用中去
遇到叶子节点时，就把计算的值累加到计数器中去**/
class Solution2 {
	//累加计数，初始为零
    private int sum = 0;

    //近似的前序遍历操作
    private void traverse(TreeNode root, int previous) {
    	//空节点之间返回
        if(root == null) return;

        //把之前值乘以十并与当前值相加得到临时值(这样就避免了记录递归层数)
        int temp = previous * 10 + root.val;

        //遇到根节点时，用临时值去更新累加器
        if(root.left == null && root.right == null)
            sum += temp;

        //非叶子节点，把临时值作为下一层递归的之前值
        traverse(root.left, temp);
        traverse(root.right, temp);
    }

    public int sumNumbers(TreeNode root) {
    	//根节点为空，直接返回零
        if(root == null) return sum;

        //执行一次“遍历”操作，初次传入的值为零
        traverse(root, 0);

        //执行一次遍历后，累加值计算完成
        return sum;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
