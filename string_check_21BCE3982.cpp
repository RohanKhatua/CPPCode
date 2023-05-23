#include <bits/stdc++.h>
using namespace std;

bool lang2Check(const string& input) {
    bool hasA = false;
    bool hasB = false;

    // Check the string
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] == 'a') {
            hasA = true;
        } else if (input[i] == 'b') {
            if (!hasA)
                return false; // 'b' cannot appear before 'a'
            hasB = true;
        } else {
            // Invalid character encountered
            return false;
        }
    }

    return hasA && hasB;
}

bool lang1Check(const string& s){
    return s=="a";
}

bool lang3Check(const string& s){
    return s=="abb";
}

int main(){

    string lang1, lang2, lang3;
    lang1 = "a";
    lang2 = "a*b+";
    lang3 = "abb";

    cout<<"The languages are : "<<endl;
    cout<<"1. "<<lang1<<endl;
    cout<<"2. "<<lang2<<endl;
    cout<<"3. "<<lang3<<endl;

    ifstream fs;
    fs.open(R"(C:\Users\khatu\github\CPPCode\string_check_file.txt)", ios::in);

    if (!fs){
        cout<<"File Not Found"<<endl;
        return 0;
    }

    if (fs.is_open()) {
        string line;
        while (getline(fs, line)) {
            auto len = line.length();
            if (len == 0) continue;
            if (lang1Check(line)) cout << line << " belongs to language 1" << endl;
            else if (lang2Check(line)) cout << line << " belongs to language 2" << endl;
            else if (lang3Check(line)) cout << line << " belongs to language 3" << endl;
            else cout << line << " does not belong to any of the languages" << endl;
        }
        fs.close();
    }

    return 0;
}