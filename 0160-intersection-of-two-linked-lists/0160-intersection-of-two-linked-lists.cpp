/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1 = 1 ;
    ListNode* temp1 = headA ;
    while(temp1!=NULL){
        temp1 = temp1->next ;
        len1++;
    }
    int len2 = 1 ;
    ListNode* temp2 = headB ;
    while(temp2!=NULL){
        temp2 = temp2->next ;
        len2++;
    }
    if(len1>len2){
        int diff = len1 - len2 ;
        while(diff!=0){
            headA = headA->next;
            diff--;
        }
    }else if(len2>len1){
        int diff = len2-len1;
        while(diff!=0){
            headB = headB->next;
            diff--;
        }
    }

    ListNode* curr1 = headA;
    ListNode* curr2 = headB;

    while(curr1!=NULL ){
        if(curr1 == curr2){
            return curr1 ;
        }
        else{
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }

    return NULL;
    }
};