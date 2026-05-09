class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), gsum = 0, csum = 0;
        vector<int> diff(n);
        // check if our given total gas can cover the cost of doing a circle?
        for(int i=0; i<n; i++){
            gsum += gas[i];
            csum += cost[i];
            diff[i] = gas[i] - cost[i];
        }
        if(gsum<csum) return -1; // circle not possible.
        int sum = 0, i=0, st = 0;  
        // now greedy appr, as their is only one unique soln
        for(int i=0; i<n; i++){
            sum += diff[i];
            if(sum<0){
                st = i+1;
                sum = 0;
            }
        }
        return st;
    }
};
