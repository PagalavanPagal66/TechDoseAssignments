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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>res;
        for(auto i:lists){
            ListNode* temp=i;
            while(temp!=nullptr){
                res.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(res.rbegin(),res.rend());
        ListNode* ans=nullptr;
        for(int i=0;i<res.size();i++){
            ans=new ListNode(res[i],ans);
        }
        return ans;
    }
};