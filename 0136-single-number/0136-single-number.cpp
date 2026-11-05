class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()){
            if(i==nums.size()-1) return nums[i];
            else if(nums[i]!=nums[i+1]) return nums[i];
            i+=2;
        }
        return -1;
    }
};