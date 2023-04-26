#include <bits/stdc++.h>
using namespace std;

string gameWinner(string colors)
{
    int len = colors.length();

    while (true)
    {
        for (int i = 0; i < len; i++)
        {
            bool found_b = false;
            bool found_w = false;
            if (colors.substr(i, 3) == "bbb")
            {
                colors = colors.substr(0, i + 1) + colors.substr(i + 2, len - i - 2);
                found_b = true;
            }
            if (colors.substr(i, 3) == "www")
            {
                colors = colors.substr(0, i + 1) + colors.substr(i + 2, len - i - 2);
                found_w = true;
            }

            if (!found_b)
            {
                return "wendy";
            }
            else if (!found_w)
            {
                return "bob";
            }
        }
    }
}

int main()
{
    cout << gameWinner("wwwbbbbwww");
    return 0;
}