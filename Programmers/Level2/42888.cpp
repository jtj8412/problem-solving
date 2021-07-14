/* 오픈채팅방 */

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> split(string str, const char delim=' ') {
    vector<string> ret;
    int prev = 0, cur = -1;

    while ((cur = str.find(delim, cur + 1)) != string::npos) {
        ret.push_back(str.substr(prev, cur - prev));
        prev = cur + 1;
    }
    ret.push_back(str.substr(prev, str.size() - prev));
    
    return ret;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> record_vvec;
    unordered_map<string, string> id_map;
    
    for (int i = 0; i < record.size(); ++i) {
        vector<string> data_vec = split(record[i]);
        if (data_vec[0][0] == 'E') {
            id_map[data_vec[1]] = data_vec[2];
            record_vvec.push_back(data_vec);
        } else if (data_vec[0][0] == 'L') {
            record_vvec.push_back(data_vec);
        } else if (data_vec[0][0] == 'C') {
            id_map[data_vec[1]] = data_vec[2];
        }
    }
    
    for (int i = 0; i < record_vvec.size(); ++i) {
        string message = id_map[record_vvec[i][1]];
        if (record_vvec[i][0][0] == 'E') message += "님이 들어왔습니다.";
        else message += "님이 나갔습니다.";
        answer.push_back(message);
    }
    
    return answer;
}