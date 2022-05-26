///Verificarea inchiderii corecte a parantezelor

#include<iostream>
#include<string>
#define MAX_SIZE 100

using namespace std;

class Mystack
{
private:

    int A[MAX_SIZE];
    int top;

public:

    Mystack();

    void push(int x);
    void pop();
    int topElement();
    bool isEmpty();
};

Mystack::Mystack()
{
    top = -1;
}

void Mystack::push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        cout << "Stop!! Stiva este plina" << endl;
        return;
    }
    else
    {
        top++;
        A[top] = x;
    }
}

void Mystack::pop()
{
    if (top != -1)
    {
        top--;
    }
    else
    {
        cout << "Stop!! Stiva este goala" << endl;
        return;
    }
}

bool Mystack::isEmpty()
{
    if (top == -1)
        return true;
    return false;
}

int Mystack::topElement()
{
    return A[top];
}


bool ArePair(char opening, char closing)
{
    if (opening == '(' && closing == ')') return true;
    return false;
}

bool AreParanthesesBalanced(string exp, Mystack stack1)
{

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
            stack1.push(exp[i]);

        else if (exp[i] == ')')
        {
            if (stack1.isEmpty() || !ArePair(stack1.topElement(), exp[i]))
                return false;
            else
                stack1.pop();
        }
    }
    return stack1.isEmpty() ? true : false;
}

bool VerificateExpressions(string exp)
{
    int i = 0;
    while(i<exp.length()){

        if (exp[i] == '(' && exp[i + 1] == ')') return true;
        else
            if ((exp[i] == '+' && (exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == '%' || exp[i + 1] == '=' || exp[i + 1] == ')')) ||
                (exp[i] == '-' && (exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == '%' || exp[i + 1] == '=' || exp[i + 1] == ')')) ||
                (exp[i] == '*' && (exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == '%' || exp[i + 1] == '=' || exp[i + 1] == ')')) ||
                (exp[i] == '/' && (exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == '%' || exp[i + 1] == '=' || exp[i + 1] == ')')) ||
                (exp[i] == '%' && (exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == '%' || exp[i + 1] == '=' || exp[i + 1] == ')')))
                return true;
            else

                if (
                    ((exp[i] >= 'A' && exp[i] <= 'Z') ||
                        (exp[i] >= 'a' && exp[i] <= 'z') ||
                        (exp[i] >= '0' && exp[i] <= '9') ||
                        exp[i] == '+' || exp[i] == '-' ||
                        exp[i] == '*' || exp[i] == '/' ||
                        exp[i] == '%' || exp[i] == '=' ||
                        exp[i] == '.' || exp[i] == ',' ||
                        exp[i] == '(' || exp[i] == ')' || exp[i] == ' ')
                    )i++; else return true;
        }
      
    return false;
    }

int AreParantheses(string exp)
{
    int k = 0;

    for (int i = 0; i < exp.length(); i++)
        if (exp[i] == '(' || exp[i] == ')') k++;

    return k;
}


#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main(cli::array<System::String^> ^ args)
{   
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    verificareparanteze::MyForm form;
    Application::Run(% form);

 
  
}


