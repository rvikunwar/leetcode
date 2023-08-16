// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.


class Solution {
public:
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     int leftIndex = 0;
    //     int rightIndex = k-1;
    //     int maxValue = INT_MIN;
    //     int maxValueIndex = -1;
    //     map<int, int> mp;

    //     vector<int> ans;

    //     for(int i=0; i<k; i++){
    //         if(maxValue <= nums[i]){
    //             maxValue = nums[i];
    //             maxValueIndex = i;
    //         }   
    //         mp[nums[i]] = i;
    //     }

    //     ans.push_back(maxValue);

    //     if(k == nums.size()) return ans;
        
    //     while(rightIndex < nums.size()-1){
    //         if(mp[nums[leftIndex]] == leftIndex) mp.erase(nums[leftIndex]);            
    //         rightIndex++;
    //         leftIndex++;
    //         mp[nums[rightIndex]] = rightIndex;

    //         if(nums[rightIndex] > maxValue){
    //             ans.push_back(nums[rightIndex]);
    //             maxValue = nums[rightIndex];
    //             maxValueIndex = rightIndex;
    //         } else if(maxValueIndex >= leftIndex){
    //             ans.push_back(maxValue);
    //         } else {
    //             const auto& currentMaxValue = *mp.rbegin();
    //             maxValue = currentMaxValue.first;
    //             maxValueIndex = currentMaxValue.second;
    //             ans.push_back(maxValue);
    //         }
    //     }

    //     return ans;
    // }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(dq.front() == i-k) dq.pop_front();

            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};