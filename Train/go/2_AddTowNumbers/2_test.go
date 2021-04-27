package AddTowNumbers

import (
	"testing"
)

func comp(l1 *ListNode, l2 *ListNode) bool {
	for l1 != nil && l2 != nil {
		if l1.Val != l2.Val {
			return false
		}
		l1 = l1.Next
		l2 = l2.Next
	}
	return true
}

func buildList(nums []int) *ListNode {
	dummy := ListNode{}
	cur := &dummy
	for _, num := range nums {
		cur.Next = &ListNode{
			Val: num,
		}
		cur = cur.Next
	}
	return dummy.Next
}

func TestAddTowNumbers(t *testing.T) {
	nums1 := []int{2, 4, 3}
	nums2 := []int{5, 6, 4}
	numso := []int{7, 0, 8}
	l1 := buildList(nums1)
	l2 := buildList(nums2)
	lo := buildList(numso)
	if !comp(addTwoNumbers(l1, l2), lo) {
		t.Errorf("addTwoNumbers test fail")
	}
}
