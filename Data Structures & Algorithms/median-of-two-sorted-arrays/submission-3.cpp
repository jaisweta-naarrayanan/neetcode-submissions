class Solution {
public:
    int getcntLEmid(vector<int>&nums, int mid){
        int c = 0, n = nums.size();
        //if(n==0) return 0;
        int l_ind = 0, r_ind = n-1;
        while(l_ind<=r_ind){
            int m_ind = l_ind + (r_ind-l_ind)/2;
            if(nums[m_ind] <= mid){
                c = m_ind + 1;
                l_ind = m_ind+1;
            }
            else{
                r_ind = m_ind - 1;
            }
        }
        return c;
    }
    int findkthsmallest(vector<int>&nums1, vector<int>& nums2, int l, int r, int k){
        int ans = r;
        while(l<=r){
            int mid = l + (r-l)/2;
            int cnt = getcntLEmid(nums1, mid) + getcntLEmid(nums2,mid);
            
            if(cnt<k){ // make the mid bigger to find atleast k cnt of nums LE to mid
                l = mid +1;
            }
            else{
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n==0 && m==0) return 0;
        else if (n == 0) {
            //int k = m/2;
            if (m%2 == 0){
                return (nums2[m/2] + nums2[(m/2)-1])/2.0;
                // return (findkthsmallest(nums1, nums2, nums2[0], nums2[m-1], k) 
                //     + findkthsmallest(nums1, nums2, nums2[0], nums2[m-1], k+1))/2.0;
            }
            else //return findkthsmallest(nums1, nums2, nums2[0], nums2[m-1], k);
                return nums2[m/2];
        }
        else if (m == 0) {
            //int k = n/2;
            if (n%2 == 0){
                return (nums1[n/2]+nums1[(n/2) - 1])/2.0;
                // return (findkthsmallest(nums1, nums2, nums1[0], nums1[n-1], k) 
                //     + findkthsmallest(nums1, nums2, nums1[0], nums1[n-1], k+1))/2.0;
            }
            else //return findkthsmallest(nums1, nums2, nums1[0], nums1[n-1], k);
                return nums1[n/2];
        }
        
        int l = min(nums1[0], nums2[0]);
        int r = max(nums1[n-1], nums2[m-1]);
        if((n+m)%2){
            int k = ((n+m)/2) + 1;
            return findkthsmallest(nums1, nums2, l, r, k);
        }
        else{
            int k = ((n+m)/2);
            return (findkthsmallest(nums1, nums2, l, r, k)*1.0 
            + findkthsmallest(nums1, nums2, l, r, k+1))/(2*1.0);
        }
        return 0;
    }
};

// [1 2] [4 5 6] => 7/2, 2,3,4  2 3 => 5 ,3rd, there k == 3, 2 + 
// [1 2 5] [ 5, 6, 8] => 9/2 => 4.5... 4 & 5 ,  k:6/2 = 3&4, 