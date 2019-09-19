/**
 * 시간복잡도 : O(n)
 * 공간복잡도 : O(1)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Store {
    public :
    int x, y;
    string name;
    int coupon;
    int dist;

    Store(){}
    Store(int x, int y, string name, int c) : x(x), y(y), name(name), coupon(c) {dist = 0;}
};

void solution(vector<Store>, int, int);
bool cmp(Store s1, Store s2);

int main()
{
    int userX, userY, n;
    vector<Store> storeList;
    cin >> userX >> userY >> n;

    for(int i=0; i<n; i++) {
        int x, y;
        string name;
        int coupon;

        cin >> x >> y >> name >> coupon;
        storeList.push_back(Store(x,y,name,coupon));
    }
    cout << endl;
    solution(storeList, userX, userY);

    return 0;
}

bool cmp(Store s1, Store s2) {
    if(s1.dist == s2.dist) {
        if(s1.coupon == s2.coupon) {
            return s1.name < s2.name;
        }
        return s1.coupon > s2.coupon;
    }
    return s1.dist < s2.dist;
}

void solution(vector<Store> storeList, int userX, int userY) {
    for(Store &s : storeList) {
        int tmpX = (s.x >= 100) ? (s.x / 100) * 100 : 0;
        int tmpY = (s.y >= 100) ? (s.y / 100) * 100 : 0;

        s.dist = abs(userX - tmpX) + abs(userY - tmpY);
    }

    sort(storeList.begin(), storeList.end(), cmp);
    for(auto store : storeList) {
        cout << store.x << " " << store.y << " " << store.name << " " << store.coupon << endl;
    }
}

/*

< test Data >

7123 4653 10
9288 6714 9S7RZV 30
2619 1434 HMH2YX 39
2588 3374 YWV0JQ 4
6284 8626 CQS1OZ 27
5099 1192 4GWLG6 19
6508 4507 Y5J0Q6 12
3161 2805 IQPY9F 36
47 8930 YC1FWC 44
751 2483 40438H 29
3226 4983 LSPFA8 45

*/