#include <iostream>
using namespace std;



int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, num;
    int ary[10001] = {0};

    cin >> n;

    for(int index = 0; index < n; index++){
        cin >> num;
        ary[num]++;        
    }

    for(int index = 1; index < 10001; index++) {
        for(int cnt = 0; cnt < ary[index]; cnt++) {
            cout << index << "\n";
        }
    }

    return 0;
}