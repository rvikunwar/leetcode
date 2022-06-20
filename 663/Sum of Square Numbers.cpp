class Solution {
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        int r = sqrt(c);
        long sq;
        while(a<=r){
            sq = long(a*a)+long(r*r);
            if(sq == c){
                return true;
            }
            else if(sq > c){
                r--;
            } else {
                a++;
            }
        }
        return false;
    }
};
