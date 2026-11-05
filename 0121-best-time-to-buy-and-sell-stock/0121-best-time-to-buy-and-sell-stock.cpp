class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int best=prices[0];
        int ans=0;
        for(int i=1;i<n;i++){
            best=min(best,prices[i]);
            ans=max(ans,prices[i]-best);
        }
        return ans;
    }
};