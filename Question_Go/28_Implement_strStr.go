func strStr(haystack string, needle string) int {
    n, m := len(haystack), len(needle)
    if m == 0 {
        return 0
    }
    if n < m {
        return -1
    }

    next := make([]int, m)
    next[0] = -1
    i := 0 //main
    t := -1 //mode
    for i < m - 1 {
        if(t < 0 || needle[t] == needle[i]) {
            i++
            t++
            next[i] = t;
        } else {
            t = next[t]
        }
    }

    i = 0
    t = 0
    for i < n && t < m {
        if(t < 0 || haystack[i] == needle[t]) {
            i++
            t++
        } else {
            t = next[t];
        }
    }

    if i == n {
        if t == m {
            return i - t
        } else {
            return -1
        }
    }
    return i - t
}