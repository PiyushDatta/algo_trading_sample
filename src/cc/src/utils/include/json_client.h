#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <utility>

#ifndef UTILS_JSONCLIENT_H
#define UTILS_JSONCLIENT_H

class JsonClient {
public:
  JsonClient();
  ~JsonClient();
  std::pair<bool, nlohmann::json> jsonParse(std::string raw_data);

private:
  nlohmann::json m_json_data;
  bool m_json_parse_success;
};

#endif // UTILS_JSONCLIENT_H
