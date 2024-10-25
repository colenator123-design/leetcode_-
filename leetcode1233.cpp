class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        // 將資料夾按字母順序排序
        std::sort(folder.begin(), folder.end());
        
        std::vector<std::string> result;
        for (const std::string& f : folder) {
            // 檢查是否為子資料夾，條件是 f 並非以 result.back() + "/" 開頭
            if (result.empty() || f.substr(0, result.back().size() + 1) != result.back() + "/") {
                result.push_back(f);
            }
        }
        return result;
    }
};