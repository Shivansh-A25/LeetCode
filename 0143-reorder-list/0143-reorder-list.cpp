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
    ListNode* Reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head ;
        while(curr!=NULL){
            ListNode* forward = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = forward ;
        }
        return prev ;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode* slow = head ;
        ListNode* fast = head->next ;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        
        ListNode* Second = slow->next ;
        slow->next = NULL ;
        Second = Reverse(Second);
        ListNode* first = head ;

        while(Second!=NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2 = Second->next;

            first->next = Second;
            Second->next = temp1;

            first = temp1;
            Second = temp2;
        }
    }
};