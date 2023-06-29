// Shortest Path to Get All Keys

// You are given an m x n grid grid where:

// '.' is an empty cell.
// '#' is a wall.
// '@' is the starting point.
// Lowercase letters represent keys.
// Uppercase letters represent locks.
// You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

// If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

// For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

// Return the lowest number of moves to acquire all keys. If it is impossible, return -1.

class Solution {

	bool isValid(int newRow, int newCol, int rows, int cols){
		if(newRow >= rows || newCol >= cols || newCol < 0 || newRow < 0) return false;
		return true;
	}

	public:
	    int shortestPathAllKeys(vector<string>& grid) {
	    	int rows = grid.size();
	    	int cols = grid[0].size();

	    	int x, y, totalKeys = 0;
	    	for(int i=0; i<rows; i++){
	    		for(int j=0; j<cols; j++){
	    			if(grid[i][j] == '@'){
	    				x = i; y = j;
	    			}

	    			if(grid[i][j] >= 'a' && grid[i][j] <= 'f'){
	    				totalKeys = max(grid[i][j] - 'a' + 1, totalKeys);
	    			}
	    		}
	    	}

            cout<<totalKeys<<endl;

	    	int delRows[] = {1, 0, -1, 0};
	    	int delCols[] = {0, -1, 0, 1};

	    	vector<int> start = { 0, x, y };
	    	queue<vector<int>> q;
	    	q.push(start);
	    	unordered_set<string> visited;
	    	visited.insert(to_string(0) + " " + to_string(x) + " " + to_string(y));
	    	int steps = 0;

	    	while(!q.empty()){
	    		int size = q.size();
	    		for(int k=0; k<size; k++){
	    			vector<int> front = q.front();
	    			q.pop();
	    			if(front[0] == (1 << totalKeys) - 1) return steps;

	    			for(int m=0; m<4; m++){
	    				int key = front[0];
	    				int newRow = delRows[m] + front[1];
	    				int newCol = delCols[m] + front[2];
	    				if(isValid(newRow, newCol, rows, cols) && grid[newRow][newCol] != '#'){
	    					char ch = grid[newRow][newCol];
	    					if(ch >= 'a' && ch <= 'f'){
	    						key |= 1 << (ch - 'a');
	    					}

	    					if(ch >= 'A' && ch <= 'F'){
	    						if((key >> (ch - 'A') & 1) == 0) continue;
	    					}

	    					if(!visited.count(to_string(key)+" "+to_string(newRow)+" "+to_string(newCol))){
	    						visited.insert(to_string(key)+" "+to_string(newRow)+" "+to_string(newCol));
	    						q.push({key, newRow, newCol});
	    					}
	    				}
	    			}
	    		}
	    		steps++;
	    	}

	    	return -1;
	    }
};