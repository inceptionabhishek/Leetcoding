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
    ListNode* mergeit(ListNode* temp1,ListNode* temp2){
        if(temp1==NULL){
            return temp2;
        }
        if(temp2==NULL){
            return temp1;
        }
        if(temp1->val<=temp2->val){
            temp1->next=mergeit(temp1->next,temp2);
            return temp1;
        }
        else{
            temp2->next=mergeit(temp1,temp2->next);
            return temp2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans;
        ans = NULL;
        if(lists.size()==0){
            return ans;
        }
        if(lists.size()==1){
            return lists[0];
        }
        while(lists.size()>=2){
            ListNode* temp1=lists[0];
            ListNode* temp2=lists[1];
            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(mergeit(temp1,temp2));
        }
        return lists[0];
    }
};