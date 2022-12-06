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
    void print(ListNode* temp){
        while(temp!=nullptr){
            cout << temp->val << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
    void insert(ListNode* &root,int val){
        ListNode* curr=new ListNode(val);
        curr->next=NULL;
        ListNode* ptr;
        if(root==NULL){
            root=curr;
        }else{
            ptr=root;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=curr;
        }
    }
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* odd=NULL;
        ListNode* even=NULL;
        int index=1;
        while(head!=nullptr){
            int val=head->val;
            if(index%2==0){
                insert(even,val);

            }else{
                insert(odd,val);
            }
            head=head->next;
            index++;
        }
        //print(odd);
        //print(even);
        ListNode * curr=odd;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=even;
        return odd;
    }
};