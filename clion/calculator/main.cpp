#include <iostream>
#include "Calculator.h"
using namespace std;
using namespace cs20a;
int main() {

    char* expr[]={

//            "12+(14*10+9)",
//            "7 * 122 - ( 100 + 1/2 ) * 14",
            "((17.2+2.9)*15-12.7)/(7-4.0)",
            "50 * 2 *3 * (6/0)",
            "((17.2+2.9)*15-12.7)/(7-4.0)",
            "5 + ((1 + 2) *4) - 3",
            "12 * (4 + 6)",
            "1+ 2)/10",
            "2.21/6*1.1+(3.145-1.1)",
            "1*2.2+ X",
            "12+(14*10+9)",

    };

    cout<< endl;
    cout<<" "<<"Stack Calculator Assignment"<<endl<<endl;
    int size = sizeof(expr)/sizeof(expr[0]);
    for (int i = 0; i < size; ++i) {
        try{
            cout<<" "<<"Infix Expression: "<< expr[i]<<endl;
//            char *temp =Calculator::infixToPostfix(expr[i]);
//            cout<<" "<< "Postfix Expression: "<< temp<<"nonon"<<endl;
//                        delete[] temp;
//            cout<<" "<< "Postfix Expression: "<< Calculator::infixToPostfix(expr[i])<<"nonon"<<endl;



            cout<<" "<<"Result = "<< Calculator::evaluate(expr[i]);
//            delete[] expr[i];
        }catch(exception& e){
            cout << " "<< expr[i]<< ": "<< e.what();
        }
        cout << endl<<endl;
    }
    return 0;
}