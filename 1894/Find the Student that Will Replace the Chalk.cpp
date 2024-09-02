 // Find the Student that Will Replace the Chalk.cpp

typedef long long ll;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum = 0;

        for(int i=0; i<chalk.size(); i++) {
            sum += chalk[i];
            if(sum > k){
                return i;
            }
        }

        ll mod =  k % sum;

        if(mod == 0) {
            return 0;
        }

        sum = 0;
        for(int i=0; i<chalk.size(); i++) {
            sum += chalk[i];
            if(sum > mod) {
                return i;
            }
        }

        return 0;
    }
};