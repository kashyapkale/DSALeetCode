//https://leetcode.com/problems/house-robber-ii/submissions/

int robUtil(int i, int n, vector<int>& nums, vector<int> &dp){
    if (i >= n) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }
    int select = nums[i] + robUtil(i + 2, n, nums, dp);
    int ignore = robUtil(i + 1, n, nums, dp);

    return dp[i] = max(select, ignore);
}


int rob(vector<int>& nums) {
    if(nums.size()==1)
        return nums[0];
    vector<int> dp1(nums.size() + 1, -1);
    vector<int> dp2(nums.size() + 1, -1);

    return max(robUtil(0, nums.size()-1, nums, dp1),robUtil(1, nums.size(), nums, dp2));
}
