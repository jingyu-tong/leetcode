func maxArea(height []int) int {
    ans := 0
    left, right := 0, len(height) - 1
    for left < right {
        curH := height[left]
        if curH > height[right] {
            curH = height[right]
        }

        cur := (right - left) * curH
        if cur > ans {
            ans = cur
        }

        if height[left] < height[right] {
            left++
        } else {
            right--
        }
    }
    return ans
}