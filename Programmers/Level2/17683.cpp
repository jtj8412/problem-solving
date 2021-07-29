/* [3차] 방금그곡 */

#include <string>
#include <vector>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)", name, music;
    int answer_time = 0, time, idx, music_len;

    for (auto musicinfo : musicinfos) {
        time = (stoi(musicinfo.substr(6, 2)) - stoi(musicinfo.substr(0, 2))) * 60 - stoi(musicinfo.substr(3, 2)) + stoi(musicinfo.substr(9, 2));
        if (time <= answer_time) continue;
        idx = musicinfo.find(',', 12);
        name = musicinfo.substr(12, idx - 12);
        music = musicinfo.substr(idx + 1, musicinfo.size() - idx);
        for (idx = 0, music_len = music.size(); music[idx] != '\0'; ++idx) {
            if (music[idx] == '#') --music_len;
        }
        while (music_len < time) {
            music += music;
            music_len += music_len;
        }
        for (idx = music.size() - 1; music_len != time; --idx, --music_len) {
            if (music[idx] == '#') { ++music_len; continue; }
        }
        music.erase(idx + 1, music.size() - idx - 1);
        for (idx = -1; (idx = music.find(m, idx + 1)) != string::npos;) {
            if (music[idx + m.size()] == '#') continue;
            answer = name;
            answer_time = time;
            break;
        }
    }
    
    return answer;
}