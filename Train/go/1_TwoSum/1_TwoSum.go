package TwoSum
func twoSum(nums []int, target int) []int {
    mem := make(map[int]int) // value to index
    for i, value := range nums {
        if index, ok := mem[target - value]; ok {
            return []int{i, index}
        }
        mem[nums[i]] = i
    }
    return []int{-1, -1}
}

