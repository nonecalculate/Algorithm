#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<char> alpha;
    int bignum;
    bool check = false;
    for (char c : s) alpha.push_back(c);
    for (int i = 0; i < alpha.size(); i++)
    {
	    for (int j = 0; j < i; j++) 
	    {
		    if (alpha[j] == alpha[i]) 
		    {
		    	bignum = i - j;
			    check = true;
		    }
	    }
	    if (check)answer.push_back(bignum);
	    else answer.push_back(-1);
	    check = false;
    }   
    return answer;
}