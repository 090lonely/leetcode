#include<bits/stdc++.h>
using namespace std;
  //Definition for singly-linked list.
  struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0,head);//设置一个哑节点，用于“计数”并且删除指定节点
        stack<ListNode*> stk;//使用栈的方式实现
        ListNode* cur=dummy;
        while(cur){
            stk.push(cur);
            cur=cur->next;
        }
        for(int i=0;i<n;i++){stk.pop();}
        ListNode* prev=stk.top();
        prev->next=prev->next->next;
        ListNode*ans=dummy->next;
        delete dummy;
        return ans;
    }
};