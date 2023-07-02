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
    bool hasCycle(ListNode *head) {
        map<ListNode*,int>ms;
        while(head!=NULL){
            if(ms.count(head)>0){
                return true;
            }
            ms[head]=1;
            head=head->next;
        }
        return false;
    }
};