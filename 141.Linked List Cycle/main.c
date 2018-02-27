/**141. Linked List Cycle
 * Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?*/


#include <stdbool.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}Node, *pNode;

pNode creatLinkedList()
{
    pNode p1 = (pNode)malloc(sizeof(Node));
    p1->val = 1;

    pNode p2 = (pNode)malloc(sizeof(Node));
    p1->next = p2;
    p2->val = 2;
    p2->next = p1;
    return p1;
}
//快慢指针，起点相同，步长不同，步子大的在有环的情况下会追上步子慢的
bool hasCycle(struct ListNode *head)
{
    if(head == NULL)
        return false;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != NULL && slow != NULL)
    {
        if(fast->next == slow )
            return true;
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;

    }
    return false;
}

#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    bool checkCycle = hasCycle(creatLinkedList());
    if(checkCycle == 0)
        printf("no cycle!\n");
    else
        printf("has cycle!\n");
    return 0;
}