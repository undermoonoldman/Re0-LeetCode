//给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。 
//
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。 
//
// 示例: 
//
// 给定的有序链表： [-10, -3, 0, 5, 9],
//
//一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5
// 
// Related Topics 深度优先搜索 链表 
// 👍 453 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

import javax.swing.tree.TreeNode;
import java.util.Enumeration;

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


/**
有序链表生成一棵平衡二叉搜索树，要保证平衡，每次都要找到链表的中点把链表截成左右子树
寻找链表中点使用快慢指针，快指针一次走两步，慢指针一次走一步，当快指针指向dummyTail或快指针的next指向dummyTail时，慢指针指在中间节点
注意:表示一段子树的区间为左闭右开，左边能取到，右边取不到
已找到的中间节点构建新子树的根，中间节点分割开的左右两端分别构建左右子树
当子树区间左右两端相同时，为递归终止条件，返回null
*/

class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        //特殊值判断
        if(head == null) return null;

        //初始以整个链表构建根节点，注意左开右闭，所以dummyTail为null
        return helper(head, null);
    }

    public TreeNode helper(ListNode front, ListNode end){
        //递归终止条件
        if(front == end) return null;

        //快慢指针初始化
        ListNode fast = front;
        ListNode slow = front;

        //快指针为null或快指针的next为null为循环终止条件
        while(fast != end && fast.next != end){
            slow = slow.next;
            fast = fast.next.next;
        }

        //以找到的中间节点构建根节点
        TreeNode middle = new TreeNode(slow.val);

        //递归生成左子树，注意边界条件为左开右闭
        middle.left = helper(front, slow);

        //递归生成右子树，注意边界条件为左开右闭
        middle.right = helper(slow.next, end);

        return middle;
    }
}
//leetcode submit region end(Prohibit modification and deletion)