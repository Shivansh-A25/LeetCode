class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st ;

        for(string s : operations){
            if(s=="C"){
                st.pop();
            }
            else if(s=="D"){
                int num = st.top();
                st.push(2*num);
            }
            else if(s=="+"){
                int first = st.top();
                st.pop();

                int second = st.top();
                
                st.push(first);
                st.push(first+second);
            }
            else{
                st.push(stoi(s));
            }
        }

        int sum = 0 ;
        while(!st.empty()){
            sum += st.top();
            st.pop(); 
        }

        return sum ;
    }
};