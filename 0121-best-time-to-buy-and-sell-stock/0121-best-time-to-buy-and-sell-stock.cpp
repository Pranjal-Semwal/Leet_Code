class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=1;
        int best=prices[0];
        int ans=0,res=0;
        while(i<n){
            best=min(best,prices[i]);
            res=prices[i]-best;
            ans=max(ans,res);
            i++;
        }
        return ans;
    }
};