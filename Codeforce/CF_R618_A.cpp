
#include <iostream>

using namespace std;

int t, n;

int main()
{
    cin >> t;

    for(int test = 1; test <= t; test++) {
        cin >> n;

        int answer = 0;
        int sum = 0;
        int cnt = 0;        
        int num;

        for(int index = 0; index < n; index++) {
            cin >> num;

            if(num == 0) {
                cnt++;
                continue;
            }

            sum += num;
        }

        if(sum == 0) {
            answer = (cnt == 0) ? 1 : cnt;
        } else {
            if(cnt != 0) {
                answer = (sum + cnt == 0) ? cnt + 1 : cnt;
            }
        }

        cout << answer << endl;
    }

    return 0;
}