class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) return;
        if(data.size() == 2) {
            (*num1) = data[0];
            (*num2) = data[1];
            return;
        }
        
        int sign = data[0];
        for(int i = 1; i < data.size(); ++i) {
            sign ^= data[i];
        }
        
        if(sign == 0) return;
        
        int loc = 0;
        for( ; loc < 32; ++loc) {
            if( ( (sign >> loc) & 0x01) == 0x01) break;
        }
        
        //找出第一个
        *num1 = 0;
        *num2 = 0;
        int symbol = 0x01 << loc;
        for(int i = 0; i < data.size(); ++i) {
            if( (data[i] & symbol) == symbol)
                (*num1) ^= data[i];
            else
                (*num2) ^= data[i];
        }
    }
};