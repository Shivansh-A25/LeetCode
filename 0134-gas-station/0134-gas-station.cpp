class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas=0;
        int totCost=0;

        for(int val:gas){
            totGas+=val;
        }

        for(int val2:cost){
            totCost+=val2;
        }

        if(totGas<totCost){
            return -1;
        }

        int n = gas.size();
        int start = 0 ; int currGas = 0;

        for(int i=0;i<n;i++){
            currGas+=gas[i]-cost[i];
            if(currGas<0){
                start = i+1;
                currGas=0;
            }
        }

        return start;
    }
};