#include <string>

#ifndef ALGO_TRADING_ALPACATRADINGAPI_CONSTANTS_H
#define ALGO_TRADING_ALPACATRADINGAPI_CONSTANTS_H

// base
const std::string BASE_PAPER_URL = "https://paper-api.alpaca.markets";
const std::string VERSION_NUM = "v2";

// different endpoints
const std::string ACCOUNT_ENDPOINT = "account";
const std::string ORDER_ENDPOINT = "orders";

// personal
const std::string APCA_API_KEY_ID = "NO_ID";
const std::string APCA_API_SECRET_KEY = "NO_KEY";

// constructs the full url given an specified endpoint
const std::string getAlpacaRESTUrl(std::string endpoint) {
  const std::string res_alpaca_url(BASE_PAPER_URL + "/" + VERSION_NUM + "/" + endpoint);
  return res_alpaca_url;
}

#endif // ALGO_TRADING_ALPACATRADINGAPI_CONSTANTS_H
