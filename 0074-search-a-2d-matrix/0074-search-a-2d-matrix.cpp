class Solution {
public:
    bool check(int row,vector<vector<int>>& matrix,int target){
            int n = matrix.size();
            int m = matrix[0].size();
            int low = 0;
            int high = m-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                if(matrix[row][mid]==target) return true;
                else if(matrix[row][mid]>target) high = mid-1;
                else low = mid+1;
            }
            return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
                int n = matrix.size();
                int m = matrix[0].size();
                for(int i=0;i<n;i++){
                    if(matrix[i][0]>target) break;
                    if(check(i,matrix,target)) return true;
                }
                return false;
    }   
};