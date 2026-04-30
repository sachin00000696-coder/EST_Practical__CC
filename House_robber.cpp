class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        vector<int> dp(n,-1);
       
        return helper(nums,0 ,n-1,dp);
        
    }
    int helper(vector<int>& nums,int i ,int j,vector<int>& dp){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i]!=-1) return dp[i];
        int take;
        int skip;

        if(i==0 && j==nums.size()-1){
            take=nums[i]+helper(nums,i+2,j-1,dp);
            skip=helper(nums,i+1,j,dp);
        }
        else{
            take=nums[i] +helper(nums,i+2,j,dp);
            skip=helper(nums,i+1,j,dp);
        }
        return dp[i]= max(take,skip);
       

    }
};
