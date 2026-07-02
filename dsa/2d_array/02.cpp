#include<bits/stdc++.h>
using namespace std;

void rowSum(int arr[][3], int row, int col){
  for(int i=0; i<row; i++){
    int sum = 0;
    for(int j=0; j<col; j++){
      sum+=arr[i][j];
    }
    cout<<sum<<endl;
  }
}

int main(){
  int arr [4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  rowSum(arr, 4, 3);
}