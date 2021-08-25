//----------------------------------------------------------------------------------
// [ 다단계 칫솔 판매 ] https://programmers.co.kr/learn/courses/30/lessons/77486
//----------------------------------------------------------------------------------

#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> enroll_vec, vector<string> referral_vec, vector<string> seller_vec, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, int> dict;
    unordered_map<string, unordered_map<string, int>::iterator> parent_dict;

    dict["-"] = 0;
    parent_dict["-"] = dict.end();

    for (int i = 0; i < enroll_vec.size(); ++i) {
        auto parent = dict.find(referral_vec[i]);
        dict.insert(make_pair(enroll_vec[i], 0));
        parent_dict.insert(make_pair(enroll_vec[i], parent));
    }

    for (int i = 0; i < seller_vec.size(); ++i) {
        auto seller = dict.find(seller_vec[i]), 
            parent = parent_dict[seller_vec[i]];
        int val = amount[i] * 100, 
            rem = val / 10;
        
        while (parent != dict.end()) {
            seller->second += (val - rem);
            if (rem == 0) break;
            val = rem; rem = val / 10;
            seller = parent;
            parent = parent_dict[parent->first];
        }
    }

    for (int i = 0; i < enroll_vec.size(); ++i) 
        answer.push_back(dict[enroll_vec[i]]);

    return answer;
}