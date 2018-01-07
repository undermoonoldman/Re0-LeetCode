#include <stdlib.h>
#include <stdio.h>
/*23. Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * 归并 k 条有序的链表*/



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

//struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)//类似选择排序的方法对链表进行归并，每次选出 lists 中头部的最小值(效率低下)
//{
//    struct ListNode* Head = (struct ListNode*)malloc(sizeof(struct ListNode));
//    struct ListNode* q = Head;
//    while(1)//循环终止条件，当 lists 中所有的头结点都遍历到头了，全部指向 NULL
//    {
//        int firstNotNull = 0;//第一个非空头结点指示器
//        int roundMinium = -1;//当前最小头结点在 lists 中的下标
//        for(int i = 0 ; i < listsSize ; i++)
//        {
//            if(lists[i] != NULL)//非空头结点
//            {
//                if(firstNotNull == 0)//第一次遇到，直接赋值
//                {
//                    roundMinium = i;
//                    firstNotNull = 1;
//                }
//                else//之后遇到，比较后赋值
//                    roundMinium = lists[i]->val < lists[roundMinium]->val ? i : roundMinium;
//            }
//        }
//        if(roundMinium == -1)//走了一圈，下标还未更新，说明所有头结点都为空了，所有链表已经归并完毕了，直接退出
//            break;
//
//        q->next = lists[roundMinium];
//        lists[roundMinium] = lists[roundMinium]->next;//更新最小位置头结点
//        q = q->next;
//    }
//    return Head->next;
//}

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


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)//参考 Bottom up mergeSort 的归并逻辑
{
    for(int sz = 1 ; sz < listsSize ; sz += sz)//从 size = 1(也就是每两个链表开始归并)，直到 size >= listsSize(所有的链表都归并到一组了)
    {
        for(int i = 0 ;  i + sz < listsSize ; i += 2*sz)//循环终止条件是不能凑出两条链表进行归并 i+sz 是要归并的第二条链表的位置
            lists[i] = mergeTwoLists(lists[i], lists[i+sz]);//每次归并 i 位置与 i+sz 位置的链表，并把新形成的链表头结点赋值给 list[i]
    }
    return lists[0];
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
    pNode p1 = creatList(5,0);
    pNode p2 = creatList(5,2);
    pNode p3 = creatList(5,3);
    traverseList(p1);
    traverseList(p2);
    traverseList(p3);
    pNode lists[3] = {p1,p2,p3};
    pNode merged = mergeKLists(lists, 3);
    traverseList(merged);

//    pNode p4 = creatList(3, 1);
//    pNode p5 = creatList(3, 2);
//    traverseList(p4);
//    traverseList(p5);
//    pNode lists[2] = {p4,p5};
//    pNode merged = mergeKLists(lists, 2);
//    traverseList(merged);
    return 0;
}