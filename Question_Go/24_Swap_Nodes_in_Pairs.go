/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}

	dummy := ListNode{}
	dummy.Next = head
	prev := &dummy
	cur := head

	for cur != nil && cur.Next != nil {
		temp := cur.Next
		prev.Next = temp
		cur.Next = temp.Next
		temp.Next = cur
		prev = cur
		cur = cur.Next
	}

	return dummy.Next
}
