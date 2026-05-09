class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        {/*
            int rs=0, re=n-1;
            while(rs<re){
                int rm = rs + (re-rs)/2;
                if(matrix[rm][m-1] == target)
                    return true;

                else if(matrix[rm][m-1] < target)
                    rs = rm+1;
                else re = rm;     
            }
            if(rs==re){
                int cs=0, ce=m-1;    
                while(cs<=ce){
                    int cm = cs + (ce-cs)/2;
                    if(matrix[rs][cm] == target)
                        return true;

                    else if(matrix[rs][cm] < target)
                        cs = cm+1;
                    else ce = cm-1;     
                }
            }
            return false;   
        */}

        int l = 0, r = n*m -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int mrow = mid/m;
            int mcol = mid%m;
            int num = matrix[mrow][mcol];
            if(num == target)
                return true;
            else if (num < target)
                l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
