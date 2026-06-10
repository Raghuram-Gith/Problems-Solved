class Solution {
private:
    int rows, cols;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
        if (dp[r][c] != 0) return dp[r][c];
        
        int max_len = 1;
        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[r][c]) {
                max_len = max(max_len, 1 + dfs(matrix, nr, nc, dp));
            }
        }
        return dp[r][c] = max_len;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int longest_path = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                longest_path = max(longest_path, dfs(matrix, i, j, dp));
            }
        }
        return longest_path;
    }
};
