class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();

        int low = 0, high = row*col -1;
        int mid;

        while(low <= high){
            mid = low + (high-low)/2;
            int r = mid/col;
            int c = mid%col;

            if(matrix[r][c] == target) return true;

            if(matrix[r][c] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};
