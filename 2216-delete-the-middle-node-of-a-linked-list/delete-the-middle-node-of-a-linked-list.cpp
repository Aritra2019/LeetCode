/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
         if (head == nullptr || head->next == nullptr) {
            // If there's only one node or the list is empty, return nullptr
            delete head;
            return nullptr;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=slow;
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        slow->next=NULL;
        delete(slow);
        return head;
    }
};