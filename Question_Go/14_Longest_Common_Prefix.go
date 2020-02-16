func longestCommonPrefix(strs []string) string {
    if len(strs) == 0 {
        return ""
    }
    
    var ans string
    for i := 0; i < len(strs[0]); i++ {
        ch := strs[0][i]
        for j := 1; j < len(strs); j++ {
            if i >= len(strs[j]) || ch != strs[j][i] {
                return ans
            }
        }
        ans += string(ch)
    }
    return ans
}