/* 신규 아이디 추천 */

#include <string>
#include <vector>

using namespace std;

char special[] = {'-', '_', '.'}; 

void func1(string& id)
{
    for (int i = 0; i < id.length(); ++i)
    {
        if (id[i] >= 'A' && id[i] <= 'Z')
            id[i] += 32;
    }
}

void func2(string& id)
{
    string res = "";
    
    for (int i = 0; i < id.length(); ++i)
    {
        if ((id[i] >= 'a' && id[i] <= 'z') ||
        (id[i] >= '0' && id[i] <= '9') ||
        id[i] == special[0] || id[i] == special[1] || id[i] == special[2])
        {
            string tmp = {id[i]};
            res.append(tmp);
        }
    }

    id = res;
}

void func3(string& id)
{
    for (int i = 0; i < id.length(); ++i)
    {
        if (id[i] != '.') continue;

        int n = 0;
        while (id[i + 1 + n] == '.') n++;
        id.erase(i + 1, n);
    }
}

void func4(string& id)
{
    if (id[0] == '.') id.erase(0, 1);
    if (id[id.length() - 1] == '.') id.erase(id.length() - 1);
}

void func5(string& id)
{
    if (id.length() == 0) id.append("a");
}

void func6(string& id)
{
    if (id.length() < 16) return;

    id.erase(15, id.length() - 15);

    if (id[id.length() - 1] == '.') id.erase(id.length() - 1);    
}

void func7(string& id)
{
    if (id.length() > 2) return;

    string tmp = {id[id.length() - 1]};
    int len = 3 - id.length();
    for (int i = 0; i < len; ++i) {
        id.append(tmp);
    }
}

string solution(string id) {
    func1(id);
    func2(id);
    func3(id);
    func4(id);
    func5(id);
    func6(id);
    func7(id);

    return id;
}