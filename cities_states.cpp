#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <string>
using namespace std;

// problem-link: https://usaco.org/index.php?page=viewproblem2&cpid=667

int main()
{
	int n; cin >> n;
	vector<pair<string, string>> cities_states;
	for (int i = 0; i < n; i++){
		string city, state;
		cin >> city >> state;
		city = city.substr(0, 2);
		cities_states.push_back(make_pair(city, state));
	}
	
	int total = 0;
	map<string, int> seen;
	for (auto [city, state] : cities_states){
		if (city != state){
			total += seen[city + state];
		}
		seen[state + city]++;
	}

	cout << total;
}