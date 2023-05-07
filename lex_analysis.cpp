#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '='|| c=='>'|| c=='<');
}

bool isDelimiter(char c)
{
    return (c == ',' || c == ';' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']');
}

bool isIdentifierChar(char c)
{
    return (isalnum(c) || c == '_');
}

bool isKeyword(const string &word)
{
    static const string keywords[] = {"then","endif","print","int", "float", "if", "else", "while", "for", "do", "return"};
    for (const auto &keyword : keywords)
    {
        if (word == keyword)
            return true;
    }
    return false;
}

bool isNumber(const string &word)
{
    for (const auto &c : word)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

void resetBuffer(string &buffer)
{
    buffer.clear();
}

void analyze(const string &input)
{
    ifstream file(input);
    if (!file.is_open())
    {
        cerr << "Error: could not open file " << input << endl;
        return;
    }
    char c;
    string buffer;
    while (file.get(c))
    {
        if (isOperator(c))
        {
            if (!buffer.empty())
            {
                if (isNumber(buffer))
                    cout << buffer << " is a constant" << endl;
                else if (isKeyword(buffer))
                    cout << buffer << " is a keyword" << endl;
                else
                    cout << buffer << " is an identifier" << endl;
                resetBuffer(buffer);
            }
            if (c == '/')
            {
                if (file.peek() == '/')
                {
                    string line;
                    getline(file, line);
                    cout << "//" << line << " is a comment" << endl;
                }
                else if (file.peek() == '*')
                {
                    cout << "/*";
                    bool endFound = false;
                    while (!endFound && file.get(c))
                    {
                        cout << c;
                        if (c == '*')
                        {
                            if (file.peek() == '/')
                                endFound = true;
                        }
                    }
                    cout << "*/ is a comment" << endl;
                }
                else
                {
                    cout << "/ is an operator" << endl;
                    buffer += '/';
                }
            }
            else
            {
                cout << c << " is an operator" << endl;
            }
        }
        else if (isDelimiter(c))
        {
            if (!buffer.empty())
            {
                if (isNumber(buffer))
                    cout << buffer << " is a constant" << endl;
                else if (isKeyword(buffer))
                    cout << buffer << " is a keyword" << endl;
                else
                    cout << buffer << " is an identifier" << endl;
                resetBuffer(buffer);
            }
            cout << c << " is a delimiter" << endl;
        }
        else if (isIdentifierChar(c))
        {
            buffer += c;
        }
        else if (isspace(c))
        {
            if (!buffer.empty())
            {
                if (isNumber(buffer))
                    cout << buffer << " is a constant" << endl;
                else if (isKeyword(buffer))
                    cout << buffer << " is a keyword" << endl;
                else
                    cout << buffer << " is an identifier" << endl;
                resetBuffer(buffer);
            }
        }
        else
        {
            cerr << c << " is an invalid symbol" << endl;
        }
    }
    if (!buffer.empty())
    {
        if (isNumber(buffer))
            cout << buffer << " is a constant" << endl;
        else if (isKeyword(buffer))
            cout << buffer << " is a keyword" << endl;
        else
            cout << buffer << "is an identifier" << endl;
        resetBuffer(buffer);
    }
    file.close();
}

int main()
{
    string input = "input_21BCE3982.txt";
    analyze(input);
    return 0;
}
