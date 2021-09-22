//----------------------------------------------------------------------------------
// [ 2019 KAKAO BLIND 2ND ] https://programmers.co.kr/skill_check_assignments/67
//----------------------------------------------------------------------------------

#include "test.h"

const string SERVER = "https://kox947ka1a.execute-api.ap-northeast-2.amazonaws.com/prod/users";
const string TOKEN = "";
string AUTH_KEY;

Connection conn(SERVER);


enum class COMMAND { NONE = 0, UP, RIGHT, DOWN, LEFT, PICK, DROP, END };
struct Truck { int x = 0, y = 0, cnt = 0; };
struct Area { int min_x = 0, min_y = 0, max_x = 0, max_y = 0; };
struct Position { int x = -1, y = -1; Position() {} Position(int _x, int _y) : x(_x), y(_y) {} };
struct Route { int score = -1; vector<int> cmds; void clear() { score = -1; cmds.clear(); } };

const int DX[] = { 0, 0, 1, 0, -1 }, DY[] = { 0, 1, 0, -1, 0 };



// [ PROBLEM 1-1 ] (score: 272)
//const int PROBLEM = 1;
//const int BOARD_SIZE = 5;
//const int TRUCK_SIZE = 4;
//const int CASE[] = {2, 3, 3, 3};
//Area areas[TRUCK_SIZE - 1] = {
//   {0,0,2,2},
//   {3,0,4,2},
//   {0,3,2,4},
//   {3,3,4,4}
//};

// [ PROBLEM 1-2 ] (score: 275)
//const int PROBLEM = 1;
//const int BOARD_SIZE = 5;
//const int TRUCK_SIZE = 3;
//const int CASE[] = { 2, 3, 3, 3 };
//Area areas[TRUCK_SIZE] = {
//   {0,0,2,2},
//   {0,3,2,4},
//   {3,0,4,4},
//};

// [ PROBLEM 2-1 ] (score: 679)
//const int PROBLEM = 2;
//const int BOARD_SIZE = 60;
//const int TRUCK_SIZE = 9;
//const int CASE[] = { 2, 3, 3, 3 };
//Area areas[TRUCK_SIZE] = {
//    {0, 0, 19, 19},
//    {0, 20, 19, 39},
//    {0, 40, 19, 59},
//    {20, 0, 39, 19},
//    {20, 20, 39, 39},
//    {20, 40, 39, 59},
//    {40, 0, 59, 19},
//    {40, 20, 59, 39},
//    {40, 40, 59, 59}
//};

// [ PROBLEM 2-2 ] (score: 678)
const int PROBLEM = 2;
const int BOARD_SIZE = 60;
const int TRUCK_SIZE = 9;
const int CASE[] = { 2, 3, 2, 3 };
Truck extra_truck;
const Area AREAS[TRUCK_SIZE] = {
    {0, 0, 19, 19},
    {0, 20, 19, 39},
    {0, 40, 19, 59},
    {20, 0, 39, 19},
    {20, 20, 39, 39},
    {20, 40, 39, 59},
    {40, 0, 59, 19},
    {40, 20, 59, 39},
    {40, 40, 59, 59}
};
const int EXTRA_DESTS[3][2][2] = {
    { {50, 37}, {59, 55} },
    { {43, 55}, {12, 4} },
    { {41, 5}, {16, 9} }
};
int extra_idx = 0;


int board[BOARD_SIZE][BOARD_SIZE];
Truck trucks[TRUCK_SIZE];
Route routes[BOARD_SIZE][BOARD_SIZE] = {};

Value start_api(int problem) {
    return post(conn, "/start", json_to_string(make_json("problem", problem)));
}

Value locations_api() {
    return get(conn, "/locations");
}

Value trucks_api() {
    return get(conn, "/trucks");
}

Value simulate_api(const Value& cmds) {
    return put(conn, "/simulate", json_to_string(make_json("commands", cmds)));
}

Value score_api() {
    return get(conn, "/score");
}

Value past_api(int day) {
    return get2(string("https://grepp-cloudfront.s3.ap-northeast-2.amazonaws.com/programmers_imgs/competition-imgs/2021kakao/problem2_day-") + to_string(day) + string(".json"));
}

void past_log() {
    vector<int> vec1(3600), vec2(3600);
    const int time[] = { 480, 720};
    for (int i = 1; i <= 3; ++i) {
        Value json = past_api(i);
        for (auto key : json.getMemberNames()) {
            if (stoi(key) < time[0]) continue;
            if (time[1] <= stoi(key)) break;
            for (auto data : json[key]) {
                vec1[data[0].asInt()]++;
                vec2[data[1].asInt()]++;
            }
        }
    }
    auto it1 = max_element(vec1.begin(), vec1.end());
    auto it2 = max_element(vec2.begin(), vec2.end());
    

    cout << (it1 - vec1.begin()) << " " << (it2 - vec2.begin()) << endl;
}

