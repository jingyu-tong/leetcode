func letterCombinations(digits string) []string {
    if digits == "" {
		return nil
	}
    letters := []string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"}

    ans := make([]string, 0)
    dfs(digits, 0, letters, "", &ans)
    return ans
}

func dfs(digits string, loc int, letters []string, cur string, ans *[]string) {
    if loc == len(digits) {
        *ans = append(*ans, cur)
        return
    }

    for _, ch := range letters[int(digits[loc] - '0')] {
        dfs(digits, loc + 1, letters, cur + string(ch), ans)
    }
}