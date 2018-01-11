/This code is created as console calculator that has ability to calculate simple math


//4.a. Due to this code, when we given the expression (2+3) nothing will appear unless we put "q" to end the operation
//However, even if we put "q" to end this code, it still contains an error which is closing parenthesis expected!
//It happens because the expression() function ate t.kind! so now let debug the code below

//b. Debugged and Added bracket ability {}
// by adding 2 more cases and a putback function to expression function

#include "std_lib_facilities.h"


class Token {
public:
    char kind;
    double value;
};

class Token_stream {
public:
    Token get();
    void putback(Token t);
private:
    bool full {false};
    Token buffer;
};


void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;
    switch (ch) {
    case ';':   // will not use this token yet
    case 'q':   // use 'q' instead of 'x'
    case '(': case ')': case '+': case '-': case '*': case '/': case '{': case '}':             //added 2 more cases: {}
        return Token {ch};
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token {'8', val};
    }
    default:
        error("Bad token");
    }
    return Token{'8',0.0};
}

Token_stream ts;

double expression();
double term();
double primary();

int main()
{
    try {
        cout << expression() << '\n';
    } catch (exception& e) {
        cerr << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "exception\n";
        return 2;
    }

}

double expression()
{
    double left = term();
    Token t = ts.get();
    while (true) {
        switch(t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch(t.kind) {
            expression();
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
                error("division by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");
        return d;
        break;
    }
    case '{':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}')
            error("'}' expected");
        return d;
        break;
    }
    case '8':
        return t.value;
        break;
    default:
        error("primary expected");
    }
}
