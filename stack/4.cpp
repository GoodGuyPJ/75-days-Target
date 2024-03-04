//valid parenthesis
// [{}] {[({})]}  ->valid
// [{(}])   -> not valid

#include<bits/stdc++.h>
using namespace std;
 
bool isValidParenthesis(string expression){
    stack<char> s;
    int n = expression.length();
    for(int i=0; i<n; i++){
        char ch= expression[i];

        if(ch=='(' || ch=='{'|| ch == '['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top = s.top();
                if((ch==')' && top=='(') || (ch==']' && top=='[') || (ch=='}' && top=='{') ){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(s.empty()) return true;
    else return false;
}


 
int main(){
    string str = "[{}](){}";

    cout<<"check if it is valid parenthesis : ";
    cout<<isValidParenthesis(str)<<endl;
 
  return 0;
}