#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> convertMap;
        convertMap["I"] = 1;
        convertMap["V"] = 5;
        convertMap["X"] = 10;
        convertMap["L"] = 50;
        convertMap["C"] = 100;
        convertMap["D"] = 500;
        convertMap["M"] = 1000;
        
        convertMap["IV"] = 4;
        convertMap["IX"] = 9;
        convertMap["XL"] = 40;
        convertMap["XC"] = 90;
        convertMap["CD"] = 400;
        convertMap["CM"] = 900;
        
        int sum=0;
        int n = s.length();

        if (n==1){
            return convertMap[s];
        }


        bool last_is_pair = convertMap.find(s.substr(n-2)) != convertMap.end();
        //true if the last form a pair
        
        int i;
        
        for (i=0;i<n-1;i++){
            string two_char = s.substr(i,2);
            if (convertMap.find(two_char)!=convertMap.end()){
                //pair found for subtraction
                sum = sum+convertMap[two_char];
                i++;
            }
            else {
                string first_letter = string(1,s[i]);
                sum = sum+convertMap[first_letter];
            }
        }
        
        if (!last_is_pair){
        
        sum+=convertMap[string(1,s[n-1])];
        }
        
        return sum;
    }
};

int main(){
    Solution s;
    cout<<s.romanToInt("D");
    return 0;
}


