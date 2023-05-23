#include <bits/stdc++.h>
using namespace std;

bool is_identifier(string str){
    auto len=str.length();

    if (str[0] == '_' || isalpha(str[0])) {
        for (int i = 1; i < len; i++) {
            if (str[i] == '_' || isalpha(str[i]) || isdigit(str[i])) {
                continue;
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

bool is_constant(string str){
    auto len=str.length();
    for(int i=0;i<len;i++){
        if(len==32){
            if(str[i]=='0' || str[i]=='1'){
                return true;
            }
        }
    }
    for(int i=0;i<len;i++){
        if(isdigit(str[i]) && len<=15){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}


int main(){
    ifstream file;
    file.open(R"(C:\Users\khatu\github\CPPCode\id_const_file.txt)", ios::in);
    if(!file){
        cout<<"File not found";
        return 0;
    }
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            auto len = line.length();
            if (len ==0) continue;
            for (int i = 0; i < len; i++) {
                if (line[i] == ' ' || line[i] == '\t') {
                    continue;
                } else if (line[i] == '_' || isalpha(line[i])) {
                    int j = i;
                    while (line[j] != ' ' && line[j] != '\t' && j < len) {
                        j++;
                    }
                    string str = line.substr(i, j - i);
                    if (is_identifier(str)) {
                        cout << str << " is a valid identifier" << endl;
                    } else {
                        cout << str << " is not a valid identifier" << endl;
                    }
                    i = j - 1;
                } else if (isdigit(line[i])) {
                    int j = i;
                    while (line[j] != ' ' && line[j] != '\t' && j < len) {
                        j++;
                    }
                    string str = line.substr(i, j - i);
                    if (is_constant(str)) {
                        cout << str << " is a valid constant" << endl;
                    } else {
                        cout << str << " is not a valid constant" << endl;
                    }
                    i = j - 1;
                }
            }
        }
        file.close();
    }

    return 0;
}