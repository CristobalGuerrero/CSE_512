#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

bool lower_eq_prec(char x, char y){
	if((x=='+' or x=='-') and (y=='/' or y=='*'))return 1;
}

int main(){
stack<char> postfix;
string infix;
cout << "Enter in a infix expression: ";
cin >> infix;
cout << infix << endl;


for(int i=0; i<infix.length(); i++)
{
    if(isalpha(infix[i]) or isdigit(infix[i]))
    {	
	cout<< infix[i];
    }
    else if(infix[i]=='('){
    	postfix.push(infix[i]);
    }
    else if(infix[i]==')'){
    	while(postfix.top()!='('){
    	    cout << postfix.top();
    	    postfix.pop();
    	}
    	postfix.pop();
    }
    if(infix[i]=='+' or infix[i]=='*' or infix[i]=='-' or infix[i]=='/'){
        postfix.push(infix[i]);
    }
    else{
       while(!postfix.empty() and postfix.top()!='('){
    	    cout << postfix.top();
    	    postfix.pop();
    	}
    }
}
if(!postfix.empty())
{
  while(!postfix.empty()){
    	    cout << postfix.top();
    	    postfix.pop();
    	}
}
cout << endl;
//condition to test if the stack is empty or not after the program executes
if(postfix.empty())cout<< "Stack is empty!" << endl;

return 0;
}
