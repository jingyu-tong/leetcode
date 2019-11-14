class Solution {
public:
    void replaceSpace(char *str,int length) {
        int counts = 0;
        for(int i = 0; i < length; ++i) {
            if(str[i] == ' ') ++counts;
        }
        int new_length = length + counts * 2;
        int cur = length - 1;
        for(int i = new_length - 1; i >= 0, cur >= 0; --i) {
            if(str[cur] != ' ') {
                str[i] = str[cur--];
            } else {
                str[i] = '0';
                str[i - 1] = '2';
                str[i - 2] = '%';
                i = i - 2;
                --cur;
            }
        }
         
    }
};