Value make_command(int truck_id, const vector<int>& cmds) {
    Value json;
    json["truck_id"] = truck_id;
    for (auto i : cmds) json["command"].append(i);
    return json;
}

Position zero_position(const Truck& truck, const Area& area) {
    Position dest;
    int min_dist = INT_MAX, dist;
    for (int i = area.min_y; i <= area.max_y; ++i) {
        for (int j = area.min_x; j <= area.max_x; ++j) {
            if (board[i][j] != 0 || (dist = abs(truck.x - j) + abs(truck.y - i)) > min_dist) continue;
            dest = { j, i };
            min_dist = dist;
        }
    }
    return dest;
}

Position pick_position(int min_cnt, const Truck& truck, const Area& area) {
    Position dest;
    int max_score = -0x7fffffff;
    for (int i = area.min_y; i <= area.max_y; ++i) {
        for (int j = area.min_x; j <= area.max_x; ++j) {
            if (PROBLEM == 2) 
            if (board[i][j] < min_cnt) continue;
            if (j == EXTRA_DESTS[extra_idx][0][0] && i == EXTRA_DESTS[extra_idx][0][1]) continue; // extra
            if (j == EXTRA_DESTS[extra_idx][1][0] && i == EXTRA_DESTS[extra_idx][1][1]) continue; // extra
            int dist = abs(truck.x - j) + abs(truck.y - i), val = board[i][j] - min_cnt + 1;
            if (val - (dist >> 1) > max_score) {
                max_score = val - (dist >> 1);
                dest = { j, i };
            }
        }
    }
    return dest;
}

vector<int> best_route(int min_cnt, const Truck& truck, const Position& dest) {
    vector<int> cmds;
    const COMMAND cmd_x = (truck.x == dest.x) ? COMMAND::NONE : ((truck.x > dest.x) ? COMMAND::LEFT : COMMAND::RIGHT);
    const COMMAND cmd_y = (truck.y == dest.y) ? COMMAND::NONE : ((truck.y > dest.y) ? COMMAND::DOWN : COMMAND::UP);
    const int dx = DX[(int)cmd_x], dy = DY[(int)cmd_y];
    const int width = abs(truck.x - dest.x) + 1, height = abs(truck.y - dest.y) + 1;

    routes[truck.y][truck.x] = { 0, {} };
    for (int i = 0; i < height; ++i) {
        int y = truck.y + (dy * i);
        for (int j = 0; j < width; ++j) {
            int x = truck.x + (dx * j);
            if (y != dest.y && routes[y + dy][x].score < routes[y][x].score + max(0, board[y + dy][x] - min_cnt + 1)) {
                routes[y + dy][x].score = routes[y][x].score + max(0, board[y + dy][x] - min_cnt + 1);
                routes[y + dy][x].cmds = routes[y][x].cmds;
                routes[y + dy][x].cmds.push_back((int)cmd_y);
            }
            if (x != dest.x && routes[y][x + dx].score < routes[y][x].score + max(0, board[y][x + dx] - min_cnt + 1)) {
                routes[y][x + dx].score = routes[y][x].score + max(0, board[y][x + dx] - min_cnt + 1);
                routes[y][x + dx].cmds = routes[y][x].cmds;
                routes[y][x + dx].cmds.push_back((int)cmd_x);
            }
        }
    }

    cmds = routes[dest.y][dest.x].cmds;

    for (int i = 0; i < height; ++i) {
        int y = truck.y + (dy * i);
        for (int j = 0; j < width; ++j) {
            int x = truck.x + (dx * j);
            routes[y][x].clear();
        }
    }
    
    return cmds;
}

