func threeSum(nums []int) [][]int {
    if len(nums) == 0 {
        return nil
    }

    ans := make([][]int, 0, 1)
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        //dedupulicate num i
        if i != 0 && nums[i] == nums[i - 1] {
            continue
        }

        l, r := i + 1, len(nums) - 1
        target := 0 - nums[i]
        for l < r {
            if nums[l] + nums[r] == target {
                ans = append(ans, []int {nums[i], nums[l], nums[r]})
                
                //deduplicate num l & r
                for l < r && nums[l] == nums[l + 1] {
                    l++
                }
                for l < r && nums[r] == nums[r - 1] {
                    r--
                }
                l++
                r--
            } else if nums[l] + nums[r] < target {
                l++
            } else {
                r--
            }
        }
    }
    return ans
}