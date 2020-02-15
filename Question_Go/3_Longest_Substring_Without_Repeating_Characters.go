func lengthOfLongestSubstring(s string) int {
    ans := 0
    mem := make(map[byte] int) //char, location

    for left, right := 0, 0; right < len(s); right++ {
        if loc, ok := mem[s[right]]; !ok || loc < left {
            len := right - left + 1
            if len > ans {
                ans = len
            }
        } else {
            left = loc + 1
        }
        mem[s[right]] = right
    }

    return ans
}