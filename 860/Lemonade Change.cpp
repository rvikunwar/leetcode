// Lemonade Change.cpp

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> vc(3, 0);

        for(auto it: bills) {
            if(it == 5) {
                vc[0]++;
            } else if(it == 10) {
                if(vc[0] > 0) {
                    vc[0]--;
                    vc[1]++;
                } else {
                    return false;
                }
            } else {
                if(vc[1] > 0 && vc[0] > 0) {
                    vc[1]--;
                    vc[0]--;
                    vc[2]++;
                } else if(vc[0] > 2){
                    vc[0] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};