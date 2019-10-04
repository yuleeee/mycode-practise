/*题目描述
在一个排序的链表中，存在重复的结点，
请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* n = new ListNode(-1);
        ListNode* p = pHead;
        ListNode* res = n;
        n->next =pHead;
        while(p!=NULL)
        {
            if(p->next!=NULL&&p->val == p->next->val)
            {
                while(p->next!=NULL&&p->val == p->next->val)
                    p = p->next;
                n->next = p->next;
                p=p->next;
            }
            else
            {
                n = n->next;
                p = p->next;
            }
            
        }
        return res->next;
    }
};