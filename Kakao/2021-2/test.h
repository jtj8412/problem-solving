#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <restclient-cpp/restclient.h> // source: https://github.com/mrtazz/restclient-cpp
#include <restclient-cpp/connection.h> // source: https://github.com/mrtazz/restclient-cpp
#include <json/json.h> // source: https://github.com/open-source-parsers/jsoncpp

using namespace std;
using namespace RestClient;
using namespace Json;

CharReaderBuilder _reader_builder;
CharReader* _reader = _reader_builder.newCharReader();
StreamWriterBuilder _writer_builder;

Value string_to_json(const string& s) {
    Value json;
    String errs;

    if (!_reader->parse(s.c_str(), s.c_str() + s.size(), &json, &errs)) {
        cout << "\n\nError: StringToJson()\n" << errs << "\n\n";
        return NULL;
    }

    return json;
}

String json_to_string(const Value& json) {
    return writeString(_writer_builder, json);
}

Value make_json(const String& key, const Value& value) {
    Value json;
    json[key] = value;
    return json;
}

Value make_json(const String& key, const vector<Value>& vec) {
    Value json;
    for (unsigned i = 0; i < vec.size(); ++i)
        json[key].append(vec[i]);
    return json;
}

Value get(Connection& conn, const string& url) {
    return string_to_json(conn.get(url).body);
}

Value post(Connection& conn, const string& url, const string& data) {
    return string_to_json(conn.post(url, data).body);
}

Value put(Connection& conn, const string& url, const string& data) {
    return string_to_json(conn.put(url, data).body);
}

Value get2(const string& uri) {
    return string_to_json(RestClient::get(uri).body);
}



void console_clear() {
    system("cls");
}

void console_pos(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

