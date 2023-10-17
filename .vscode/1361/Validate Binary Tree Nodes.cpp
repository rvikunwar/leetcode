// You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.
// If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
// Note that the nodes have no values and that we only use the node numbers in this problem.


class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n, 0);
        vector<int> inDegree(n, 0);

        for(int i=0; i<n; i++){
            if(leftChild[i] != -1){
                int val = leftChild[i];
                inDegree[val]++;
            }
            
            if(rightChild[i] != -1){
                int val = rightChild[i];
                inDegree[val]++;
            }
        }

        stack<int> st;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                st.push(i);
            } else if(inDegree[i] > 1) {
                return false;
            }
        }

        if(st.size() != 1) return false;
        
        while(!st.empty()){
            int currentVal = st.top();
            visited[currentVal] = true;
            st.pop();
            if(leftChild[currentVal] != -1){
                int value = leftChild[currentVal];
                if(visited[value]) return false;
                st.push(value);
            }
            
            if(rightChild[currentVal] != -1){
                int value = rightChild[currentVal];
                if(visited[value]) return false;
                st.push(value);
            }
        }

        for(int i=0; i<n; i++){
            if(!visited[i]) return false;
        }

        return true;
    }
};