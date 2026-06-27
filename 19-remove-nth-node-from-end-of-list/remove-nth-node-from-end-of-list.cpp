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
int size(ListNode* head){
    int idx=0;
    while(head!=NULL) {head=head->next;idx++;}
    return idx;
}
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int a = size(head);
        int x  = (a-n)+1;
       if (x == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        ListNode* curr = head;
        for(int i=1;i<x-1;i++){
            curr=curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;

        return head;

        }
        
        
    };