// min heap 方法
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        PriorityQueue<ListNode> q = new PriorityQueue<>((ListNode l1, ListNode l2)->{
            return l1.val - l2.val;
        });
        // 初始化 heap
        for (ListNode list : lists) {
            if (list != null) q.add(list);
        }

        while (!q.isEmpty()) {
            ListNode l = q.poll();
            cur.next = l;
            cur = cur.next;
            l = l.next;
            if (l != null) q.add(l);
        }
        return dummy.next;
    }
}

// divide and conquer
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        int n = lists.length;
        while (n > 1) {
            int mid = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + mid]);
            }
            n = mid;
        }
        return lists[0];
    }
    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                cur.next = l1;
                l1 = l1.next;
            } else {
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }
        cur.next = l1 == null ? l2 : l1;
        return dummy.next;
    }
}