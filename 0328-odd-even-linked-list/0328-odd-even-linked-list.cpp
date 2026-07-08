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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head ;
        }
        ListNode* temp1 = head ;
        ListNode* temp2 = head->next ;
        ListNode* head2 = temp2;
        ListNode* curr = temp2->next ;
        int count = 1;

        while(curr!=NULL){
            if(count%2!=0){
                temp1->next = curr;
                temp1 = temp1->next;
                curr = curr->next;
                count++;
            }
            else{
                temp2->next = curr ;
                temp2 = temp2->next;
                curr = curr->next ;
                count++;
            }
        }
        temp2->next = NULL ;
        temp1->next = head2;
        return head ;
    }
};