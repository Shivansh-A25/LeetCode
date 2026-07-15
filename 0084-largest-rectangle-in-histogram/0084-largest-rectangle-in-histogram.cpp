class Solution {
public:
    vector<int> NextSmallerElement(vector<int>&arr , int n){
        stack<int> s ;
        vector<int> ans(n) ;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
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

    vector<int> PrevSmallerElement(vector<int>&arr , int n){
        stack<int> s ;
        vector<int> ans(n) ;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
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

        vector<int> Next = NextSmallerElement(heights,n);
        vector<int> Prev = PrevSmallerElement(heights,n);
        int area = - 1  ;
        for(int i=0;i<n;i++){
            int len = heights[i];
            if(Next[i]==-1){
                Next[i] = n;
            }
            int breadth = Next[i]-Prev[i]-1;
            int newArea = len*breadth;
            area = max(area,newArea);
        }

        return area ;
    }
};