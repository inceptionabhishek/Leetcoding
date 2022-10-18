class Solution {
public:
    int count(int n){
        int len=9;
        int digi=9;
        for(int i=1;i<=n-1;i++){
            len *= digi;
            digi--;
        }
        return len;
    }
    int countNumbersWithUniqueDigits(int n) {
        int tot=0;
        for(int i=1;i<=n;i++){
            // digit length : i
            tot += count(i);
        }
        return tot+1;
    }
};