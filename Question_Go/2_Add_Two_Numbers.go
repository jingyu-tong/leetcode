/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := &ListNode{}
    cur := dummy
    carry := 0

    for l1 != nil || l2 != nil || carry != 0  {
        temp := 0
        if l1 != nil {
            temp += l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            temp += l2.Val
            l2 = l2.Next
        }
        temp += carry
        cur.Next = &ListNode{}
        cur = cur.Next
        cur.Val = temp % 10
        carry = temp / 10
    }

    return dummy.Next
}