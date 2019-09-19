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