func reverse(x int) int {
    sign := 0
    if x < 0 {
        sign = -1
        x = -x
    } else {
        sign = 1
    }

    ans := 0
    for x != 0 {
        num := x % 10
        x /= 10

        //overflow or not
        if ans > math.MaxInt32 / 10 {
            return 0
        }
        ans = ans * 10 + num
    }

    return ans * sign
}