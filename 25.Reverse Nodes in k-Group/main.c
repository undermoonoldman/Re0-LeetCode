#include <stdlib.h>
#include <stdio.h>
/*25. Reverse Nodes in k-Group
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

 反转链表每隔 k 个区间中的元素*/



typedef struct ListNode
{
    int val;
    struct ListNode *next;
}*pNode,ListNode;

pNode creatList(int N, int begin)//创建链表，测试用
{
    pNode pHead = (pNode)malloc(sizeof(ListNode));
    pNode p = pHead;
    for(int i = 0 ; i < N ; i++)
    {
        pNode temp = (pNode)malloc(sizeof(ListNode));
        temp->val = begin + i;
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
    return pHead->next;
}

//void swapTwoNodes(struct ListNode* p1, struct ListNode* pre1, struct ListNode* p2, struct ListNode* pre2)//交换链表中某两个节点的位置
//{
//    struct ListNode *temp1 = p1->next;
//    pre1->next = p2;
//    pre2->next = p1;
//    struct ListNode *temp2 = p2->next;
//    p2->next = p1->next;
//    p1->next = temp2;
//}

void reverseRange(struct ListNode* pre1, struct ListNode* post2, int k)//区间反转
{
    struct ListNode *pHead = (struct ListNode*)malloc(sizeof(struct ListNode));//虚拟头节点
    struct ListNode *last = NULL;//上次执行插入的节点
    struct ListNode *p1 = pre1->next;//前闭
    struct ListNode *p = p1;//游标
    for(int i = 0 ; i < k ; i++)//对区间中的节点执行一轮头插，完成了反转
    {
        pHead->next = p;
        p = p->next;
        pHead->next->next = last;
        last = pHead->next;
    }
    pre1->next = pHead->next;//pre1 指向反转后的前闭
    p1->next = post2;//p1 经过反转后，变成了后闭，更改后闭的指向
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    struct ListNode *pHead = (struct ListNode*)malloc(sizeof(struct ListNode));//虚拟头节点
    pHead->next = head;
    struct ListNode *p1 = head;//待反转区间前闭
    struct ListNode *pre1 = pHead;//前闭的前置节点
    struct ListNode *p2 = p1;//待反转区间的后闭(初始化与前闭相同)
    struct ListNode *pre2 = pre1;//后闭的前置(初始化与前闭的前置相同)

    while(1)
    {
        if(p1 == NULL)//第二次循环用到，待反转的区间前闭为空，直接退出
            break;
        p2 = p1;//第二次循环用到，类似于初始化
        pre2 = pre1;//第二次循环用到，类似于初始化
        for(int i = 1 ; i < k ; i++)//从前闭开始向后 k 个偏移查找后闭
        {
            if(p2 == NULL || pre2 == NULL)//链表从前闭开始不满足 k 个偏移，找不到后闭，直接退出
                break;
            p2 = p2->next;//向后偏移
            pre2 = pre2->next;//向后偏移
        }
        if(p2 == NULL || pre2 == NULL)//这里也要检查
            break;
        reverseRange(pre1, p2->next, k);//反转区间，参数，前置，后置，区间长度
        pre1 = p1;//为下一次反转做准备，p1 经过反转后已经变成了区间的后闭
        p1 = p1->next;//p1 指向下一个待交换区间的前闭
    }
    return pHead->next;
}

void traverseList(pNode p)//遍历打印链表
{
    while(p != NULL)
    {
        printf("%d -> ",p->val);
        p = p->next;
    }
    printf("NULL");
    printf("\n");
}

int main() {
    printf("Hello, World!\n");

    pNode p = creatList(5, 1);
    traverseList(p);
    pNode reversed = reverseKGroup(p, 2);
    traverseList(reversed);
    return 0;
}