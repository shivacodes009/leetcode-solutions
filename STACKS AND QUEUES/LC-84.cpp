class Solution {
public:

    vector<int>PSE(vector<int>&heights){
        int n = heights.size();
        // since we want to protect smaller numbers first we will 
        // use increasing stack : 
        stack<int>st;
        vector<int>pse(n,-1);
        for(int i =0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()) pse[i] =st.top();

            // defalut case : 
            st.push(i);
        }
        return pse;
    }
    vector<int>NSE(vector<int>&heights){
        int n = heights.size();
        // monotonic increasing stack form the last index to the first index
        stack<int>st;
        vector<int>nse(n,n);

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        // my approch : we look at the most amomunt of contribution of a certain 
        // value to the area.
        // we take NSE AND PSE for every index thorugh which our range will be breadth
        // then we will simply mupltiply it with the height of the bar 
        // take the max among all the contribution and return it
        int n = heights.size();
        vector<int>pse = PSE(heights);
        vector<int>nse = NSE(heights);
        long long max_area = INT_MIN;
        for(int i = 0; i < n; i++){
            long long left_idx = pse[i]+1;
            long long right_idx = nse[i];
            
            long long area = heights[i] * (right_idx-left_idx);
            max_area = max(max_area,area);
        }
        return max_area;
    }
};