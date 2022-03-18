#include <iostream>
#include <iterator>
#include <regex>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
	string input,final_input;
	char c_input = ' ';
	string r_PLUS, r_MINUS, r_MUL, r_DIV, r_LPR, r_RPR, r_NUM, result;
	//getline(cin, input);
	
	/*
	while (cin >> input) {
		if (input == "0") {
			break;
		}
		else {
			final_input += input;
		}
	}
	*/

	while (cin >> input) {

		final_input += input;

	}

	regex NUM("([A-Z]*)([0-9][0-9]*)([A-Z]*)");
	regex PLUS("([1-9|A-Z]*[-|*|/|(|)]*)([+])([1-9|A-Z]*[\W]*)");
	regex MINUS("([1-9|A-Z]*[*|/|(|)]*)([-])([1-9|A-Z]*[\W]*)");
	regex MUL("([1-9|A-Z]*[/|(|)]*)([*])([1-9|A-Z]*[\W]*)");
	regex DIV("([1-9|A-Z]*[(|)]*)([/])([1-9|A-Z]*[\W]*)");
	regex LPR("([1-9|A-Z]*[)]*)([(])([1-9|A-Z]*[\W]*)");
	regex RPR("([1-9|A-Z]*)([)])([1-9|A-Z]*[\W]*)");
	/*
	regex PLUS("([1-9|+|-|*|/|(|)]*)([+]*)([1-9|+|-|*|/|(|)]*)");
	regex MINUS("([1-9|A-Z]*[*|/|(|)]*)([-])([1-9|A-Z]*[-|*|/|(|)]*)");
	regex MUL("([1-9|A-Z]*[/|(|)]*)([*])([1-9|A-Z]*[*|/|(|)]*)");
	regex DIV("([1-9|A-Z]*[(|)]*)([/])([1-9|A-Z]*[/|(|)]*)");
	regex LPR("([1-9|A-Z]*[)]*)([(])([1-9|A-Z]*[(|)]*)");
	regex RPR("([1-9|A-Z]*)([)])([1-9|A-Z]*[)]*)");
	*/
	/*
	stringstream ss;
	ss << c_input;
	ss >> final_input;
	*/
	//cout << regex_replace(final_input, PLUS, "$1 PLUS $3") << endl;
	regex_replace(back_inserter(r_PLUS), final_input.begin(), final_input.end(), PLUS, "$1\nPLUS$3");
	//cout << "result: " << "\n" << r_PLUS << endl;
	
	//cout << regex_replace(r_PLUS, MINUS, "$1 MINUS $3") << endl;
	regex_replace(back_inserter(r_MINUS), r_PLUS.begin(), r_PLUS.end(), MINUS, "$1\nMINUS$3");
	//cout << "result: " << "\n" << r_MINUS << endl;

	//cout << regex_replace(r_MINUS, MUL, "$1 MUL $3") << endl;
	regex_replace(back_inserter(r_MUL), r_MINUS.begin(), r_MINUS.end(), MUL, "$1\nMUL$3");
	//cout << "result: " << "\n" << r_MUL << endl;

	//cout << regex_replace(r_MUL, DIV, "$1 DIV $3") << endl;
	regex_replace(back_inserter(r_DIV), r_MUL.begin(), r_MUL.end(), DIV, "$1\nDIV$3");
	//cout << "result: " << "\n" << r_DIV << endl;
	
	//cout << regex_replace(r_DIV, LPR, "$1 LPR $3") << endl;
	regex_replace(back_inserter(r_LPR), r_DIV.begin(), r_DIV.end(), LPR, "$1\nLPR$3");
	//cout << "result: " << "\n" << r_LPR << endl;

	//cout << regex_replace(r_LPR, RPR, "$1 RPR $3") << endl;
	regex_replace(back_inserter(r_RPR), r_LPR.begin(), r_LPR.end(), RPR, "$1\nRPR$3");
	//cout << "result: " << "\n" << r_RPR << endl;
	
	//cout << regex_replace(r_RPR, NUM, "$1 NUM $2$3") <<endl;
	regex_replace(back_inserter(r_NUM), r_RPR.begin(), r_RPR.end(),NUM, "$1\nNUM $2$3");
	cout << r_NUM << endl;
	
	return 0;
}
