class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=abs(nums[n-1]-nums[i]);
        }
        return sum;
    }
};