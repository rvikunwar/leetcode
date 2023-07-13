// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.


// class Solution {
// private:
//     bool dfs(int val, vector<bool> &visited, vector<vector<int>> &vc, vector<bool> &recStack){
//         if(recStack[val]) return false;
//         if(visited[val]) return true;
//         visited[val] = true;
//         recStack[val] = true;
//         int size = vc[val].size();
//         bool res = true;
//         for(int i=0; i<size; i++){
//             if(res == false) return res;
//             res = dfs(vc[val][i], visited, vc, recStack);
//         }
//         recStack[val] = false;
//         return res;
//     }
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> vc(numCourses);
//         vector<bool> visited(numCourses);
//         vector<bool> recStack(numCourses);


//         for(int i=0; i<prerequisites.size(); i++){
//             vc[prerequisites[i][1]].push_back(prerequisites[i][0]);
//         }

//         for(int i=0; i<numCourses; i++){
//             if(!visited[i] && vc[i].size()>0){
//                 if(!dfs(i, visited, vc, recStack)){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };


class Solution {
    private:
        bool dfs(int val, vector<vector<int>> &vc, vector<bool> &visited, vector<bool> &visitedPath){
            if(visitedPath[val]) return false;
            if(visited[val]) return true;
            visitedPath[val] = 1;
            visited[val] = 1;
            int size = vc[val].size();
            for(int i=0; i<size; i++){
                if(!dfs(vc[val][i], vc, visited, visitedPath)){ return false; }
            }

            visitedPath[val] = 0;
            return true;
        }
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
            const int size = prerequisites.size();
            vector<vector<int>> vc(numCourses);

            vector<bool> visited(numCourses);
            vector<bool> visitedPath(numCourses);

            for(int i=0; i<size ;i++){
                vc[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }

            for(int i=0; i<numCourses; i++){
                if(!visited[i]){
                    if(!dfs(i, vc, visited, visitedPath)) return false;
                }
            }
            return true;
        }
};

