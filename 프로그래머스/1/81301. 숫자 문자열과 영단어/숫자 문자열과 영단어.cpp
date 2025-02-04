#include <string>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int solution(string s) {
    
    int answer = 0;
    vector<string> number = 
    {
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"
	};
    string temp1;
    string temp2;

    for (char ch : s) {
	    if (isalpha(ch)) {
		    temp1 += ch;
		    for (int i = 0; i < number.size(); i++) {
			    if (temp1 == number[i]) {
				    temp2 += to_string(i);
				    temp1 = ""; 
				    break;
			    }
		    }
	    }
    	else {
		temp2 += ch;
	    }
    }
    answer = stoi(temp2);
    return answer;
}