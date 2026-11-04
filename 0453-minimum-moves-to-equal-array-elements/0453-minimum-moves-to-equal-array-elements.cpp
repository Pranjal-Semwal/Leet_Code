class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long n=nums.size();
        if(n==1) return 0;
        long long mn=nums[0];
        long long sum=0;
        for(int x:nums){
            mn=min(mn,(long long)x);
            sum+=x;
        }
        return (int)(sum-mn*n);
    }
};