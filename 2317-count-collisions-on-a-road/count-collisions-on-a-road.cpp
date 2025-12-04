class Solution {
public:
    int countCollisions(string dir) {
        // Approach 2 : single loop 
        // T.C. = O(N);
        // S.C. = O(1)
       int n = dir.length();
       //Skip kro jo left nikal jayengi and right nikal jayengi
       int start = 0, end = n-1;
       while(start < n && dir[start] == 'L') start++;
       while(  end>=0 && dir[end] == 'R') end--;
       long long ans = 0;
        int cntR = 0;
        for(int i = start; i <= end; i++){
            if(dir[i] == 'R'){
                cntR++;
            }
            else if(dir[i] == 'L'){
                ans+= cntR+1;
                cntR=0;
            }
            else {
                ans+= cntR;
                cntR=0;
            }
        }
        return ans;

    }
};

 // Approach 1 : Stack based
//    T.C. = O(N)
//    S.C. = O(N)
 /*     stack<char> st;
        int cnt = 0;
        for(char& c : dir){
            if(c == 'R'){
                st.push(c);
            }
            else if(c== 'L' && !st.empty()){
                if(st.top() == 'R'){
                    cnt+= 2;
                    st.pop();
                    st.push('S');
                }
                else{
                    cnt+=1;
                }
            }
            else if(c== 'S'){
                while(!st.empty() && st.top() == 'R'){
                    cnt+=1;
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty() && st.top() == 'R'){
            st.pop();
        }
        while(!st.empty()){
            if(st.top() == 'S'){
                st.pop();
            }
            else if(st.top() == 'R'){
                cnt++;
                st.pop();
            }
        }
        return cnt;
*/