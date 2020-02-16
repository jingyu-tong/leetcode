func isPalindrome(x int) bool {
    if x < 0 { //negative
        return false
    }
    if x != 0 && x % 10 == 0 { //avoid the first number is 0
        return false
    }

    ans := 0
    for ans < x {
        ans = ans * 10 + x % 10
        x /= 10
    }

    return x == ans || x == ans / 10
}