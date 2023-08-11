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
        ios_base::sync_with_stdio(false);
 if(head==NULL || head->next==NULL ||head->next->next==NULL){
     return {-1,-1};
 }
        ListNode* temp2=head->next;
        ListNode* temp3=head->next->next;
      vector<int>v;
      int i=2;
      while(temp3){
          if((head->val<temp2->val)&&(temp3->val<temp2->val)){
              v.push_back(i);
          }
          else if((head->val>temp2->val)&&(temp3->val>temp2->val)){
              v.push_back(i);
          }
          i++;
          head=head->next;
          temp2=temp2->next;
          temp3=temp3->next;
      }
      if(v.size()<2){
           return {-1,-1};
      }
      int mini=INT_MAX;
      for(int i=1;i<v.size();i++){
          mini=min(mini,(v[i]-v[i-1]));
      }
        return {mini,(v[v.size()-1]-v[0])};
    }
};