vector<int> truck_logic(int id) {
    vector<int> commands;
    Truck& truck = trucks[id];
    const Area& area = AREAS[id];

    // 위치 초기화
    if (truck.x < area.min_x || truck.y < area.min_y) {
        while (truck.x < area.min_x) {
            commands.push_back((int)COMMAND::RIGHT);
            truck.x += 1;
            if (commands.size() == 10) return commands;
        }
        while (truck.y < area.min_y) {
            commands.push_back((int)COMMAND::UP);
            truck.y += 1;
            if (commands.size() == 10) return commands;
        }
    }

    while (commands.size() != 10) {
        // 루트 설정
        Position dest = zero_position(truck, area);
        vector<int> routes;
        int min_cnt = -1;

        if (dest.x != -1) { // 비어있는 곳 O
            if (truck.cnt == 0) { // 자전거 여유분 X
                min_cnt = CASE[0];
                if ((dest = pick_position(min_cnt, truck, area)).x == -1) return commands;
                routes = best_route(min_cnt, truck, dest);
            }
            else { // 자전거 여유분 O
                min_cnt = CASE[1];
                routes = best_route(min_cnt, truck, dest);
            }
        }
        else { // 비어있는 곳 X
            if (truck.cnt == 20) return commands;
            if (truck.cnt == 0) { // 자전거 여유분 X
                min_cnt = CASE[2];
                if ((dest = pick_position(min_cnt, truck, area)).x == -1) return commands;
                routes = best_route(min_cnt, truck, dest);
            }
            else { // 자전거 여유분 O
                min_cnt = CASE[3];
                if ((dest = pick_position(min_cnt, truck, area)).x == -1) return commands;
                routes = best_route(min_cnt, truck, dest);
            }
        }

        // 픽업
        while (board[truck.y][truck.x] >= min_cnt && truck.cnt != 20) {
            commands.push_back((int)COMMAND::PICK);
            board[truck.y][truck.x]--;
            truck.cnt++;
            if (commands.size() == 10) return commands;
        }

        // 픽업 및 이동
        for (auto cmd : routes) {
            while (board[truck.y][truck.x] >= min_cnt && truck.cnt != 20) { // 픽업
                commands.push_back((int)COMMAND::PICK);
                board[truck.y][truck.x]--;
                truck.cnt++;
                if (commands.size() == 10) return commands;
            }

            commands.push_back(cmd); // 이동
            truck.x += DX[cmd]; truck.y += DY[cmd];
            if (commands.size() == 10) return commands;
        }

        if (board[truck.y][truck.x] == 0 && truck.cnt > 0) { // 드랍
            if (truck.cnt == 1 || commands.size() == 9) {
                commands.push_back((int)COMMAND::DROP);
                truck.cnt--;
                board[truck.y][truck.x]++;
            }
            else {
                commands.push_back((int)COMMAND::DROP); commands.push_back((int)COMMAND::DROP);
                truck.cnt -= 2;
                board[truck.y][truck.x] += 2;
            }
        }
    }

    return commands;
}

vector<int> extra_logic(int time) {
    vector<int> commands;
    static bool extra_flags[3] = {};
    static int mode = 0; // 0: to_pick, 1: pick, 2 : to_drop, 3: drop
    static const int dest_cnt = 20;

    extra_idx = time / 240;
    
    // 위치 초기화
    if (extra_flags[extra_idx] == false) {
        mode = 0;
        extra_flags[extra_idx] = true;
    }

    vector<int> cmds;
    while (commands.size() != 10) {
        switch (mode) {
            case 0:
                cmds = best_route(999, extra_truck, Position(EXTRA_DESTS[extra_idx][0][0], EXTRA_DESTS[extra_idx][0][1]));
                for (auto i : cmds) {
                    commands.push_back(i);
                    extra_truck.x += DX[i]; extra_truck.y += DY[i];
                    if (commands.size() == 10) return commands;
                }
                break;
            case 1:
                while (extra_truck.cnt != dest_cnt) {
                    commands.push_back((int)COMMAND::PICK);
                    extra_truck.cnt++;
                    if (board[extra_truck.y][extra_truck.x] <= 1 || commands.size() == 10) return commands;
                }
                break;
            case 2:
                cmds = best_route(999, extra_truck, Position(EXTRA_DESTS[extra_idx][1][0], EXTRA_DESTS[extra_idx][1][1]));
                for (auto i : cmds) {
                    commands.push_back(i);
                    extra_truck.x += DX[i]; extra_truck.y += DY[i];
                    if (commands.size() == 10) return commands;
                }
                break;
            case 3:
                while (extra_truck.cnt != 0) {
                    commands.push_back((int)COMMAND::DROP);
                    extra_truck.cnt--;
                    if (commands.size() == 10) return commands;
                }
                break;
            
        }
        mode = (mode + 1) % 4;
    }

    return commands;
}

int main() {
    RestClient::init();
    conn.AppendHeader("X-Auth-Token", TOKEN);
    conn.AppendHeader("Content-Type", "application/json");
    conn.AppendHeader("Authorization", start_api(PROBLEM)["auth_key"].asString());

    std::cout << "auth_key: " << conn.GetHeaders()["Authorization"] << "\n";

    for (int time = 0;; ++time) {
        // 맵 업데이트
        Value locations = locations_api()["locations"];
        for (auto location : locations) {
            board[location["id"].asInt() % BOARD_SIZE][location["id"].asInt() / BOARD_SIZE] = location["located_bikes_count"].asInt();
        }

        // 트럭 로직
        Value commands;
        vector<int> cmds = extra_logic(time);
        if (!cmds.empty()) commands.append(make_command(TRUCK_SIZE, cmds));
        for (int id = 0; id < TRUCK_SIZE; ++id) {
            vector<int> cmds = truck_logic(id);
            if (cmds.empty()) continue;
            commands.append(make_command(id, cmds));
        }
        if (commands.empty()) commands.append(string_to_json("{\"truck_id\": 0, \"command\": [0]}"));

        // 실행
        Value result = simulate_api(commands);

        cout << trucks_api()["trucks"][9]["location_id"] << " (" << extra_truck.cnt << ")" << "\n";
        cout << "distance: " << result["distance"] << "\n";
        cout << "fail: " << result["failed_requests_count"] << "\n";

        if (result["status"] == "finished") break;
    }

    // 점수 출력
    std::cout << score_api() << endl;
    RestClient::disable();
}

