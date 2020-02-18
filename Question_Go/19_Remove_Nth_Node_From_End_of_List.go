/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func removeNthFromEnd(head *ListNode, n int) *ListNode {
    if head == nil {
        return nil
    }

    dummy := ListNode{-1, head}
    prev := &dummy
    cur := &dummy
    for i := 0; i < n; i++ {
        cur = cur.Next
    }

    for cur.Next != nil {
        prev = prev.Next
        cur = cur.Next
    }
    prev.Next = prev.Next.Next
    return dummy.Next
}