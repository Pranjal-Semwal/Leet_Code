class Solution {
public:
    bool canAliceWin(int n) {
        //if(n<10) return false;
        for(int i=10;i>0;i--){
            n=n-i;
            if(i%2==0 && n<0) return false;
            else if(i%2!=0 && n<0) return true;
        }
        return true;
    }
};