// Last Day Where You Can Still Cross

// There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

// Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

// You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

// Return the last day where it is possible to walk from the top to the bottom by only walking on land cells


class Solution {
    private:
    	bool isValid(int newRow, int newCol, int cols, int rows){
    		if(newRow >= rows || newCol >= cols || newCol <0 || newRow < 0) return false;
    		return true;
    	}

    	bool bfs(int mid, vector<vector<int>> grid){

 			int rows = grid.size();
 			int cols = grid[0].size();

    		unordered_set<string> visited();
    		int delRow[] = { 1, 0, -1, 0 };
    		int delCol[] = { 0, -1, 0, 1 };

    		for(int i=0; i<=mid; i++){
    			grid[cells[i][0]-1][cells[i][1]]-1] = 1;
    		}

    		for(int i=0; i<cols; i++){
    			queue<pair<int, int>> q;
    			q.push({ 0, i });

    			while(!q.empty()){
    				int size = q.size();

    				for(int k=0; k<size; k++){
    					pair<int, int> pr = q.front();
    					q.pop();

    					for(int m=0; m<4; m++){
	    					int newRow = delRow[k] + q.first;
	    					int newCol = delCol[k] + q.second;
		    				if(isValid(newRow, newCol, rows, cols) 
	    						&& grid[newRow][newCol] != 1 && 
	    						!visited.count(to_string(newRow)+" "+to_string(newCol))){

	    						visited.insert(to_string(newRow)+" "+to_string(newCol));
	    						q.push({newRow, newCol});
	    						if(newRow == rows) return true;

	    					}
    					}
    				}
    			}
    		}
    		return false;
    	}

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        int first = 0;
        int last = cells.size()-1;

        int ans = 0;

        while(first<=last){
        	int mid = first + (last-first)/2;

        	if(bfs(mid, grid)){
        		ans = mid;
        		first = mid + 1;
        	} else {
        		last = mid - 1;
        	}
        }
        return ans;
    }
};