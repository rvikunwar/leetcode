// Shortest Path in a Grid with Obstacles Elimination

// You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

// Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

class Solution {

    bool isValid(int newRow, int newCol, int rows, int cols){
    	if(newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0) return false;
    	return true;
    }

	public:
	    int shortestPath(vector<vector<int>>& grid, int k) {
					int rows = grid.size();
					int cols = grid[0].size();
	        vector<int> start = { k, 0, 0 };
	        queue<vector<int>> q;
					unordered_set<string> visited;
					visited.insert(to_string(0)+ " " + to_string(0) + " " + to_string(0));
	        q.push(start);
	        int steps = 0;

	        int delRows[] = {1, 0, -1, 0};
	        int delCols[] = {0, -1, 0, 1};

	        while(!q.empty()){
	        	int size = q.size();

	        	for(int k=0; k<size; k++){
	        		vector<int> front = q.front();
	        		q.pop();
	        		int obs = front[0];
	        		int row = front[1];
	        		int col = front[2];

	        		if(row == rows-1 && col == cols-1) return steps;

	        		for(int m=0; m<4; m++){
	        			int obs = front[0];
	        			int newRow = delRows[m] + row;
	        			int newCol = delCols[m] + col;

	        			if(isValid(newRow, newCol, rows, cols)){
	        				if(grid[newRow][newCol] == 1 & obs > 0){
	        					obs--;
								if(!visited.count(to_string(obs)+ " " + to_string(newRow) + " " + to_string(newCol))){
									visited.insert(to_string(obs)+ " " + to_string(newRow) + " " + to_string(newCol));
									q.push({obs, newRow, newCol});
								}
	        				} 

	        				if(grid[newRow][newCol] == 0){
	        					if(!visited.count(to_string(obs)+ " " + to_string(newRow) + " " + to_string(newCol))){
									visited.insert(to_string(obs)+ " " + to_string(newRow) + " " + to_string(newCol));
									q.push({obs, newRow, newCol});
								}
	        				}
	        			}	
	        		}
	        	}
	        	steps++;
	        }
	        return -1;
	    }
};