#define ll long long int
class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, long long int target) {
        solve(0, 0, 0, 0, "", num, target);
        return ans;
    }
    void solve(ll k, ll prev_num, ll curr_num, ll curr_result, string str, string num, ll target)
    {
        if (k == num.length())
        {
            if ((curr_result == target) && (curr_num == 0))
            {
                ans.push_back(str);
            }
            return;
        }

        curr_num = curr_num * 10 + (num[k] - '0');
        string ch = to_string(curr_num);

        if (curr_num > 0)
        {
            solve(k + 1, prev_num, curr_num, curr_result, str, num, target);
        }
        if (str.size() == 0)
        {
            solve(k + 1, curr_num, 0, curr_result + curr_num, str + ch, num, target);
        }
        else
        {
            solve(k + 1, curr_num, 0, curr_result + curr_num, str + "+" + ch, num, target);
            solve(k + 1, -curr_num, 0, curr_result - curr_num, str + "-" + ch, num, target);
            solve(k + 1, curr_num * prev_num, 0, curr_result - prev_num + prev_num * curr_num, str + "*" + ch, num, target);
        }

    }
};
