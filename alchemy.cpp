#include <iostream>
#include <unordered_map>
#include <vector>    
using namespace std;

unordered_map<char, int> mp = {
    {'H', 1},
    {'O', 16},
    {'C', 12},
    {'N', 14},
    {'S', 32},
    {'P', 31},
    {'F', 19},
    {'I', 127},
    {'B', 11},
    {'K', 39},
    {'Y', 89},
    {'V', 51},
};

int calculateMolarMass(string compound){

    // Separate the compound into elements and their respective quantities
    vector<pair<char, int>> elements;
    for(int i = 0; i < compound.size(); i++){
        char element = compound[i];
        int quantity = 1;
        if(i + 1 < compound.size() && isdigit(compound[i + 1])){
            quantity = compound[i + 1] - '0';
            i++;
        }
        elements.push_back({element, quantity});
    }

    // Calculate the molar mass
    int molarMass = 0;
    for(auto element : elements){
        molarMass += mp[element.first] * element.second;
    }

    if (molarMass == 0) {
        cout << "Does Not Exist. You must periodically check your answers." << endl;
    }

    return molarMass;



}

int main(){

    int t;
    cin>>t;

    while(t--){
        string compound1;
        string compound2;
        cin>>compound1>>compound2;


        int molarMass1 = calculateMolarMass(compound1);
        int molarMass2 = calculateMolarMass(compound2);
        cout<<molarMass1+molarMass2<<endl;
    }




    return 0;
}