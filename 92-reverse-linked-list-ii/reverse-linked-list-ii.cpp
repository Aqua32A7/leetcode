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
    ListNode* solve(ListNode* root,int left,int right){
        ListNode* prev=NULL;
        ListNode* curr=root;
        ListNode* tail=root;
        while(left<=right){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            left++;
        }
        tail->next=curr;
        return prev;
    }



    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        if (left == 1) {
            return solve(head, left, right);
        }

        ListNode* root=head;
        int c=1;
        while(root!=NULL){
            if(c==left-1){
                root->next=solve(root->next,left,right);
                break;
            }
            root=root->next;
            c++;
        }

        return head;

        
    }
};