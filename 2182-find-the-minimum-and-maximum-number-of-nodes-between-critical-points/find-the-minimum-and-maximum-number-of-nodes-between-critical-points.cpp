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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1);
        ListNode* last = head;
        ListNode* middle = last->next;
        if(middle == NULL) return ans;

        ListNode* top = middle->next;
        if(top == NULL) return vector<int>{-1,-1};

        int first = -1, curr = -1;
        int maxi = -1 , mini = INT_MAX;
        int idx = 1;

        while(top != NULL){
            if(middle->val > top->val && middle->val > last->val){
                if(first == -1){
                    first = idx;
                } 
                else{
                    maxi = max(maxi , idx-first);
                    mini = min(mini, idx - curr);
                }
                curr = idx;
            }
            else if(middle->val < top->val && middle->val < last->val){
                if(first == -1){
                    first = idx;
                } 
                else{
                    maxi = max(maxi , idx-first);
                    mini = min(mini, idx - curr);
                }
                curr = idx;
            }
           // cout<<" First : "<<first<<" , curr : "<<curr<<" maxi : "<<maxi<<" , mini : " << mini<<endl;
            idx++;
            last = middle;
            middle = top;
            top = top->next;
        }
        if(maxi == -1){
            return ans;
        }
        ans = {mini,maxi};
        return ans;
        
    }
};