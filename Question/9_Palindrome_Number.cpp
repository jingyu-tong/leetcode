//翻一半
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x % 10 == 0 && x != 0) return false; //avoid the last number is 0

        int reverse = 0;
        while(x > reverse) {
            reverse = reverse * 10 + x % 10;
            x = x / 10;
        }
        return x == reverse || x == reverse / 10;
    }
};

//整个儿翻
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x % 10 == 0 && x != 0) return false;

        int reverse = 0;
        int num = x;
        while(num != 0) {
            if(reverse > INT_MAX / 10) return false;
            reverse = reverse * 10 + (num % 10);
            num /= 10;
        }
        return reverse == x;
    }
};
