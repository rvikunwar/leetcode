// There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e., the length of the garden is n).

// There are n + 1 taps located at points [0, 1, ..., n] in the garden.

// Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

// Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.


class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> newArr;
        for(int i=0; i<=n; i++) {
            pair<int, int> pr;
            pr.first = i - ranges[i];
            pr.second = ranges[i] + i;
            newArr.push_back(pr);
        }


        sort(newArr.begin(), newArr.end());

        for(int i=0; i<=n; i++) {
            cout<<newArr[i].first<<" "<<newArr[i].second<<endl;
        }

        int taps = 0;
        int currentIdx = 0; 
        int maxRightMost = INT_MIN;

        while(currentIdx <= n) {
            int currentLeft = newArr[currentIdx].first;
            int currentRight = newArr[currentIdx].second;
            if(currentLeft > 0){
                break;
            }
            maxRightMost = max(maxRightMost, currentRight);
            currentIdx++;
        }
        taps++;
        int lastIndex = currentIdx-1;

        if(newArr[lastIndex].second >= n) return taps;

        for(int i=currentIdx; maxRightMost<n; ){
            int rightMost = maxRightMost;
            while(i <= n && newArr[i].first <= maxRightMost) {
                rightMost = max(rightMost, newArr[i].second);
                i++;
            }

            if(rightMost == maxRightMost) {
                return -1;
            }

            taps++;
            maxRightMost = rightMost;
        }

        return taps;
    }
};