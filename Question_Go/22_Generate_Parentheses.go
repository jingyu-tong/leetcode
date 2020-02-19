func generateParenthesis(n int) []string {
	if n == 0 {
		return nil
	}

	ans := []string{}
	generate(n, n, "", &ans)
	return ans
}

func generate(left int, right int, cur string, ans *[]string) {
	if left == 0 && right == 0 {
		*ans = append(*ans, cur)
		return
	}
	if left < 0 || right < 0 {
		return
	}
	if left > right {
		return
	}

	//left and right
	generate(left-1, right, cur+"(", ans)
	generate(left, right-1, cur+")", ans)
}