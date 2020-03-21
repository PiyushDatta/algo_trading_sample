#include "include/json_client.h"

// init
JsonClient::JsonClient() {}

// destructor
JsonClient::~JsonClient() {}

// parse raw string into json
std::pair<bool, nlohmann::json> JsonClient::jsonParse(std::string raw_data) {

  try {
    // got a good json parsable response
    m_json_data = nlohmann::json::parse(raw_data);
    std::cout << "\nSuccessfully parsed JSON data" << '\n';
    std::cout << "\nJSON data size: " << m_json_data.size() << '\n';
    std::cout << "\nJSON data received:" << '\n';
    std::cout << m_json_data << '\n';
    m_json_parse_success = true;
  } catch (const nlohmann::json::exception &e) {
    std::cout << "ERROR: Could not parse HTTP data as JSON" << '\n';
    // output exception information
    std::cout << "ERROR: " << e.what() << '\n';
    std::cout << "Exception id: " << e.id << '\n';
    m_json_parse_success = false;
  }

  return std::make_pair(m_json_parse_success, m_json_data);
}
