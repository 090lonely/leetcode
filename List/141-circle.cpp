//本方法需要读者对「Floyd 判圈算法」（又称龟兔赛跑算法）有所了解。

//假想「乌龟」和「兔子」在链表上移动，「兔子」跑得快，「乌龟」跑得慢。当「乌龟」和「兔子」从链表
//上的同一个节点开始移动时，如果该链表中没有环，那么「兔子」将一直处于「乌龟」的前方；如果该链表中有环，
//那么「兔子」会先于「乌龟」进入环，并且一直在环内移动。等到「乌龟」进入环时，由于「兔子」的速度快，
//它一定会在某个时刻与乌龟相遇，即套了「乌龟」若干圈。
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
    bool hasCycle(ListNode *head) {
         if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(slow!=fast){//两种情况：要么快慢指针相遇，说明有环的存在。
            if(fast==nullptr || fast->next==nullptr){//要么fast遍历到链表的末尾，也就是已经结束，无环。
                return false;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        return true;

    }
};
