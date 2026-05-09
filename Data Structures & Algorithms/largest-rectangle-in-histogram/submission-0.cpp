class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // find 1st min in left and right, 
        // and sub to get width that maintains the curr height.
        int n = heights.size();
        vector<int> lmin(n), rmin(n);
        // lmin[0] = -1;
        // rmin[n-1] = n;
        stack<int> st1, st2;
        for(int i=0; i<n; i++){
            while(!st1.empty() && heights[st1.top()] >= heights[i]){
                st1.pop();
            }
            if(!st1.empty()) lmin[i] = st1.top();
            else lmin[i] = -1;
            st1.push(i);
        }
        
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && heights[st2.top()] >= heights[i]){
                st2.pop();
            }
            if(!st2.empty()) rmin[i] = st2.top();
            else rmin[i] = n;
            st2.push(i);
        }
        cout<<"lmin: ";
        for(int l:lmin) cout<<l<<", ";
        cout<<"rmin: ";
        for(int r:rmin) cout<<r<<", ";

        int ans = 0;
        for(int i=0; i<n; i++){
            int w = rmin[i]-lmin[i]-1;
            ans = max(ans, w*heights[i]);
        }
        return ans;
    }
};
