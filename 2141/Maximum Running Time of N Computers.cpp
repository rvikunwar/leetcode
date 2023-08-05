// You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

// Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

// Note that the batteries cannot be recharged.

// Return the maximum number of minutes you can run all the n computers simultaneously.


#define ll long long
class Solution {
public:

    bool isPossible(ll maxx, int n, vector<int> &bat){
        ll life = 0;
        for(int i=0; i<bat.size(); i++){
            life += bat[i]; 
            if(life >= maxx){
                life -= maxx;
                n--;
            }

            if(n == 0) return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int> &bat) {
        ll sum = 0;
        for(auto it: bat) sum+=it;
        ll r = sum/n, l=1;

        // sort(bat.begin(), bat.end());

        while(r>=l){
            ll mid = l+ (r-l)/2;
            if(isPossible(mid, n, bat)){
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return l-1;
    }
};