//
// Created by toor on 4/3/17.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include "Stack.h"
#include <stdexcept>
#include "Exceptions.h"

namespace cs20a {
    class Calculator {
    public:
        static double evaluate(const char *infix);

        static char *infixToPostfix(const char *infix);

        static double evaluatePostfix(const char *postfix);

        static bool checkDelimiters(const char *infix);

        static bool checkValidChars(const char *infix);


    private:
        static bool isOperator(char ch);

        static bool isValidChar(char ch);

        static int weitght(char ch);
    };

    double Calculator::evaluate(const char *infix) {
        char *postfix = infixToPostfix(infix);

        double result = evaluatePostfix(postfix);

        return result;

    }

    char *Calculator::infixToPostfix(const char *infix) {

        if(!checkDelimiters(infix)||!checkValidChars(infix)) return nullptr;
//        cout <<"2"<<endl;
        Stack<char> operators;
        // postfix is not deleted
        Stack<char> postfix;
        cout <<"1"<<endl;
        for(;*infix;infix++){
//            cout<<*infix<<endl;
            if(*infix=='(') operators.push('(');
            else if(isOperator(*infix)){
                while(!operators.isEmpty()  &&weitght(operators.top())>=weitght(*infix)){
                    postfix.push(' ');
                    postfix.push(operators.pop());
                }
                postfix.push(' ');
                operators.push(*infix);
            }
            else if(*infix==')'){
                while(!operators.isEmpty()){
                    if(operators.top()=='('){
                        operators.pop();
                        break;
                    }
                    postfix.push(' ');
                    postfix.push(operators.pop());
                }
            }else if(*infix==' ') continue;
            else{
                postfix.push(*infix);
            }
        }
        while(!operators.isEmpty()){
            postfix.push(' ');
            postfix.push(operators.pop());
        }
        int length=postfix.getUsed();

        char* copyPostfix = new char[length+1]();
//        char copyPostfix[length]=char [length]();

        char* temp = postfix.getArray();
        char* temp1= operators.getArray();
        for (int i = 0; i < length; i++) {
            copyPostfix[i]=temp[i];
            cout<<copyPostfix[i]<<temp[i]<<endl;
        }

        return copyPostfix;
//
    }

    double Calculator::evaluatePostfix(const char *postfix) {
        Stack<char> stringToConvert;

        Stack<float> operands;
        const char *temp=postfix;
        float operand0;
        float operand1;
        for(int i =0;*(postfix+i);i++){

            if (isOperator(*(postfix+i))){
                operand1=operands.pop();
                operand0=operands.pop();
                switch (*(postfix+i)){
                    case '-':
                        operands.push(operand0-operand1);
                        break;
                    case '+':
                        operands.push(operand0+operand1);
                        break;
                    case '*':
                        operands.push(operand0*operand1);
                        break;
                    case '/':
                        if(operand1==0) {

                            delete[] temp;
//                            delete stringToConvert;
//                            delete operands;
                            throw DivideByZeroException("");
                        }
                        operands.push(operand0/operand1);
                        break;
                    default:
                        break;

                }
//                cout<<operand0<<*postfix<<operand1<<"="<<operands.top()<<endl;
            }
            else if(*(postfix+i)==' '){
//                cout<<"space"<<endl;
                if(stringToConvert.isEmpty()) continue;
                cout<<"stof"<<stringToConvert.getArray()<<endl;
                operands.push(stof(stringToConvert.getArray()));


                stringToConvert.makeEmpty();
                cout<<"test"<<endl;

            }

            else {
                for(int x = 0;x<i;x++){
                    cout<<"wierd symble "<<*(postfix+x)<<" test "<<*(postfix)<<endl;
                }
                cout<<"stringToConvert"<<stringToConvert.getArray()<<" i "<<*(postfix+i-1)<<endl;
                stringToConvert.push(*(postfix+i));
                cout<<"stringToConvert"<<stringToConvert.getArray()<<endl;
            }
        }

        double result =0;
        if(!operands.isEmpty()) result= operands.pop();
        cout<<postfix<<endl;
//        delete[] temp;
//        const char *temp123=postfix+10;
        delete[] postfix;
//        delete[] temp123;
//        for(int i =1;i<15;i++){
//            cout<<postfix[i]<<endl;
//        }
//        delete stringToConvert;
//        delete operands;
        return result;

    }

    bool Calculator::checkDelimiters(const char *infix) {
//        Stack<char>* temp= new Stack<char>();
        Stack<char> x;
        Stack<char> *temp= &x;
        for(; *infix; infix++){
            switch(*infix){
                case '(':

                    temp->push('(');

                    break;
                case ')':

                    if(temp->isEmpty()) {
//                        cout<<"))))"<<endl;
//                        delete temp;
                        throw UnbalancedParenthesesException("");
//                        return false;
                    }

                    temp->pop();
                    break;
                default:
                    break;
            }
        }
        if(!temp->isEmpty()) {

//            cout<<"(((("<<temp->top()<<endl;
//            delete temp;
            throw UnbalancedParenthesesException("");
//            return false;
        }
//        delete temp;

        return true;
    }

    bool Calculator::checkValidChars(const char *infix) {
        for(; *infix; infix++){
            if (!isValidChar(*infix)) {
//                cout<<*infix<<endl;
                throw InvalidCharactersException("");
//                return false;
            }
        }
        return true;
    }

    bool Calculator::isOperator(char ch) {
        switch (ch) {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
            default:
                return false;
        }
    }

    bool Calculator::isValidChar(char ch) {
        if (isOperator(ch) || (ch >= '0' && ch <= '9') || ch == '(' || ch == ')' || ch == ' ' || ch=='.') return true;
        return false;

    }

    int Calculator::weitght(char ch) {
        switch (ch) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            default:
                return 0;
        }


    }
}






#endif //CALCULATOR_CALCULATOR_H
