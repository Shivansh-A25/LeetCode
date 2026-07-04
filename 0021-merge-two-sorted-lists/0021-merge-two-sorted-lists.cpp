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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* currHead = new ListNode(-1);
        ListNode* temp = currHead;

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->val >= temp2->val) {
                currHead->next = temp2;
                currHead = temp2;
                temp2 = temp2->next;
            } else {
                currHead->next = temp1;
                currHead = temp1;
                temp1 = temp1->next;
            }
        }

        while (temp1 != NULL) {
            currHead->next = temp1;
            currHead = temp1;
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            currHead->next = temp2;
            currHead = temp2;
            temp2 = temp2->next;
        }

        ListNode* ans = temp->next;
        delete temp;
        return ans;
    }
};