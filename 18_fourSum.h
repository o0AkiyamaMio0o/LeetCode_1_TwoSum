static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		set<vector<int>> ans_temp;
		//vector<int> ans_temp;
		vector<int>::iterator i1 = nums.begin(), i2, i3, i4;

		sort(nums.begin(), nums.end());

		if (nums.size()<4)
			return ans;

		int sum = 0;//= nums[0]+nums[1]+nums[2]+nums[3];

		while (i1 < nums.end()) {
			sum += *i1;
			i2 = i1 + 1;
			while (i2 < nums.end()) {
				sum += *i2;
				i3 = i2 + 1;
				while (i3 < nums.end()) {
					sum += *i3;
					i4 = i3 + 1;
					while (i4 < nums.end()) {
						sum += *i4;

						if (sum == target )
							ans_temp.insert(vector<int>{*i1, *i2, *i3, *i4});

						sum -= *i4;
						i4++;
					}
					sum -= *i3;
					i3++;
				}
				sum -= *i2;
				i2++;
			}
			sum -= *i1;
			i1++;
		}

		for (auto i : ans_temp)
			ans.push_back(i);

		return ans;
	}
};