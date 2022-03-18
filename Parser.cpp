#include <iostream>
#include <iterator>
#include <regex>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

string peek();
void program();
void stmts();
void stmt();
void primary();
void primary_tail();

vector<string> sentence;
string input,cin_temp,temp;
regex ID("([A-Za-z_][A-Za-z0-9_]*)");
regex STRLIT("([\"][A-Za-z0-9_]*[\"])");
regex LBR("([(])*");
regex RBR("([)])*");
regex DOT("([.])");

int main()
{
    int string_symbol_num=0;
    /*
    stringstream ss;
    ss << input[i];
    ss >> temp;
    */
    while (cin >> cin_temp) {
        if (cin_temp == "0") {
            break;
        }
        input += cin_temp;
    }
    for (int i = 0; i < input.size();i++) {
        //cout << input[i];
        if (input[i] != '\\') {
            if (input[i] == '.' || input[i] == '('|| input[i] == ')') {
                //如果有還沒push的部分先push
                if (temp != "") {
                    sentence.push_back(temp);
                    temp = "";
                }
                temp += input[i];
                sentence.push_back(temp);
                temp = "";
                //cout << " 1" << endl;
                /*
                if (input[i - 1] == '(' || input[i - 1] == ')') {

                    sentence.push_back(temp);
                    temp = "";
                    cout << " 1" << endl;
                }
                else {
                    sentence.push_back(temp);
                    temp = "";
                    cout << " 2" << endl;
                }      
                */
            }
            else if (input[i] == '\"') {
                string_symbol_num += 1;
                if (string_symbol_num % 2 == 0) {
                    //sentence[vector_num] += input[i];
                    temp += input[i];
                    sentence.push_back(temp);
                    temp = "";
                    //cout << " 3" << endl;
                }
                else {
                    //vector_num += 1;
                    temp += input[i];
                    //cout << " 4" << endl;
                }   
            }
            else {
                if (i == 0) {
                    temp += input[i];
                    //cout << " 5" << endl;
                }
                else if (input[i - 1] != '\\') {
                    temp += input[i];
                    //cout << " 6" << endl;
                    if (i == input.size() - 1) {
                        sentence.push_back(temp);
                    }
                }   
            }
        }
    }
    
    for (int j = 0; j < sentence.size(); j++) {
        cout << j+1 << ":" << sentence[j] << endl;
    }
    
    program();

}

string peek() {
    if (sentence.size() == 0) {
        return "";
    }
    else if (regex_match(sentence.front(), ID)) {
        return "ID";
    }
    else if (regex_match(sentence.front(), STRLIT)) {
        return "STRLIT";
    }
    else if (regex_match(sentence.front(), LBR)) {
        return "LBR";
    }
    else if (regex_match(sentence.front(), RBR)) {
        return "RBR";
    }
    else if (regex_match(sentence.front(), DOT)) {
        return "DOT";
    }
    return "invalid input";
}

void program() {
    stmts();
}

void stmts() {
    if (peek() == "STRLIT" || peek() == "ID") {
        stmt();
        stmts();
    }
    else {
        cout << peek();
    }  
}

void stmt() {
    if (peek() == "ID") {
        primary();
    }
    else if (peek() == "STRLIT") {
        //regex_replace (back_inserter(input), input.begin(), input.end(), STRLIT, "STRLIT $1");
        cout << "STRLIT " << sentence.front() << endl;
        sentence.erase(sentence.begin());//1
    }
}

void primary() {
    //regex_replace(back_inserter(input), input.begin(), input.end(), ID, "ID $1");
    cout << "ID " << sentence.front() << endl;
    sentence.erase(sentence.begin());//1
    primary_tail();
}

void primary_tail() {
    if (peek() == "DOT") {
        //regex_replace(back_inserter(input), input.begin(), input.end(), DOT, "DOT $1");
        cout << "DOT " << sentence.front() << endl;
        sentence.erase(sentence.begin());//1
        //regex_replace(back_inserter(input), input.begin(), input.end(), ID, "ID $1");
        cout << "ID " << sentence.front() << endl;
        sentence.erase(sentence.begin());//1
        primary_tail();
    }
    else if (peek() == "LBR") {
        //regex_replace(back_inserter(input), input.begin(), input.end(), LBR, "LBR $1");
        cout << "LBR " << sentence.front() << endl;
        sentence.erase(sentence.begin());//1
        stmt();
        //regex_replace(back_inserter(input), input.begin(), input.end(), RBR, "RBR $1");
        cout << "RBR " << sentence.front() << endl;
        sentence.erase(sentence.begin());//1
        primary_tail();
    }
}
