func removeDuplicates(nums []int) int {
	cur := 0
	end := 1
	ans := len(nums)

	for end < len(nums) {
		if nums[cur] == nums[end] {
			ans--
		} else {
			cur++
			nums[cur] = nums[end]
		}
		end++
	}
	return ans
}