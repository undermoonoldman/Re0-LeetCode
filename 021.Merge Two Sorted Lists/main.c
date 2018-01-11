#include <stdlib.h>
#include <stdio.h>
/*21. Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

 归并两条有序的链表*/



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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)//归并两个有序的链表返回新的头指针
{
    if(!l1)//l1 为空，l2 也为空时，返回 NULL。l2 不为空，返回 l2
        return l2;
    if(!l2)//l1 不为空， l2 为空时，返回 l1
        return l1;
    //l1,l2 都不为空
    struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = ret;

    while(l1 && l2)//循环退出条件，l1 , l2 有一个为空就退出
    {
        if(l1->val > l2->val)
        {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
        else
        {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
    }
    if(!l1)//l1空，把 l2 剩下的续上, l2 为空也不要紧
        p->next = l2;
   else if(!l2)
        p->next = l1;

    return ret->next;
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

    pNode p1 = creatList(3, 1);
    pNode p2 = creatList(3, 2);
    traverseList(p1);
    traverseList(p2);
    pNode merged = mergeTwoLists(p1, p2);
    traverseList(merged);
    return 0;
}