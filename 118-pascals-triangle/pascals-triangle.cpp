class Solution {
public:
    vector<int> getRow(int Rows){
         vector<int>ansRow;
        ansRow.push_back(1);
        int ans=1;
        for(int i=1; i<Rows; i++){
            ans=ans*(Rows-i);
            ans=ans/(i);
            ansRow.push_back(ans);
        }
    return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
       for(int i=1; i<=numRows; i++){
         pascal.push_back(getRow(i));
       }
    return pascal;
    }
};