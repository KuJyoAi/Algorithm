
struct ListNode
{
    int val;
    struct ListNode *next;
};

#include <iostream>

using namespace std;

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr || k == 1)
    {
        return head;
    }
    
    {
        /* code */
    }
    
    // write code here
    ListNode *slow, *fast=head;
    int cnt;
    // 虚拟头结点
    ListNode zero;
    zero.next = head;
    slow = &zero;
    head = slow;

    while (fast)
    {
        cnt = 1;
        // 循环向前
        while (cnt < k)
        {
            fast = fast->next;
            // fast到末尾了, 直接返回
            if (!fast)
            {
                return zero.next;
            }
            cnt++;
        }
        // 翻转
        ListNode *pre, *cur, *nxt, *nxt_fast, *nxt_slow;
        nxt_fast = fast->next;
        nxt_slow = slow->next;

        pre = slow->next;
        cur = pre->next;
        nxt = cur->next;

        slow->next = fast;
        pre->next = nxt_fast;

        while (cur != fast)
        {
            cur->next = pre;
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = pre;

        // 重设slow和fast
        slow = nxt_slow;
        fast = nxt_fast;
    }
    return zero.next;
}

int main(){
    ListNode* test;
    // 1 2 3 4 5
    test = new ListNode{1};
    test->next = new ListNode{2};
    test->next->next = new ListNode{3};
    test->next->next->next = new ListNode{4};
    test->next->next->next->next = new ListNode{5};
    test = reverseKGroup(test, 2);
    while(test){
        cout<<test->val<<" ";
        test = test->next;
    }
    return 0;

}