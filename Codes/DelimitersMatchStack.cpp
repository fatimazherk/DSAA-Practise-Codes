#include<iostream>
#include<stack>

using namespace std;

class DelimiterMatching{
public:
bool ExpressionMatch(string s){
    stack<char> stack1;
    //idher stack ko character type liya hai takay string ka har
    //letter ko iterative for loop se check krske
    for(char ch: s){
        if(ch=='{' || ch=='(' || ch=='['){
            stack1.push(ch);
        }else if(ch=='}' || ch==')' || ch==']'){
            if(stack1.empty())
            return false; //brackets match nahi kar rhe
            
            char top=stack1.top();
            if((ch=='}' && top!='{') ||
            (ch==']' && top!='[') ||
            (ch==')' && top!='(')){
                return false; //match nahi kr rha toh sahih nhi
            }
            stack1.pop();
            //agar match kr rha hai toh stack se nikal do
        }
    }
    return stack1.empty();//saray bracket h toh empty h wrna nhi hai thik
}
};

int main(){
    DelimiterMatching d1;
    
    string expression = "(MUB)+{ASH}+[IRSHAH]";
    if (d1.ExpressionMatch(expression)) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }

    // Additional tests
    string test1 = "(MUB)+{ASH}+[IRSHAH]";
    string test2 = "(MUB)+{ASH+[IRSHAH}";
    string test3 = "(MUB)+(ASH)]+{IRSHAH}";

    cout << (d1.ExpressionMatch(test1) ? "Balanced" : "Not Balanced") << endl;
    cout << (d1.ExpressionMatch(test2) ? "Balanced" : "Not Balanced") << endl;
    cout << (d1.ExpressionMatch(test3) ? "Balanced" : "Not Balanced") << endl;

    return 0;

}