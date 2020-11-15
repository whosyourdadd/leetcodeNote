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
/*
1.建立dummy的node，指到head
2.累加每個node的和，而且把當前的和和node的指標傳入hash map
3.如果發現目前的和已經有出現在hash map當中，則把hash map的node的next指到curr->next，並把之間的node全部從hash map刪掉
*/
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int sum = 0;
        map<int, ListNode*> m;
        ListNode *dummy = new ListNode(0), *curr;
        dummy->next = head;
        curr = dummy;
        //1.建立dummy的node，指到head
        while(curr){
            sum += curr->val;//2.累加每個node的和，而且把當前的和和node的指標傳入hash map
            //cout<<"sum "<<sum<<" "<<curr->val<<endl;
            if(m.find(sum) != m.end()){
                ListNode* node = m[sum]->next; 
                int tsum = sum + node->val;
                //cout<<"tsum = sum "<<tsum<<" "<<sum<<" "<<node->val<<endl;
//3.如果發現目前的和已經有出現在hash map當中，則把hash map的node的next指到curr->next，並把之間的node全部從hash map刪掉
                while(tsum != sum){//一直到值相同才結束
                    //cout<<"1.tsum "<<tsum<<" "<<sum <<" "<<node->val<<endl;
                    m.erase(tsum);
                    node = node->next;
                    tsum += node->val;
                    //cout<<"2.tsum "<<tsum<<" "<<sum <<" "<<node->val<<endl;
                }
                m[sum]->next = curr->next;
            }else{
                m[sum] = curr; //沒找到相同的，用 "array" 方式插入
            }
            curr = curr->next;
        }
        ListNode* tmp = dummy->next;
        delete dummy;
        return tmp;
        
    }
};
