#include "../src/third_party_broker_api/alpaca/include/alpaca_trading_api.h"
#include <gtest/gtest.h>
#include <string>

const std::string HEADER_GET_URL = "https://postman-echo.com/headers";
const std::string GET_URL = "https://postman-echo.com/get?foo1=bar1&foo2=bar2";
const std::string POST_URL = "https://postman-echo.com/post";
const std::string DELETE_URL = "https://postman-echo.com/delete";
std::string actual_resp = "";

class TradeAPITest : public testing::Test {
public:
  TradeAPI *trade_api;

  virtual void SetUp() { trade_api = new TradeAPI(); }

  virtual void TearDown() { delete trade_api; }
};

TEST_F(TradeAPITest, GetTradingAccount) {
    std::cout << "here!";
//   EXPECT_EQ(GET_URL, trade_api->getAccount());
}
