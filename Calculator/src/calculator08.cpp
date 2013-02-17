#include "../std_lib_facilities.h"


/**
 * Token represents a single unit that calculator operates on.
 */
struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) :kind(ch), value(0) { }
    Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string val) :kind(ch), name(val), value(0) { }
};


/**
 * Variable definition.
 */
struct Variable {
    string name;
    double value;
    bool constant;
    Variable(string n, double v, bool c) :name(n), value(v), constant(c) { }
};


/**
 * Table of existing variables.
 */
class Table {
public:
        void set(string s, double v);
        double get(string s);
        void define(string s, double v, bool c);
        bool is_declared(string s);
private:
        vector<Variable> var_names;
};


/**
 * Sets a new value for existing variable.
 */
void Table::set(string s, double v) {
    for (int i = 0; i<=var_names.size(); ++i) {
        if (var_names[i].name == s) {
            if (var_names[i].constant) error(s, " is a constant.");
            var_names[i].value = v;
            return;
        }
    }
    error("set: undefined name ",s);
}


/**
 * Returns value of a variable
 */
double Table::get(string s) {
    for (int i = 0; i<var_names.size(); ++i) {
        if (var_names[i].name == s) return var_names[i].value;
    }

    error("get: undefined name ",s);
}


/**
 * Defines a new variable or constant.
 */
void Table::define(string s, double v, bool c) {
    if (is_declared(s)) {
        error(s, " already declared");
    }

    var_names.push_back(Variable(s, v, c));
}


/*
 * Checks is variable is declared.
 */
bool Table::is_declared(string s) {
    for (int i = 0; i<var_names.size(); ++i) {
        if (var_names[i].name == s) return true;
    }

    return false;
}


/**
 * Interface to variables table.
 */
class Symbol_Table {
public:
        double get_value(string s) {
            return var_names.get(s);
        }

        void set_value(string s, double v){
            var_names.set(s, v);
        }

        void define_name(string s, double v, bool c){
            var_names.define(s, v, c);
        }

        bool is_declared(string s){
            try {
                return !!var_names.get(s);
            } catch(exception &e) {
                return false;
            }
        }
private:
        Table var_names;
};

Symbol_Table symbols;

/**
 * Symbolic constants.
 */
const char LET = 'L';
const char CONST = 'C';
const char SQRT = 'S';
const char POW = 'P';
const char QUIT = 'Q';
const char PRINT = ';';
const char NUMBER = '8';
const char NAME = 'a';
const char ASSIGN = '=';


/**
 * Returns tokens from stdin.
 */
class Token_stream {
public:
    bool full;
    Token buffer;
    Token_stream() :full(0), buffer(0) { }

    Token get();
    void unget(Token t) { buffer=t; full=true; }

    void ignore(char);
};


Token Token_stream::get() {
    if (full) { full=false; return buffer; }
    char ch;

    if (cin.get(ch) && ch == '\n') return Token(PRINT);
    cin.unget();

    cin >> ch;
    switch (ch) {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case ';':
    case '=':
    case ',':
        return Token(ch);
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {   cin.unget();
        double val;
        cin >> val;
        return Token(NUMBER,val);
    }
    default:
        if (isalpha(ch) || '#' || '_') {
            string s;
            s += ch;
            // read in all alphanumeric chars
            while( cin.get(ch) && (isalpha(ch) || isdigit(ch)) ){
                s +=ch;
            }
            // put next non-alphanumeral back into stream
            cin.unget();
            if (s == "#") return Token(LET);
            if (s == "const") return Token(CONST);
            if (s == "sqrt") return Token(SQRT);
            if (s == "pow") return Token(POW);
            if (s == "quit") return Token(QUIT);
            return Token(NAME, s);
        }
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
{
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch;
    while (cin>>ch)
        if (ch==c) return;
}


Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {   double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '-':
        return - primary();
    case NUMBER:
        return t.value;
    case NAME:
        return symbols.get_value(t.name);
    default:
        error("primary expected");
    }
}

double term()
{
    double left = primary();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
        case '%': {
            int mod = (int)left;
            int right = primary();
            left = mod%right;
            break;
        }
        case '*':
            left *= primary();
            break;
        case '/':
        {   double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    while(true) {
        Token t = ts.get();
        switch(t.kind) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}


double declaration(bool constant) {
    Token t = ts.get();
    if (t.kind != NAME) error ("name expected in declaration");
    string name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing");

    double d = expression();

    if (symbols.is_declared(name)) symbols.set_value(name,d);
    else symbols.define_name(name,d, constant);

    return d;
}

double statement()
{
    Token t = ts.get();
    switch(t.kind) {
    case LET:
        return declaration(false);
    case CONST:
        return declaration(true);
    case ASSIGN:
        return declaration(false);
    case SQRT: {
        double e = expression();
        if (e < 0) error("Cannot calculate square root of negative numbers.");
        return sqrt(e);
    }
    case POW: {
        t = ts.get();
        if (t.kind != '(') error("( expected.");

        double base = primary();
        t = ts.get();
        if (t.kind != ',') error("Comma expected.");

        double power = primary();

        t = ts.get();
        if (t.kind != ')') error(") expected.");

        double result = 1;

        while (power > 0) {
            result *= base;
            --power;
        }

        return result;
    }
    default:
        ts.unget(t);
        return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(PRINT);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    while(true) try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == PRINT) t=ts.get(); // eat all ';' chars
        if (t.kind == QUIT) return;
        ts.unget(t);
        cout << result << statement() << endl;
    }
    catch(runtime_error& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}


int main() {
    symbols.define_name("k", 1000, true);
    try {
        calculate(); // run the calculation loop
        return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        char c;
        while (cin >> c && c!=';');
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        char c;
        while (cin>>c && c!=';');
        return 2;
    }
}
