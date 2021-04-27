import org.junit.Test;

import java.util.Arrays;

import static org.junit.Assert.*;
public class SolutionTest {
    static boolean comp(ListNode l1, ListNode l2) {
        while (l1 != null && l2 != null) {
            if (l1.val != l2.val) return false;
            l1 = l1.next;
            l2 = l2.next;
        }
        return true;
    }
    static ListNode buildList(int[] nums) {
        ListNode dummy = new ListNode();
        ListNode cur = dummy;
        for (int num : nums) {
            cur.next = new ListNode(num);
            cur = cur.next;
        }
        return dummy.next;
    }
    @Test
    public void twoSumTest() {
        int[] nums1 = {2, 4, 3};
        int[] nums2 = {5, 6, 4};
        int[] out = {7, 0, 8};
        ListNode l1 = buildList(nums1);
        ListNode l2 = buildList(nums2);
        ListNode lo = buildList(out);
        assertTrue(comp(lo, Solution.addTwoNumbers(l1, l2)));
    }
}
