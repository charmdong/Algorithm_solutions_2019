/// 2017 kakao blind coding test - cache (LRU)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(int, vector<string>);
void upper(string&);
int isInCache(vector<string>, string, int);
int maxIndex(vector<int>, int);
void increaseTime(vector<int>&, int);

int main()
{
	int cacheSize;
	vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo","Seoul","NewYork","LA" };

	cin >> cacheSize;
	cout << solution(cacheSize, cities);

	return 0;
}

int solution(int cacheSize, vector<string> cities) {
	if (cacheSize == 0)
		return cities.size() * 5;
	
	int res = 0, index=0;
	int len = cities.size();

	vector<string> cache(cacheSize, "");
	vector<int> cacheTime(cacheSize, 0);

	for (int i = 0; i < len; i++) {
		upper(cities[i]);
		int hitIndex = isInCache(cache, cities[i], index);
		
		// Cache Miss
		if (hitIndex == -1) {
			if (index < cacheSize) {
				cache[index++] = cities[i];
			}
			else {
				int temp = maxIndex(cacheTime, *max_element(cacheTime.begin(), cacheTime.end()));
				cache[temp] = cities[i];
				cacheTime[temp] = 0;
			}
			res += 5;
		}
		// Cache Hit
		else {
			cacheTime[hitIndex] = 0;
			res += 1;
		}
		increaseTime(cacheTime, index);
	}

	return res;
}

void upper(string& str) {
	for (auto & c : str)
		c = toupper(c);
}

int isInCache(vector<string> cache, string city, int index) {
	for (int i = 0; i < index; i++) {
		if (cache[i] == city)
			return i;
	}
	return -1;
}

int maxIndex(vector<int> cacheTime, int max) {
	for (int i = 0; i < cacheTime.size(); i++)
		if (cacheTime[i] == max) return i;
}

void increaseTime(vector<int>& cacheTime, int index) {
	for (int i = 0; i < index; i++)
		cacheTime[i]++;
}