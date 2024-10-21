// Minimum Difference in Sums After Removal of Elements.cpp
// https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/?envType=problem-list-v2&envId=dynamic-programming&difficulty=HARD

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<ll> preMin(n+1, 0);
        vector<ll> sufMax(n+1, 0);

        priority_queue<int> pqMax;
        ll sumMin = 0;
        for(int i=0; i<n; i++) {
            sumMin += nums[i];
            pqMax.push(nums[i]);
        }
        preMin[0] = sumMin;
        int preIndex = 1;
        int i=n;
        while(i < 2*n) {
            pqMax.push(nums[i]); 
            int top = pqMax.top();
            pqMax.pop();
            sumMin = (sumMin - top + nums[i]);
            preMin[preIndex] = sumMin;
            preIndex++;
            i++;
        }


        priority_queue<int, vector<int>, greater<int>> pqMin;
        ll sumMax = 0;
        for(int i=3*n-1; i>=2*n; i--) {
            sumMax += nums[i];
            pqMin.push(nums[i]);
        }
        sufMax[n] = sumMax;
        int sufIndex = n-1;
        i=2*n-1;
        while(i >= n) {
            pqMin.push(nums[i]); 
            int top = pqMin.top();
            pqMin.pop();
            sumMax = (sumMax - top + nums[i]);
            sufMax[sufIndex] = sumMax;
            sufIndex--;
            i--;
        }

        ll ans = LLONG_MAX;
        for(int i=0; i<=n; i++) {
            ans = min(ans, preMin[i] - sufMax[i]);
        } 

        return ans;
    }
};

