#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Define the grammar productions as LHS -> RHS
unordered_map<string, vector<vector<string>>> productions = {
        {"E", {{"TA"}}},
        {"A", {{"+TA"}, {}}},
        {"T", {{"FB"}}},
        {"B", {{"*FB"}, {}}},
        {"F", {{"(E)"}, {"x"}}}
};

// LL(1) parsing table
unordered_map<string, unordered_map<string, vector<string>>> parsingTable = {
        {"E", {
                      {"(", {"T", "A"}},
                      {"x", {"T", "A"}}
              }},
        {"A", {
                      {"+", {"+", "T", "A"}},
                      {")", {}},
                      {"$", {}}
              }},
        {"T", {
                      {"(", {"F", "B"}},
                      {"x", {"F", "B"}}
              }},
        {"B", {
                      {"*", {"*", "F", "B"}},
                      {"+", {}},
                      {")", {}},
                      {"$", {}}
              }},
        {"F", {
                      {"(", {"(", "E", ")"}},
                      {"x", {"x"}}
              }}
};

// Parse function
vector<string> parse(const string& input)
{
    string augmentedInput = input + "$"; // Append end marker

    vector<string> parseStack = {"$", "E"}; // Initialize parse stack
    vector<string> output; // Store the list of productions used

    size_t inputIndex = 0;

    while (!parseStack.empty())
    {
        string currentSymbol = parseStack.back();
        parseStack.pop_back();

        if (inputIndex >= augmentedInput.size())
        {
            cout << "Error: String not parsed by this grammar." << endl;
            return {};
        }

        if (currentSymbol == augmentedInput.substr(inputIndex, 1))
        {
            if (currentSymbol != "$") {
                output.push_back(currentSymbol + " -> " + augmentedInput.substr(inputIndex, 1));
            }
            inputIndex++;
        }
        else if (productions.find(currentSymbol) != productions.end())
        {
            string inputToken = augmentedInput.substr(inputIndex, 1);
            vector<string> production;

            if (parsingTable[currentSymbol].find(inputToken) != parsingTable[currentSymbol].end())
            {
                production = parsingTable[currentSymbol][inputToken];
            }
            else
            {
                cout << "Error: String not parsed by this grammar." << endl;
                return {};
            }

            if (production.empty())
            {
                continue; // Skip epsilon production
            }

            output.push_back(currentSymbol + " -> " + production[0]);

            // Push RHS of the production onto the stack in reverse order
            for (int i = production.size() - 1; i >= 0; i--)
            {
                parseStack.push_back(production[i]);
            }
        }
        else
        {
            cout << "Error: String not parsed by this grammar." << endl;
            return {};
        }
    }

    return output;
}

int main()
{
    string input;
    cout << "Enter a string to be parsed: ";
    getline(cin, input);

    vector<string> productionsUsed = parse(input);

    if (!productionsUsed.empty())
    {
        cout << "Productions used for parsing:" << endl;
        for (const string& production : productionsUsed)
        {
            cout << production << endl;
        }
    }

    return 0;
}
