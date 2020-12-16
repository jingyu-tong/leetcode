class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode dummy = new ListNode(0);
        ListNode prev = dummy;
        while (head != null && head.next != null) {
            prev.next = head.next;
            head.next = head.next.next;
            prev.next.next = head;
            prev = head;
            head = head.next;
        }
        return dummy.next;
    }
}
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode node = head.next;
        head.next = swapPairs(node.next);
        node.next = head;
        return node;
    }
}
