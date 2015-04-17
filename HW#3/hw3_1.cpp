#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <string>


using namespace std;

//http://en.cppreference.com/w/c/language/operator_precedence
int op_precedence( string );

bool is_digit(char);
bool is_operator(char);
bool is_operator(string);
bool right_associate(string);

bool calc(const string , int&);

int main()
{
    string input; 
    //char s[] = "-u";
    //string op = s;
    //if(op == "-u") printf("%s\n", op.c_str());
    //printf("%d",op_precedence(s));

    while( getline(cin, input))
    {
        int output = 0;
        if( calc(input,output) )
        {
            //printf("%s\n", input.c_str());
        }
    }
    return 0;
}
//if precedence larger, then return int smaller (priority)

int op_precedence(string str)
{
    if(str == "+u" || str == "-u")
        return 2;
    else if(str == "<<" || str == ">>")
        return 5;
    else if(str == "&&")
        return 11;
    else if(str == "||")
        return 12;

    char op = str[0];
    switch(op)  {
        
        case '!': case '~':
            return 2;
        case '*': case '/': case '%':
            return 3;
        case '+': case '-':
            return 4;
        case '&':
            return 8;
        case '^':
            return 9;
        case '|':
            return 10;
        case '(':
            return 99;
	    default:
 	        return op - 'A';
    }
    return 0; //error


    return 0; //error
}
bool is_digit(char d)
{
    if(d >= '0' && d <= '9')
        return true;
    else
        return false;
}
bool is_operator(char op)
{
    if(op == '!' || op == '*' || op == '/' || op == '%' || op == '+' ||
       op == '~' || op == '-' || op == '&' || op == '^' || op == '|')
        return true;
    else
        return false;
}
bool is_operator(string str)
{
    if(str == "<<" || str == ">>" || str == "&&" || str == "||")
        return true;
    else
        return false;
}
bool right_associate(string op)
{
    if(op == "+u" || op == "-u" || op == "!" || op == "~")
        return true;
    else
        return false;
}
bool calc(const string in, int& out)
{
    queue< string > my_queue;
    stack< string > op_stack;
    int i = 0;

    while( i < in.length() )
    {
        if(in[i] == ' ')
        {
            i++;
            continue;
        }
        if(is_digit(in[i]))
        {
            string _int;
            while( is_digit(in[i]) && i < in.length())
            {
                _int += in[i];
                i++;
            }
            i--;
            my_queue.push(_int);
            //printf("%s\n", my_stack.top().c_str());
        } 
        string _op;
        _op += in[i]; //char can't be assigned to string
        if(in[i] == '(')
        {
            op_stack.push(_op);
        }
        _op += in[i + 1];
        bool _2_char = false; // is 2 char operator
        
        //check 2 char operator first
        if(is_operator(_op))
        {
            while(op_precedence(_op) > op_precedence(op_stack.top()))
            {
                my_queue.push(op_stack.top());
                op_stack.pop();
                if(op_stack.empty())
                    break;
            }
            op_stack.push(_op);
            _2_char = true;
            i++;
        }
        _op.erase(_op.end() - 1); //resize _op into 1 char operator
        if(is_operator(in[i]) && !_2_char)
        {
            bool flag = 1;
            if(_op == "+" || _op == "-") //unary
            {   
                if(i == 0)
                {
                    op_stack.push(_op + "u"); 
                    flag = 0;
                }
                else
                {
                    int j = i - 1;
                    while(in[j] == ' ' && j > 0)
                        j--;
                    if(is_operator(in[j]) || in[j] == '(' || in[j] == '>' || in[j] == '<') //consider 2 char operator
                    {   
                        _op += "u";
                        while(op_precedence(_op) > op_precedence(op_stack.top()))
                        {
                            my_queue.push(op_stack.top());
                            op_stack.pop();
                            if(op_stack.empty())
                                break;
                        }
                        flag = 0;
                    }
                }
            }
            if(flag)//binary
            {  
                if(!op_stack.empty())
                {   
                    if(right_associate(_op))
                    {
                        while(op_precedence(_op) > op_precedence(op_stack.top()))
                        {
                            my_queue.push(op_stack.top());
                            op_stack.pop();
                            if(op_stack.empty())
                                break;
                        }
                    }
                    else
                    {   
                        while(op_precedence(_op) >= op_precedence(op_stack.top()))
                        {
                            my_queue.push(op_stack.top());
                            op_stack.pop();
                            if(op_stack.empty())
                                break;
                        }    
                    }
                }
                op_stack.push(_op);
            }
        }
        //printf("%d", op_stack.size());
        if(in[i] == ')')
        {
            bool flag = 1;
            while(flag)
            {
                if(op_stack.empty())
                {
                    printf("Error: parentheses mismatched\n");
                    return false;
                }
                if(op_stack.top() != "(")
                {
                    my_queue.push(op_stack.top());
                }
                else
                    flag = 0;
                op_stack.pop();
            } 
        }
        i++;
    }

    return true;
}
