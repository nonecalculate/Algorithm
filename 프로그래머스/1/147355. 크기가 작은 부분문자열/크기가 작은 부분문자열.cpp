#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    string str;
    for (long i = 0; i <= t.length() - p.length(); i++) 
    {
	    for (long j = i; j < p.length()+i; j++) 
        {
		    str += t[j];
		}
		if (stol(str) <= stol(p)) answer++;
		str.clear();
	}
    return answer;
}