#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class FileChanger {
public:

	void Upper(fstream& fs, int numb);
	void Lower(fstream& fs, int numb);
	void Change(fstream& fs, int numb, char a, char b);
};

int main() {
	FileChanger fch;
	string filename;
	cin >> filename;
	fstream s(filename, s.binary | s.trunc | s.in | s.out);
	if (!s.is_open()) {
		cout << "Failed to open" << endl;
	} else {
		string command;
		while(getline(cin, command)) {
			stringstream ss(command);
			int numb;
			ss >> numb;
			if (ss.peek() == ':') {
				ss.ignore(1);
				if (ss.peek() == 'u') {
					fch.Lower(s, numb);
				} else if (ss.peek() == 'U') {
					fch.Upper(s, numb);
				} else if (ss.peek() == 'R') {
					ss.ignore(1);
					char a, b;
					ss >> a >> b;
					fch.Change(s, numb, a, b);
				} else {
					throw invalid_argument("Wrong command");
				}
			} else {
				throw invalid_argument("Wrong command");
			}
		}

		s.close();
	}
	return 0;
}
