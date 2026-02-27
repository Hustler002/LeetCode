class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        vector<int> count(3,0);

        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                count[0]++;
            }

            else if(bills[i] == 10){
                if(count[0]>0){
                    count[1]++;
                    count[0]--;
                }
                else return false;
            }
            
            else if(bills[i] == 20){
                if(count[0] >= 1 && count[1] >=1){
                    count[2]++;
                    count[0]--;
                    count[1]--;
                }
                else if(count[0] >= 3){
                    count[2]++;
                    count[0] = count[0] - 3;
                }
                else return false;
                
            }
        }
        return true;
    }
};