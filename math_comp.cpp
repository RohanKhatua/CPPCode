#include <bits/stdc++.h>
using namespace std;

int main()
{

    float mean = 59.94;
    vector<float> values = {68, 72, 77, 42, 53, 72, 53, 63, 53, 48, 60, 82, 64, 75, 72, 48, 61, 57, 64, 50, 64, 65, 70, 68, 53};
    float sst = 0;

    for (int value : values)
    {
        float diff = value - mean;
        float diff2 = pow(diff, 2);

        cout << "Diff : " << diff << endl;
        cout << "Diff2 : " << diff2 << endl;
        sst += diff2;
    }

    cout << "SST : " << sst << endl;

    return 0;
}