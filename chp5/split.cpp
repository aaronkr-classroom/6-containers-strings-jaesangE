// split.cpp
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string>split(const string& s) {
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	//불변성 :지금까지 원래의 i,현재의 i 범위에 있는 
	//문자들을 처리
	while (i != s.size()) {
		//선행하는 공백을 뮈
		while (i != s.size() && isspace(s[i])) {
			++i;
		}
	}
	//순서상 다음 단어의 끝을찾음
	string_size  j = i;

	while (j != s.size() && !isspace(s[j])) {
		j++;
	}
	if (i != j) {
		ret.push_back(s.substr(i, j - i));
		i = j;
	}
	return ret;
}

int main() {
	string s;
	while (getline(cin, s)) {
		vector<string> v = split(s);
		for (vector<string>::size_type i = 0; i != v.size(); ++i) {
			cout << v[i] << endl;
		}
	}
	return 0;
}
