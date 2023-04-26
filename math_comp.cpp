#include <bits/stdc++.h>
using namespace std;

int main()
{

    float mean = 84.75;
    vector<float> values = {43.8,71,81.4,142.8};
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