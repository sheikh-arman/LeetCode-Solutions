class Solution {
public:
	bool isVowel(char ch) {
		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			return true;
		if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			return true;
		return false;
	}
	string reverseVowels(string s) {
		int i = 0;
		int j = s.length() - 1;
		while(i < j) {
			while(i < s.length() && !isVowel(s[i]))
				i++;
			while(j > 0 && !isVowel(s[j]))
				j--;
			if(i < j)
			swap(s[i++], s[j--]);
		}
		return s;
	}
};