class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, long long int target) {
        solve(0,"",num,0,0,target);
        return ans;
    }
    void solve(long long int k, string path, string num, long long int curr_result, long long int prev_num, long long int target)
    {
        if (k == num.length())
        {
            if (curr_result == target)
            {
                ans.push_back(path);
            }
            return;
        }
        long long int temp=0;
        string num_path="";
        for (long long int i = k; i < num.length(); i++)
        {
            num_path.push_back(num[i]);
            temp=temp*10 + (num[i]-'0');
            if (i > k && num_path[0] == '0')
            {
                break;
            }
            
            // temp = stoi(num.substr(k, i + 1-k));
            if (k == 0)
            {
                solve(i + 1, path + num_path, num, temp, temp, target);
            }
            else
            {
                
                solve(i + 1, path + "+" + num_path, num, curr_result + temp, temp, target);
                solve(i + 1, path + "-" + num_path, num, curr_result - temp, -temp, target);
                solve(i + 1, path + "*" + num_path, num, curr_result - prev_num + prev_num * temp, prev_num * temp, target);
            }
        }




    }
};