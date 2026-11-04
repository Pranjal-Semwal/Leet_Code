class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int max=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>max) max=nums[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(max-nums[i]);
        }
        return sum;
    }
};