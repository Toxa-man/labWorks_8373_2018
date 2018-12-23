#include <string> 
#include <vector> 
#include <sstream> 
#include <iostream> 
using namespace std;

int main() {
	string s, w, c;

	cout << "Enter words: " << endl;
	getline(cin, s);

	istringstream iss(s);
	vector<string> v;
	
	while (iss >> w) 
		v.push_back(w);

	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < v.size() - i - 1; j++) {
			if (v[j].size() > v[j + 1].size()) {
				c = v[j];
				v[j] = v[j + 1];
				v[j + 1] = c;
			}
		}
	}

	cout << "Sorted string: " << endl;
	for (int c = 0; c < v.size(); ++c) cout << v[c] << " ";
	system("pause");
	return 0;
}