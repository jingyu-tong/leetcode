func twoSum(nums []int, target int) []int {
    mem := make(map[int]int) //(num, index)
    for i, num1 := range nums {
        if j, ok := mem[target - num1]; ok {
            return []int{i, j}
        }
        mem[num1] = i
    }
    return nil
}