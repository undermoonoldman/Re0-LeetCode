/*2. Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8*/

#include <stdio.h>
#include <stdlib.h>



 struct ListNode
 {
     int val;
     struct ListNode *next;
 };

typedef struct ListNode Node,*pNode;

pNode createNode(int val)
{
    pNode p = (pNode)malloc(sizeof(Node));
    p->val = val;
    p->next = NULL;
    return p;
}

void traverseList(pNode pHead)
{
    while(pHead)
    {
        printf("%d  ",pHead->val);
        pHead = pHead->next;
    }
    printf("\n");
}
/*由于数是倒序存储的，所以顺着头结点相加即可，题目说了每个结点只存个位数，设立两个指针从两个链表的头开始，相加两数取进位跟余数，余数存在新创建
 * 的结点中，进位保存起来与下次加和的结果相加，然后指针后移，直到两个链表有一个为空*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *Head = (struct ListNode*)malloc(sizeof(struct ListNode));//虚拟头结点
    struct ListNode *p;//遍历指针
    p = Head;
    int i = 0;//保存加和结果，初始化为零
    int j = 0;//保存进位，初始化为零
    while(l1 && l2)//两链表一旦有一个为空就退出循环
    {
        i = (l1->val + l2->val + j) % 10;//当前结点数值相加再加上上次余数为本次加和结果(对十取模得到要存储的结果)
        j = (l1->val + l2->val + j) / 10;//余数
        l1 = l1->next;
        l2 = l2->next;
        struct ListNode *q = (struct ListNode*)malloc(sizeof(struct ListNode));
        q->val = i;
        q->next = NULL;
        p->next = q;
        p = q;
    }

    struct ListNode *l = p;//退出时可能两链表都为空，也可能只有一个链表为空

    if(!l1 || !l2)//同时处理两个都为空或一个为空的情况
    {
        if(!l1)//l1为空，在上边的链表后接上l2的后半部分
            p->next = l2;
        else//反之
            p->next = l1;
        p = p->next;
        while(p)//两个都为空时P为NULL直接退出
        {//不再申请空间
            i = (p->val + j) / 10;
            p->val = (p->val + j) % 10;
            j = i;
            p = p->next;
            l = l->next;
        }
    }

    if(j != 0)//当处理完所有链后如果还有进位要另开一个节点存储
    {
        struct ListNode *q = (struct ListNode*)malloc(sizeof(struct ListNode));
        q->val = j;
        q->next = NULL;
        l->next = q;
    }

    return Head->next;
}

int main() {
    printf("Hello, World!\n");
    pNode pa1 = createNode(1);
    pNode pa2 = createNode(2);
    pNode pa3 = createNode(3);
    pNode pb1 = createNode(4);
    pNode pb2 = createNode(5);
    pNode pb3 = createNode(6);

    pa1->next = pa2;
    pa2->next = pa3;

    pb1->next = pb2;
    pb2->next = pb3;

    printf("pa = ");
    traverseList(pa1);

    printf("pb = ");
    traverseList(pb1);

    pNode psum = addTwoNumbers(pa1,pb1);
    printf("psum = ");
    traverseList(psum);
    return 0;
}