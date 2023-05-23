#include <bits/stdc++.h>
using namespace std;

bool isValidOperator(const string& token) {
    // List of valid operators
    const string operators[] = {
            "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!",
            "&", "|", "^", "~", "<<", ">>", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=",
            "&=", "|=", "^=", "++", "--"
    };

    // Check if the token is a valid operator
    for (const string& op : operators) {
        if (token == op)
            return true;
    }

    return false;
}

int main() {
    ifstream fs(R"(C:\Users\khatu\github\CPPCode\operator_file.txt)", ios::in);
    if (!fs) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(fs, line)) {
        string token;
        size_t pos = 0;

        while ((pos = line.find_first_of(" \t", pos)) != string::npos) {
            if (pos > 0) {
                token = line.substr(0, pos);
                if (isValidOperator(token))
                    cout << "Valid operator " << lineNumber << ": " << token << endl;
                else
                    cout << "Not a valid operator " <<": " << token << endl;
            }

            line.erase(0, pos + 1);
            pos = 0;
        }

        if (!line.empty()) {
            if (isValidOperator(line))
                cout << "Valid operator "<<": " << line << endl;
            else
                cout << "Not a valid operator  " <<": " << line << endl;
        }

        lineNumber++;
    }

    fs.close();

    return 0;
}