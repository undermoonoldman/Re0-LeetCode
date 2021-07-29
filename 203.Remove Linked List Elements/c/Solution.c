struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode *Head = (struct ListNode*)malloc(sizeof(struct ListNode));
    Head->next = head;
    if(head == NULL)
        return NULL;
    struct ListNode *pre = Head;
    struct ListNode *p = head;
    struct ListNode *cur;
    while(p)
    {
        cur = p;
        if(cur->val == val)
        {
            pre->next = cur->next;
        }
        else
        {
            pre = p;
        }        
        p = p->next;
    }
    return Head->next;
}