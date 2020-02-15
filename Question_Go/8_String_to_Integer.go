func myAtoi(str string) int {
    sign := 1
    ans := 0
    begin := false
    for _, c := range str {
        if c == ' ' {
            if begin {
                break
            }
            continue
        } else if c == '-' {
            if begin {
                break
            }
            sign = -1
            begin = true
        } else if c == '+' {
            if begin {
                break
            }
            sign = 1
            begin = true
        } else if c >= '0' && c <= '9' {
            num := int(c - '0')
            if ans > math.MaxInt32 / 10 {
                if sign == 1 {
                    return math.MaxInt32
                } else {
                    return math.MinInt32
                }
            } else if ans == math.MaxInt32 / 10 && sign == 1 && num > 7 {
                return math.MaxInt32
            } else if ans == math.MaxInt32 / 10 && sign == -1 && num > 7 {
                return math.MinInt32
            }
            ans = ans *10 + num
            begin = true
        } else {
            break
        }
    }
    return ans * sign
}