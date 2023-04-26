#include <bits/stdc++.h>
using namespace std;

string gameWinner(string colors)
{
    int len = colors.length();
    string turn = "w";
    while (true)
    {
        bool b_found = false;
        bool w_found = false;
        for (int i = 0; i <= colors.length()-2; i++)
        {
        

            if (colors.substr(i, 3) == "bbb" && turn == "b")
            {
                colors = colors.substr(0, i + 1) + colors.substr(i + 2, len - i - 2);
           
                
                b_found = true;
                break;
            }
            if (colors.substr(i, 3) == "www" && turn == "w")
            {
                colors = colors.substr(0, i + 1) + colors.substr(i + 2, len - i - 2);

                
                w_found = true;
                break;
            }
        }

        if (turn == "w" && !w_found)
            return "bob";
        if (turn == "b" && !b_found)
            return "wendy";

        if (turn == "w") turn = "b";
        else turn = "w";
    }
}

int main()
{
    cout << gameWinner("wwwbbbbwww");
    return 0;
}