static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
	string tens[4] = { "I","X","C","M" };
	string fives[3] = { "V","L","D" };

	string getSymbol(string c, int i) {
		string str;
		for (; i > 0; i--)
			str += c;
		return str;
	}

	string symbol(int a, int pow) {
		if (a <= 3)
			return getSymbol(tens[pow],a);
		if (a == 4)
			return (tens[pow] + fives[pow]);
		if (a == 5)
			return fives[pow];
		if (a <= 8 && a > 5)
			return fives[pow] + symbol(a - 5, pow);
		if (a == 9)
			return tens[pow] + tens[pow + 1];
	}

	string intToRoman(int num) {
		string ans;

		vector<string> arr;
		while (num > 0) {
			arr.push_back(symbol(num%10,arr.size()));
			num /= 10;
		}

		for (int i = arr.size()-1; i >= 0;i--) {
			ans += arr[i];
		}
		return ans;
	}
};