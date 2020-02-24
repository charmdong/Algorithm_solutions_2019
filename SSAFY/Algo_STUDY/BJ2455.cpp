#include <iostream>

using namespace std;

int main()
{
    int max = 0;
    int in, out;
    int total = 0;

    for(int station = 0; station < 4; station++) {
        cin >> out >> in;
        total = total + in - out;

        if(max < total) {
            max = total;
        }
    }

    cout << max << endl;

    return 0;
}