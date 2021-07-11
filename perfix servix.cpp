#include <iostream>
#include <string>
#include <vector>
using namespace std;

// nama kelompok : 
//Muhammad Arif A.F - 1907051020
//Muhammad Rasyid Singgih - 1907051014
//Muhammad Zulfikar - 2017051052


void Infix(string operan){
	
int Lenght;    
Lenght = operan.length();
    
    cout << "Print : ";
    for (int i=0; i<Lenght; i++) {   
        if(i==0 && operan[i] == '-' && operan[i+1]!= '(')
        {
           cout << operan[i];
        }
        if(operan[i] == '(')
        {
            if(operan[i] == '(' && isdigit(operan[i-1]) && (operan[i-1]) != '-' && (operan[i-1]) != ' ')
            {
                cout << "* ";
            }
            
        }
        if((operan[i]=='-') && (operan[i-1]=='+' || operan[i-1]=='*' || operan[i-1]=='/' || operan[i-1]=='%'))
        {
            if(!isdigit(operan[i]=='-') && (operan[i-1]=='+' || operan[i-1]=='*' || operan[i-1]=='/' || operan[i-1]=='%'))
            {
                cout << "-1 * ";
            }
            else if(isdigit(operan[i]=='-') && (operan[i-1]=='+' || operan[i-1]=='*' || operan[i-1]=='/' || operan[i-1]=='%'))
            {
                cout << operan[i] << " ";
            }
            else if(isdigit(operan[i-1]))
            {
                cout << operan[i] << " ";
            }
        }
        else if(operan[i]=='-'){
            if (isdigit (operan[i-1]) && operan[i+1] == '(') 
            {
                cout << operan[i] << " ";
            }
            else if (!isdigit(operan[i-1]) && operan[i+1] == '(')
            {
                cout << "-1 * ";
            }
            else if (!isdigit(operan[i-1]) && operan[i+1] == ')')
            {
                cout << operan[i] << " ";
            }
            else if (operan[i-1] == ' ' && operan[i+1] == ' ')
            {
                cout << operan[i] << " ";
            }
            else if (isdigit(operan[i-1]))
            {
                cout << operan[i] << " ";
            }
        }
        else if (operan [i] == ' ')
        {
        }
        else if (isdigit(operan[i]))
        {
            if(isdigit(operan[i+1]))
            {
                cout << operan [i];
            }
            else if (!isdigit(operan[i+1]))
            {
                cout << operan[i] << " ";
            }
        }
        else
            cout << operan[i] << " ";
    }
};

int main () 
{
    string operan;
    getline(cin,operan);
    Infix(operan);
}
