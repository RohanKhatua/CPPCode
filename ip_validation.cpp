#include <bits/stdc++.h>
#include <cstring>
using namespace std;

bool isipv4(string str)
{
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (len == 32)
        {
            if (str[i] == '0' || str[i] == '1')
            {
                return true;
            }
        }
    }
    regex r("^([0-9]{1,3}\\.){3}[0-9]{1,3}$");
    if (!regex_match(str, r))
        return false;

    vector<string> tokens;
    istringstream iss(str);
    string token;

    while (getline(iss, token, '.'))
    {
        if (token.empty() || token.size() > 3)
            return false;
        if (token[0] == '0' && token.size() > 1)
            return false;
        if (!all_of(token.begin(), token.end(), ::isdigit))
            return false;
        if (stoi(token) > 255)
            return false;

        tokens.push_back(token);
    }

    if (tokens.size() != 4)
        return false;
    return true;
}

bool isipv6(string str)
{
    regex r("^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$|^::$|^(([0-9a-fAF]{1,4}:){0,6}[0-9a-fA-F]{1,4})?::(([0-9a-fA-F]{1,4}:){0,6}[0-9a-fAF]{1,4})?$");

    return regex_match(str, r);
}

string getIPv4Error(string ip)
{
    int count = 0;
    vector<string> parts;
    stringstream ss(ip);
    string part;
    int flag = 0;

    while (getline(ss, part, '.'))
    {
        parts.push_back(part);
    }

    for (int i = 0; i < ip.length(); i++)
    {
        if (ip[i] != '.' && ip[i] != '0' && ip[i] != '1' && ip[i] != '2' && ip[i] != '3' && ip[i] != '4' && ip[i] != '5' && ip[i] != '6' && ip[i] != '7' && ip[i] != '8' && ip[i] != '9')
        {
            flag = 1;
        }
    }

    if (flag == 1)
    {
        return "IPv4 Error : Address cannot have special characters except .";
    }

    for (string part : parts)
    {
        if (part.empty() || part.size() > 3)
        {
            return "IPv4 Error : Part cannot be empty or longer than 3 digits";
        }

        if (part[0] == '0' && part.size() > 1)
        {
            return "IPv4 Error : Cannot have leading zeroes";
        }

        int num = stoi(part);

        if (num < 0 || num > 255)
        {
            return "IPv4 Error : Each part must be a number between 0 and 255";
        }
    }

    if (count != 3)
    {
        return "IPv4 Error : Must have 4 parts separated by .";
    }

    return "Valid IPv4 Address";
}

string getIPv6Error(string ip)
{
    int len = ip.length();
    int count = 0;
    int colons = 0;
    int flag = 0;

    for (int i = 0; i < len - 1; i++)
    {
        if (ip[i] == ':' && ip[i + 1] == ':')
        {
            colons++;
        }
        else if (ip[i] != ':')
        {
            count++;
        }
    }

    for (int i = 0; i < ip.length(); i++)
    {
        if (ip[i] != '0' && ip[i] != '1' && ip[i] != '2' && ip[i] != '3' && ip[i] != '4' && ip[i] != '5' && ip[i] != '6' && ip[i] != '7' && ip[i] != '8' && ip[i] != '9' && ip[i] != 'A' && ip[i] != 'B' && ip[i] != 'C' && ip[i] != 'D' && ip[i] != 'E' && ip[i] != 'F' && ip[i] != 'a' && ip[i] != 'b' && ip[i] != 'c' && ip[i] != 'd' && ip[i] != 'e' && ip[i] != 'f' && ip[i] != ':')
        {
            flag = 1;
        }
    }

    if (colons>1){
        return "IPv6 Error : At most one :: is allowed";
    }

    else if (flag==1){
        return "IPv6 Error : No special characters allowed except :";        
    }

    if (count!=7){
        return "IPv6 Error : Must have 8 parts unless it has ::";
    }

    vector<string> parts;
    stringstream ss (ip);
    string part;

    while (getline(ss,part,':')){
        parts.push_back(part);
    }

    if (parts.size()!=8){
        return "IPv6 Error : Each Part should be a hexadecimal number between 0000 and FFFF";
    }

    for (string part : parts){
        if (part.empty()||part.size()>4) {
            return "IPv6 Error : Each Part should be a hexadecimal number between 0000 and FFFF";
        }

        for (char c : part){
            if (!isxdigit(c)) return "IPv6 Error : Each Part should be a hexadecimal number between 0000 and FFFF";
        }
    }

    return "Valid IPv6 Address";

}

int main()
{

    vector<string> addresses = {
        "192.168.1.0", "10.0.0.1", "172.16.0.1", "00000001000000010000000100000001", "300.168.1.1", "192.168@1.1", "192.168.01.1", "1010100111000001.172.18", "2001:db8:3333:4444:5555:6666:7777:8888", "2001:db8:3333:4444:CCCC:DDDD:EEEE:FFFF", "::", "21E5:69AA:FFFF:1:E100:B691:1285:F56E", "2001:db8::", "::1234:5678", "2001:db8::1234:5678", "2001:0db8:0001:0000:0000:0ab9:C0A8:0102", "2001:db8:1::ab9:C0A8:102", "255.1.4.2", "fe80:2030:31:24", "::255.255.255.255", "56FE::2159:5BBC::6594"
    };

    for (string address : addresses) {
        if (isipv4(address)){
            cout<<address<<" is a valid IPv4 Address"<<endl;
        }
        else if (isipv6(address)){
            cout<<address<<" is a valid IPv6 Address"<<endl;
        }

        else {
            if (!isipv4(address)){
                cout<<address<<" : "<<getIPv4Error(address)<<endl;
            }
            if (!isipv6(address)){
                cout<<address<<" : "<<getIPv6Error(address)<<endl;
            }
        }
    }

    return 0;
}