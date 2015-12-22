/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==nullptr)
            return head;
        // write your code here
        ListNode*temp = head;
        int len = 1;
        while(temp->next!=nullptr)
        {
            temp = temp->next;
            len++;
        }
        temp->next = head;
        k %= len;
        ListNode*cur = head;
        int cnt = 1;
        while(cnt<len-k)
        {
            cur = cur->next;
            cnt++;
        }
        ListNode*ret = cur->next;
        cur->next = nullptr;
        return ret;
    }
};
