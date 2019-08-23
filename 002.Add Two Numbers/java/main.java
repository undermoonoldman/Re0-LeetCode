    class Solution {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode dummyHead = new ListNode(0);
            ListNode p = dummyHead;

            //记录进位
            int j = 0;
            //记录加和结果
            int i = 0;
            while(l1 != null && l2 != null){
                i = (l1.val + l2.val + j) % 10;
                j = (l1.val + l2.val + j) / 10;
                l1 = l1.next;
                l2 = l2.next;
                ListNode temp = new ListNode(i);

                p.next = temp;
                p = p.next;
            }

            /**
             * 始终处于p的前一个位置
             */
            ListNode q = p;

            if(l1 == null || l2 == null){
                if(l1 == null)
                    p.next = l2;

                else
                    p.next = l1;

                /**
                 * 执行该步骤时，两条都为空的情况下p就指向空
                 * 而单条为空时p指向非空
                 */
                p = p.next;

                //可以排除两条同时为空的情况
                while(p != null){
                    i = (p.val + j) / 10;
                    p.val = (p.val + j) % 10;
                    j = i;
                    p = p.next;
                    q = q.next;
                }
            }

            //当处理完所有后如果还有进位要另开一个节点存储，p已经为空了，要用q来处理
            if(j != 0){
                ListNode temp = new ListNode(j);
                temp.next = null;
                q.next = temp;
            }

            return dummyHead.next;
        }
    }