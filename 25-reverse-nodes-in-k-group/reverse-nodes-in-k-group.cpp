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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz = 0;
        if(head ==NULL || head->next == NULL || k==1) return head;
        ListNode* dummy = head;
        while(dummy!=nullptr){
            sz++;
            dummy = dummy->next;
        }
        int x = sz/k;
        int t = k-1;

        ListNode fake(0,head);
        dummy = &fake;

        ListNode* prev = dummy;
        ListNode* curr = nullptr;
        while(x--){
            t=k-1;
            ListNode* groupStart = prev->next;
            curr = groupStart->next;
            while(t--){
                ListNode* temp = prev->next;
                prev->next = curr;
                groupStart->next = curr->next;
                curr->next = temp;
                curr = groupStart->next;
            }
            prev = groupStart;
        }
        return dummy->next;
    }
};