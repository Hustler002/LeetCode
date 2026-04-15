class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int i = startIndex;
        int dist = 0;
        int cnt= n;
        while(cnt--){
            if(words[i] == target){
                //ans = dist;
                break;
            }
            dist++;
            i = (i+1) % n;
        }
        cnt = n;
        int dist2 = 0;
        i=startIndex;
        while(cnt--){
            if(words[i] == target){
                
                break;
            }
            dist2++;
            i = (i-1 + n) % n;
        }
        
        int ans =  min(dist, dist2);
        return ans == n ? -1 : ans;
    }
};