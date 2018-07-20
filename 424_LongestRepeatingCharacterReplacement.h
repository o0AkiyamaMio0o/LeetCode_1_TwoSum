class Solution {
public:

	int characterReplacement(string s, int k) {

		bool state = 1;
		int max = 0, ans = 0;
		int arr[26];

		string::iterator iter;

		while (state&&ans<=s.size()) {

			iter = s.begin();
			state = 0;

				for (int i = 0; i<26; i++)
					arr[i] = 0;

				for (int i = 0; i < ans; i++) {
					arr[s[i] - 'A']++;
				}

				for (int i = 0; i<26; i++) {
					if (arr[i] > max)
						max = arr[i];
				}

				if (max + k >= ans) {
					ans++;
					state = 1;
					continue;
				}

				while (iter + ans < s.end()) {
					arr[*iter - 'A']--;
					arr[*(iter+ans) - 'A']++;
					if (arr[*(iter+ans) - 'A'] > max)
						max = arr[*(iter+ans) - 'A'];
					iter++;

					if (max + k >= ans) {
						ans++;
						state = 1;
						break;
					}
				}

		}
		return ans-1;
	}
};