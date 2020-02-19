import "container/heap"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
	if lists == nil || len(lists) == 0 {
		return nil
	}

	n := len(lists)
	for n > 1 {
		mid := (n + 1) / 2
		for i := 0; i < n/2; i++ {
			lists[i] = mergeTwoLists(lists[i], lists[i+mid])
		}
		n = mid
	}

	return lists[0]
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := ListNode{}
	cur := &dummy

	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			cur.Next = l1
			l1 = l1.Next
		} else {
			cur.Next = l2
			l2 = l2.Next
		}
		cur = cur.Next
	}

	if l1 != nil {
		cur.Next = l1
	} else {
		cur.Next = l2
	}

	return dummy.Next
}

//建堆

//heap
// An ListHeap is a min-heap of ListNodes.
type ListHeap []*ListNode

func (h ListHeap) Len() int           { return len(h) }
func (h ListHeap) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h ListHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *ListHeap) Push(x interface{}) {
	*h = append(*h, x.(*ListNode))
}

func (h *ListHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func mergeKLists(lists []*ListNode) *ListNode {
	if lists == nil || len(lists) == 0 {
		return nil
	}

	q := ListHeap{}
	for _, list := range lists {
		if list != nil {
			q = append(q, list)
		}
	}

	//建堆 O(n)，在空堆如果一个一个down-up的push，复杂度为O(nlogn)
	//这里init的话，采用的是folyd算法，自top-down的方式建堆
	heap.Init(&q)
	dummy := ListNode{}
	cur := &dummy

	for len(q) != 0 {
		ele := heap.Pop(&q).(*ListNode) //pop的是interface{}，要做类型转换
		cur.Next = ele
		cur = cur.Next
		if ele.Next != nil {
			heap.Push(&q, ele.Next)
		}
	}

	return dummy.Next
}

