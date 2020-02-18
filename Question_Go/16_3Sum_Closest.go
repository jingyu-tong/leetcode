func threeSumClosest(nums []int, target int) int {
    ans := 0
    diff := math.MaxInt32
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        left, right := i + 1, len(nums) - 1
        for left < right {
            sum := nums[left] + nums[right] + nums[i]
            if(Abs(target - sum) < diff) {
                diff = Abs(target - sum)
                ans = sum
            }

            if sum < target {
                left++
            } else if sum > target {
                right--
            } else {
                return target
            }
        }
    }
    return ans
}

func Abs(num int) int {
    if num < 0 {
        return -num
    }
    return num
}