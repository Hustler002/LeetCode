class Solution {
public:
    int countTriples(int n) {
        if(n<5) return 0;

        vector<bool> isSquare(n*n +1, false);
        for(int i = 1; i <=n ;i++)
            isSquare[i*i] = true;
        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++){
                int sq = (i*i) + (j*j);
                //double root = sqrt(sq);

                if( sq <= n*n && isSquare[sq]){
                    ans++;
                }
            }
        }
        return ans;
    }
};