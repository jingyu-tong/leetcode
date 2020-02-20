/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func reverseKGroup(head *ListNode, k int) *ListNode {
    dummy := ListNode{}
    dummy.Next = head

    cur := head
    prev := &dummy

    for i := 1; cur != nil; i++ {
        if i % k == 0 { //找到分段
            prev = reverseOneGroup(prev, cur.Next);
            cur = prev.Next;
        } else {
            cur = cur.Next;
        }
    }

    return dummy.Next
}


//逆转(head, tail)范围内的链表元素
func reverseOneGroup(head *ListNode, tail *ListNode) *ListNode {
        last := head.Next
        cur := last.Next
        
        for cur != tail {
            last.Next = cur.Next
            cur.Next = head.Next
            head.Next = cur
            cur = last.Next
        }

        return last
}