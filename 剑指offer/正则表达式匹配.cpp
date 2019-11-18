class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(!str || !pattern) return false;
        
        return matchCore(str, pattern);
    }
    bool matchCore(char* str, char* pattern) {
        if(*str == '\0' && *pattern == '\0') return true;
            
        if(*str != '\0' && *pattern == '\0') return false;
        
        if(*(pattern + 1) == '*') {
            //any times
            if(*str == *pattern || (*pattern =='.' && *str != '\0')) {
                return matchCore(str + 1, pattern + 2)
                        || matchCore(str + 1, pattern)
                        || matchCore(str, pattern + 2);
            } else {
                //不等，只能忽略
                return matchCore(str, pattern + 2); 
            }
        }
        
        //不是*
        if(*str == *pattern || (*pattern == '.' && *str != '\0')) 
            return matchCore(str + 1, pattern + 1);
        return false;
    }
};