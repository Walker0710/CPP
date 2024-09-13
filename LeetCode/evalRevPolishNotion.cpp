#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//1st approch
int evalRPN(vector<string>& tokens) {

    stack<int> s;

    for(int i = 0; i<tokens.size(); i++) {

        string yo = tokens[i];
        char element = stoi(yo);

        if(element == '+' || element == '-' || element == '*' || element == '/') {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            switch (element) {

            case '+':
            int toPush = a+b;
            s.push(toPush);
            break;

            case '-':
            int toPush = b-a;
            s.push(toPush);
            break;

            case '*':
            int toPush = a*b;
            s.push(toPush);
            break;

            case '/':
            int toPush = b/a;
            s.push(toPush);
            break;
            }
        }

        if(element < '9' && element > '0') {

            s.push(element);
        }
    }

    return s.top();
}

//2nd aproch
    bool isOperator(string token){
        if(token == "+" || token == "-" || token == "*" || token == "/")return true;
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {

        int evaluated_result = 0;
        stack<int>myStack;

        for(int i = 0 ; i < tokens.size() ; i++){
            string token = tokens[i];
            if(isOperator(token)){
                // If the current token is an operator
                int operand_first = myStack.top();
                myStack.pop();
                int operand_second = myStack.top();
                myStack.pop();
                int temp_result;
                if(token == "/"){
                    temp_result = operand_second / operand_first;
                }else if(token == "*"){
                    temp_result = operand_second * operand_first;
                }else if(token == "-"){
                    temp_result = operand_second - operand_first;
                }else if(token == "+"){
                    temp_result = operand_second + operand_first;
                }
                myStack.push(temp_result);
            }else{
                // Current token is an operand
                myStack.push(stoi(token));
            }
        }
        evaluated_result = myStack.top();
        return evaluated_result;
    }