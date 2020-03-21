cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    third_party_broker_api/alpaca/alpaca_trading_api.cc
    utils/json_client.cc
)

set(HEADERS
    third_party_broker_api/alpaca/include/alpaca_trading_api.h
    third_party_broker_api/alpaca/include/alpaca_trading_constants.h
    utils/include/json_client.h
)

add_executable(algo_trading_src "main.cc" ${SOURCES} ${HEADERS})
target_link_libraries(algo_trading_src simple_curl_cpp nlohmann_json::nlohmann_json)
