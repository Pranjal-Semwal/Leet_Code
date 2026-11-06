class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int x=n/2;
        int i=0;
        int j=0;
        while(i<n-1){
            if(nums.at(i)!=nums.at(i+1)){
                if(i-j+1>x) return nums[i];
                else j=i+1;
            }
            i++;
        }
        return nums[n-1];
    }
};