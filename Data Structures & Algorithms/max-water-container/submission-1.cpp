class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxamt=0;
        int n = heights.size();
        int i=0, j=n-1;
        while(i<j){
            int curr = min(heights[i], heights[j]) * (j-i);
            // cout<<curr<<" ";
            maxamt = max(maxamt , curr);
            if(heights[i] < heights[j]) i++;
            else j--;
        }
        return maxamt;
    }
};
