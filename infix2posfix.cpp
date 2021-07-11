#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// nama kelompok : 
//Muhammad Arif A.F - 1907051020
//Muhammad Rasyid Singgih - 1907051014
//Muhammad Zulfikar - 2017051052

vector <string> realInfix;
vector <string> postfix;

bool isOperator(char checkOp);
int prcd(char checkPre);
void parsingInfix(string inpString);
void infixPostfix();


int main(){
    string rawInfix;
    char inpCh;
    while(cin.get(inpCh)){
        if(inpCh == '\n'){
            break;
        }
        else if(inpCh != ' '){
            rawInfix.push_back(inpCh);
        }
    }
    parsingInfix(rawInfix);
    infixPostfix();
    return 0;
}

bool isOperator(char checkOp){
    return (checkOp == '*' || checkOp == '/' || checkOp == '+' || checkOp == '-' || checkOp == '%');
}

int prcd(char checkPre){
    if(checkPre == '*' || checkPre == '/' || checkPre == '%'){
        return 4;
    } else{
        return 2;
    }
}

void parsingInfix(string inpString){
    string tampung;

    for(unsigned int i = 0; i < inpString.length(); i++)
    {
        if((i == 0 && inpString[i] == '-' && inpString[i + 1] != '(') || isdigit(inpString[i])){
            tampung.push_back(inpString[i]);
            continue;
        }
        else if(tampung.length() != 0){
            realInfix.push_back(tampung);
            tampung.clear();
        }
        if(inpString[i] == '-' && ((isOperator(inpString[i - 1]) || inpString[i - 1] == '(') || (i == 0 && inpString[i + 1] == '('))){
            realInfix.push_back("-1");
            realInfix.push_back("*");
        }
        else if(inpString[i] != ' '){
            realInfix.push_back(inpString.substr(i, 1));
        }
    }
    if(tampung.length() != 0)
    {
        realInfix.push_back(tampung);
        tampung.clear();
    }
 
}

void infixPostfix(){
    stack <string> opStack;
    vector <string>::iterator itr;
    int i = 0;
    for(itr = realInfix.begin(); itr != realInfix.end(); itr++, i++)
    {
        if(isdigit(realInfix[i].back())){
            postfix.push_back(realInfix[i]);
        }
        else if(realInfix[i] == "("){
            opStack.push(realInfix[i]);
        }
        else if(realInfix[i] == ")"){
            while(!opStack.empty() && opStack.top() != "("){
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.pop();
        }
        else if(isOperator(realInfix[i][0])){
            if(opStack.empty() || opStack.top() == "("){
                opStack.push(realInfix[i]);
            }
            else{
                while(!opStack.empty() && opStack.top() != "(" && (prcd(realInfix[i][0]) <= prcd((opStack.top())[0]))){
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(realInfix[i]);
            }
        }
    }
    while(!opStack.empty()){
        postfix.push_back(opStack.top());
        opStack.pop();
    }
    
     cout << "Print : ";
    for(itr = postfix.begin(); itr != postfix.end(); itr++){
        cout << *itr << " ";
    }
}

