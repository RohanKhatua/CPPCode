#include <iostream>
#include <string>

using namespace std;

bool isCommentLine(string line) {
    // Remove any leading whitespace
    size_t pos = line.find_first_not_of(" \t");
    if (pos != string::npos) {
        line = line.substr(pos);
    }

    // Check if the line starts with "//" or "/*"
    if (line.compare(0, 2, "//") == 0 || line.compare(0, 2, "/*") == 0) {
        return true;
    }

    return false;
}

int main() {
    string line;

    // Read a line of input from the user
    cout << "Enter a line of C code: ";
    getline(cin, line);

    // Check if the line is a comment line
    if (isCommentLine(line)) {
        cout << "This is a comment line." << endl;
    } else {
        cout << "This is not a comment line." << endl;
    }

    return 0;
}
