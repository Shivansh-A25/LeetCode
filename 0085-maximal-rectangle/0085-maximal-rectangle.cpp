class Solution {
private:
    vector<int> NextSmallestElement(vector<int>& heights,int n){
        stack<int> s;
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            int curr = heights[i];
            while(!s.empty() && heights[s.top()]>=curr){
                s.pop();
            }

            if(s.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = s.top();
            }

            s.push(i);
        }
        return ans ;
    }

    vector<int> PrevSmallestElement(vector<int>& heights,int n){
        stack<int> s;
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            int curr = heights[i];
            while(!s.empty() && heights[s.top()]>=curr){
                s.pop();
            }

            if(s.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = s.top();
            }

            s.push(i);
        }
        return ans ;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> Next = NextSmallestElement(heights,n);
        vector<int> Prev = PrevSmallestElement(heights,n);
        
        int area = - 1  ;
        for(int i=0;i<n;i++){
            int len = heights[i];
            int breadth = Next[i]-Prev[i]-1;
            int newArea = len*breadth;
            area = max(area,newArea);
        }

        return area ;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int area = 0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }

            area = max(area ,largestRectangleArea(heights));
        }

        return area ;
    }
};