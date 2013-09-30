//Author: Cristobal A Guerrero
//Class: CSE 330
//This program changes a infix expression to a post fix expression
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cstdlib>
using namespace std;

bool lower_eq_prec(char x, char y){
	return((x=='+' or x=='-') and (y=='*' or y=='/'));
}

int main(){
stack<char> postfix;
string infix;
char previous;
int n = 0;
while(n<3){
cout<< "Enter in a infix expression: ";
cin >> infix;
cout << "This is your infix expression: " << infix << endl;
cout << "This is your postfix expression: ";
for(int i=0; i<infix.length(); i++){
	//checks to see if the next character is alphanumeric
	if(isalpha(infix[i]) or isdigit(infix[i])){
	    cout << infix[i];
	  }
	//checks for distributive property
	else if(infix[i]=='('){
	    postfix.push(infix[i]);
	  }
	//checks to see if its the end of the parenthesis
	else if(infix[i]==')'){
	    while(postfix.top()!='('){
		//The check for the order of the signs would go here
		cout << postfix.top();
		postfix.pop();
	    }
	    postfix.pop();
	  }
	if(infix[i]=='+' or infix[i]=='-' or infix[i]=='*' or infix[i]=='/'){
	    postfix.push(infix[i]);
	  }
	else{
	    while(!postfix.empty() and postfix.top()!='('){
		cout << postfix.top();
		postfix.pop();
	    }
	  }
}
if(!postfix.empty()){
while(!postfix.empty()){
		//The check for the order of the signs would go here
		//previous = postfix.top();
		//postfix.pop();
		//if(lower_eq_prec(previous, postfix.top())){cout<<"yeah it is";}		
		//Program seems to work without these cases though it would still be needed		
		cout << postfix.top();
		postfix.pop();
	    }
}
cout << endl;
n++;}
return 0;
}
