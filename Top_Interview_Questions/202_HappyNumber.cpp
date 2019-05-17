/*
**利用HashSet来记录已经出现过的数字
*/
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mem;
        while(n != 1) {
            int sum = 0;
            while(n) {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = sum;
            if(mem.count(n)) break;
            mem.insert(n);
        }
        return n == 1;
    }
};
/*
**非快乐数最后会陷入一个有4的循环，利用这个性质
*/
class Solution {
public:
    bool isHappy(int n) {
        while(n != 1 && n != 4) {
            int sum = 0;
            while(n) {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
