class Solution {
public:
    double Power(double base, int exponent) {
        //先处理base特殊
        if(base == 0) return 0;
        if(base == 1) return 1;
        
        if(exponent == 0) return 1;
        if(exponent == 1) return base;
        
        if(exponent < 0) return Power(1 / base, -exponent); //负数，处理
        
        double part = Power(base, exponent >> 1);
        part *= part;
        if(exponent % 2 == 1)
            part *= base;
        return part;
    }
};