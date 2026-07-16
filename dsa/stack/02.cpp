#include<bits/stdc++.h>
using namespace std;

int prefixEval(string exp){
  int i = exp.length()-1;
  //create a stack
  stack<int> st;

  for(i; i>=0; i--){
    if(exp[i]>= '0' && exp[i] <= '9'){
      st.push(exp[i]-'0');
    } else {
      int op1 = st.top();
      st.pop();
      int op2 = st.top();
      st.pop();

      switch(exp[i]){
        case '+' :
          st.push(op1 + op2);
          break;
        case '-' :
          st.push(op1 - op2);
          break;
        case '*' :
          st.push(op1 * op2);
          break;
        case '/' :
          st.push(op1 / op2);
          break;
        case '^' :
          st.push(pow(op1, op2));
          break;
      }
    }
  }
  return st.top();
}

int postfixEval(string exp){
  int n = exp.length();
  //create a stack
  stack<int> st;

  for(int i = 0; i<n; i++){
    if(exp[i]>= '0' && exp[i] <= '9'){
      st.push(exp[i]-'0');
    } else {
      int op1 = st.top();
      st.pop();
      int op2 = st.top();
      st.pop();

      switch(exp[i]){
        case '+' :
          st.push(op1 + op2);
          break;
        case '-' :
          st.push(op1 - op2);
          break;
        case '*' :
          st.push(op1 * op2);
          break;
        case '/' :
          st.push(op1 / op2);
          break;
        case '^' :
          st.push(pow(op1, op2));
          break;
      }
    }
  }
  return st.top();
}

int main(){
  string exp = "-+7*45+20";

  cout<<prefixEval(exp);
}