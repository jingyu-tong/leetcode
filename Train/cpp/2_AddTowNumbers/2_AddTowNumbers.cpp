#include <unordered_map>
#include <vector>
#include <gtest/gtest.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum %= 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        if (carry) cur->next = new ListNode(carry);
        return dummy.next;
    }
};

ListNode* createList(const vector<int>& nums) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (auto& num : nums) {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    return dummy.next;
}
void deleteList(ListNode* l) {
    while(l) {
        ListNode* temp = l->next;
        delete l;
        l = temp;
    }
}

bool comp(ListNode* l1, ListNode* l2) {
    while (l1 && l2) {
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}

TEST(test, case1) {
    vector<int> nums1{2, 4, 3};
    vector<int> nums2{5, 6, 4};
    vector<int> out{7, 0, 8};
    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);
    ListNode* la = createList(out);
    Solution s;
    ListNode* lo = s.addTwoNumbers(l1, l2);
    EXPECT_TRUE(comp(la, lo));
    deleteList(l1);
    deleteList(l2);
    deleteList(lo);
    deleteList(la);
}


