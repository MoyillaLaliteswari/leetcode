class Solution {
public:
    int cn(string s) {
        int sum = 0;
        for (char c : s) {
            int r = int(c) - '0';
            sum = sum * 10 + r;
        }
        return sum;
    }

    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> st;
        unordered_map<string, int> countMap;
        int n = formula.size();

        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                st.push(countMap);
                countMap.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                std::string numStr;
                while (i < n && isdigit(formula[i])) {
                    numStr += formula[i];
                    i++;
                }
                int num = numStr.empty() ? 1 : cn(numStr);

                if (!st.empty()) {
                    auto topMap = st.top();
                    st.pop();
                    for (auto &[elem, cnt] : countMap) {
                        topMap[elem] += cnt * num;
                    }
                    countMap = topMap;
                }
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) j++;
                std::string elem = formula.substr(i, j - i);
                i = j;
                std::string numStr;
                while (i < n && isdigit(formula[i])) {
                    numStr += formula[i];
                    i++;
                }
                int num = numStr.empty() ? 1 : cn(numStr);
                countMap[elem] += num;
            }
        }

        vector<pair<string, int>> elements(countMap.begin(), countMap.end());
        sort(elements.begin(), elements.end());

        string result;
        for (const auto &element : elements) {
            result += element.first;
            if (element.second > 1) {
                result += to_string(element.second);
            }
        }

        return result;
    }
};
