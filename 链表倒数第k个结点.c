/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(pListHead==nullptr)
        return nullptr;
        else 
        {
        ListNode* fast=pListHead;
        ListNode* slow=pListHead;
            //ListNode* tail=pListHead;
        while(k!=0 && fast)
        {
            fast=fast->next;
            --k;
        }
            if(k!=0)
                return nullptr;
            {  while(fast)
             {
                 fast=fast->next;
                 slow=slow->next;
             }
            return slow;
        }
        }
    }
};