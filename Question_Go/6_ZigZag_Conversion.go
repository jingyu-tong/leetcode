//采用string的slice储存行列，然后再输出
//但是由于go中的string都是不可变的，所以每次+=都会造成复制，效率很低
//而且string的+=必须是字符串，s[i : i + 1]不能写成s[i]
func convert(s string, numRows int) string {
    if numRows <= 1 {
        return s
    }

    vec := make([]string, numRows)
    for i, length := 0, len(s); i < length; {
        //column
        for j := 0; j < numRows && i < length; j++ {
            vec[j] += s[i : i + 1]
            i++
        }

        //row
        for j := numRows - 2; j > 0 && i < length; j-- {
            vec[j] += s[i : i + 1]
            i++
        }
    }

    ans := ""
    for _, rStr := range vec {
        ans += rStr
    }
	return ans
}

//为了提高性能，采用buffer.Buffer当做可变字符串
//from 12ms to 8ms
func convert(s string, numRows int) string {
    if numRows <= 1 {
        return s
    }

    vec := make([]bytes.Buffer, numRows)
    for i, length := 0, len(s); i < length; {
        //column
        for j := 0; j < numRows && i < length; j++ {
            vec[j].WriteByte(s[i])
            i++
        }

        //row
        for j := numRows - 2; j > 0 && i < length; j-- {
            vec[j].WriteByte(s[i])
            i++
        }
    }

    ans := bytes.Buffer{}
    for _, rStr := range vec {
        ans.Write(rStr.Bytes())
    }
    return ans.String()
}