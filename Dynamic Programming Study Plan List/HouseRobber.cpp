//https://leetcode.com/problems/house-robber
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
    vector<int> dp(nums.size() + 1, -1);

    return robUtil(0, nums.size(), nums, dp);
}
