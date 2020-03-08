func removeElement(nums []int, val int) int {
    cur := 0
    right := 0

    for right < len(nums) {
        if nums[right] != val {
            nums[cur] = nums[right]
            cur++
        } 
        right++
    }
    return cur
}