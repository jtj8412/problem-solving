//----------------------------------------------------------------------------------
// [ 매칭 점수 ] https://programmers.co.kr/learn/courses/30/lessons/42893
//----------------------------------------------------------------------------------

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

struct DATA { int idx, basic = 0, from = 0;};

int solution(string word, vector<string> pages) {
    unordered_map<string, DATA> dict;
    unordered_map<string, vector<string>> ex_link;
    const string link_rule = "<meta property=\"og:url\" content=\"";
    const string href_rule = "<a href=\"";
    float result[20] = {}, max = 0;

    for (int i = 0; i < word.size(); ++i) {
        if (word[i] <= 'Z') word[i] += 32;
    }

    for (int i = 0; i < pages.size(); ++i) {
        string link;
        int idx = 0, body_idx;

        idx = pages[i].find(link_rule, idx+1);
        for (int j = idx + link_rule.size(); pages[i][j] != '\"'; ++j)
            link += pages[i][j];
        dict[link] = DATA({i});

        idx = pages[i].find("<body>", idx);
        idx += 6;
        body_idx = idx;

        while ((idx = pages[i].find(href_rule, idx+1)) != string::npos) {
            string ex;
            for (int j = idx + href_rule.size(); pages[i][j] != '\"'; ++j)
                ex += pages[i][j];
            ex_link[ex].push_back(link);
            ++dict[link].from;
        }

        for (int j = body_idx, k; j < pages[i].size() - 13; ++j) {
            if ((pages[i][j-1] >= 'a' && pages[i][j-1] <= 'z') || (pages[i][j-1] >= 'A' && pages[i][j-1] <= 'Z') ||
                (pages[i][j+word.size()] >= 'a' && pages[i][j+word.size()] <= 'z') || (pages[i][j+word.size()] >= 'A' && pages[i][j+word.size()] <= 'Z')) continue;
            for (k = 0; k < word.size(); ++k) {
                if (pages[i][j+k] != word[k] && pages[i][j+k] + 32 != word[k]) break;
            }
            if (k == word.size()) ++dict[link].basic;
        }
    }

    for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
        float sum = iter->second.basic;
        for (int j = 0; j < ex_link[iter->first].size(); ++j) {
            auto &data = dict[ex_link[iter->first][j]];
            if (data.from != 0) sum += (float)data.basic / data.from;
        }
        result[iter->second.idx] = sum;
        if (sum > max) max = sum;
    }

    for (int i = 0; i < pages.size(); ++i) {
        if (max == result[i]) return i;
    }
    return 0;
}