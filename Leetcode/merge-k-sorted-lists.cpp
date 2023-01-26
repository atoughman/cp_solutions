// problem link
// https://leetcode.com/problems/merge-k-sorted-lists/description/

class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* ans = new ListNode(); // dummyNode
        ListNode* trav = ans;

        while(list1 || list2) {
            int val1 = list1 ? list1->val : INT_MAX;
            int val2 = list2 ? list2->val : INT_MAX;

            if(val1 <= val2) {
                trav->next = list1;
                list1 = list1->next;
            } else {
                trav->next = list2;
                list2 = list2->next;
            }
            trav = trav->next;
        }

        return ans->next;
    }

    ListNode* merge_sort(int l, int r, vector<ListNode*>& lists) {
        if(l == r) return lists[l];
        int mid = l + (r-l)/2;

        ListNode* left = merge_sort(l, mid, lists);
        ListNode* right = merge_sort(mid+1, r, lists);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;

        int l = 0;
        int r = n-1;
        return merge_sort(l, r, lists);
    }
};