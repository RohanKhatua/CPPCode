#include <iostream>
#include <string>

using namespace std;

bool Q(string input, int& index);
bool QPrime(string input, int& index);
bool A(string input, int& index);
bool APrime(string input, int& index);
bool B(string input, int& index);

bool isTerminal(char c) {
    return c == 'a' || c == 'b';
}

bool Q(string input, int& index) {
    if (A(input, index) && QPrime(input, index)) {
        return true;
    }
    return false;
}

bool QPrime(string input, int& index) {
    if (isTerminal(input[index]) && B(input, index) && QPrime(input, index)) {
        return true;
    }
    return true;  // epsilon
}

bool A(string input, int& index) {
    if (B(input, index) && APrime(input, index)) {
        return true;
    }
    return false;
}

bool APrime(string input, int& index) {
    if (isTerminal(input[index]) && B(input, index) && APrime(input, index)) {
        return true;
    }
    return true;  // epsilon
}

bool B(string input, int& index) {
    if (isTerminal(input[index])) {
        index++;
        return true;
    }
    return false;
}

bool parse(string input) {
    int index = 0;
    return Q(input, index) && index == input.length();
}

int main() {
    string input;

    cout<<"Enter the string to be parsed: ";
    cin>>input;

    bool isParsed = parse(input);

    if (isParsed) {
        cout << "String parsed successfully!" << endl;
    } else {
        cout << "String not parsed by this grammar." << endl;
    }

    return 0;
}
