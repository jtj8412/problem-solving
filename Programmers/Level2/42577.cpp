#include <string>
#include <vector>
#include <unordered_map>

#define SIZE_MAX 20

using namespace std;

vector<int> GetSizeVector(const vector<string> &vec) {
    vector<int> size_vec;
    int size_arr[SIZE_MAX + 1] = {};

    for (int i = 0; i < vec.size(); ++i) {
        size_arr[vec[i].size()] = 1;
    }
    for (int i = 1; i < SIZE_MAX - 1; ++i) {
        if (size_arr[i] == 1)
            size_vec.push_back(i);
    }
    return size_vec;
}

bool solution(vector<string> phone_book) {
    unordered_map<string, bool> um;
    vector<int> size_vec = GetSizeVector(phone_book);
    int phone_book_size = phone_book.size();
    int size_vec_size = size_vec.size();

    for (int i = 0; i < phone_book_size; ++i) {
        int phone_size = phone_book[i].size();
        for (int j = 0; j < size_vec_size && phone_size > size_vec[j]; ++j) {
            um.insert(make_pair(phone_book[i].substr(0, size_vec[j]), true));
        }
    }

    for (int i = 0; i < phone_book_size; ++i) {
        if (um.find(phone_book[i]) != um.end())
            return false;
    }

    return true;
}