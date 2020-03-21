cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    alpaca_trading_api_test.cc
    ../src/third_party_broker_api/alpaca/alpaca_trading_api.cc
)

set(HEADERS
    ../src/third_party_broker_api/alpaca/include/alpaca_trading_api.h
    ../src/third_party_broker_api/alpaca/include/alpaca_trading_constants.h
)

# googletest
enable_testing()

add_executable(algo_trading_test "main.cc" ${SOURCES} ${HEADERS})
target_link_libraries(algo_trading_test simple_curl_cpp nlohmann_json::nlohmann_json gtest)

add_test(
    NAME algo_trading_test
    COMMAND algo_trading_test
)
