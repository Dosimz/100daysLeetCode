#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int first = 0;
        int last = 0;
        int e_num = 0;
        int record = bookings.size();
        vector<vector<int>> matrix(n, vector<int>(record, 0));
        for(int i=0; i<record; i++){
            first = bookings[i][0];
            last = bookings[i][1];
            e_num = bookings[i][2];
            while(first<=last){
                matrix[first-1][i] = e_num;
                first++;
            }            
        }
    
        vector<int> answer(n, 0);
        for(int j=0; j<n; j++){
        int sum_nn= 0;
            for(int i=0; i<record; i++){
                sum_nn += matrix[j][i];
            }
            answer[j] = sum_nn;
      }
      return answer;
    }
};

int main(){
    vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    int n = 5;
    Solution s;
    vector<int> answer = s.corpFlightBookings(bookings, n);
    for(auto i:answer){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}