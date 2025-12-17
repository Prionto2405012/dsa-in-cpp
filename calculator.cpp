#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


string postfix(string infix) {
    string ans;
    stack<char> operators;
    int i=0;
    while (i<infix.size()) {
        if (infix[i] ==  ' ');
        else if (infix[i]>='0' && infix[i]<='9') ans.push_back(infix[i]);
        else if (infix[i]=='(') operators.push(infix[i]);
        else if (infix[i]==')') {
            while (!operators.empty() && operators.top()!='(') {
                ans.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
        }
        else {
            if (operators.empty()) operators.push(infix[i]);
            else if (precedence(infix[i])>precedence(operators.top())) operators.push(infix[i]);
            else {
                while (!operators.empty() && precedence(infix[i])<=precedence(operators.top())) {
                    ans.push_back(operators.top());
                    operators.pop();
                }
                operators.push(infix[i]);
            }
        }
        i++;
    }
    while (!operators.empty()) {
        ans.push_back(operators.top());
        operators.pop();
    }
    return ans;
}

double calculate(string str) {
    stack<double> nums;
    str = postfix(str);
    for (int i=0;i<str.size();i++) {
        char c= str[i];
        if (c>='0' && c<='9') {
            nums.push((double)(c-'0'));
        }
        else {
            int op2 = nums.top();
            nums.pop();
            int op1 = nums.top();
            nums.pop();
            double ans;
            switch (c) {
                case '+':
                    ans = (double) op1+op2;
                    break;
                case '-':
                    ans = (double) op1-op2;
                    break;
                case '*':
                    ans = (double) op1*op2;
                    break;
                case '/':
                    ans = (double) op1/op2;
                    break;
            }
            nums.push(ans);
        }
    }
    return nums.top();
}


int main() {
    string s = "5 + 3 * 4 -3 ";
    cout<<calculate(s)<<endl;
}
/*Strategy:
 *1/ if operand is number
 *  ->add directly to output
 *2/ if ( -> push to stack
 *3/ if ) -> while not ( and not empty -> pop and add to output
 *4/ if operator is -> high precedance -> push to stack
 *                  -> equal precedence -> pop add push
 *                  -> while lower precedence -> pop and add -> then push
 *  Now for calculations
 */