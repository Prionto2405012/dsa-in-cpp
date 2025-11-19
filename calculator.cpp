#include <iostream>
#include <stack>
using namespace std;

bool is_operator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':return true;
        default:return false;
    }
}
bool is_operator(string s) {
    return is_operator(s[0]);
}
bool higher_order(string s1,string s2) {
    char c1 = s1[0];//comes form arr
    char c2 = s2[0];//comes from stack
    if (c1==c2) return false;
    if (c1=='/') {
        return true;
    }
    else if (c1=='*') {
        if (c2 == '+' || c2 == '-') return true;
        else return false;
    }
    else if (c1 == '+') {
        if (c2 =='-') return true;
        else return false;
    }
    else if (c1=='-') return false;
}
string arr[100];
int element = 0;

bool is_digit(char c) {
    if (c >= '0' && c <= '9') return true;
    else return false;
}
int main() {

    string str;
    getline(cin,str);

    if (str.size()==0 || is_operator(str[0])) {
        cout<<"vag shala";
        return -1;
    }
    int i = 0;
    while (1) {
        while (str[i]==' ') i++;
        if (str[i]== '\0' ) break;
        if (is_digit(str[i])) {
            int start = i;
            while (is_digit(str[i])) {
                i++;
            }
            string temp;
            while (start<i) {
                temp+=str[start];
                start++;
            }
            arr[element] = temp;
            element++;
        }
        else if (is_operator(str[i])) {
            if (str[i+1]!='\0' && is_operator(str[i+1])) {
                cout<<"vag shala";
                return -1;
            }
            string temp;
            temp += str[i];
            arr[element] = temp;
            element++;
            i++;
        }
    }
    for (int j=0;j<element;j++) {
        cout<<arr[j]<<endl;
    }
    //so far tokenization is done
    //now arr contains the tokens
    stack<string> postfix,operators;
    for (int j=0;j<element;j++) {
        if (!is_operator(arr[j])) {
            postfix.push(arr[j]);
        }
        else if (is_operator(arr[j])) {
            if (operators.size()==0) {
                operators.push(arr[j]);
            }
            else {

            }
        }
    }
}