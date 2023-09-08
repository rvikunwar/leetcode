// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vc(numRows);
        for(int i=1; i<=numRows; i++){
            for(int j=0; j<i; j++){
                if(j == 0 || j == i-1){
                    vc[i-1].push_back(1);
                } else {
                    int sum = vc[i-2][j] + vc[i-2][j-1];
                    vc[i-1].push_back(sum);
                }
            }
        }

        return vc;
    }
};