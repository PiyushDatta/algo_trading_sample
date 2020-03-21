#include "include/alpaca_trading_api.h"
#include "../../utils/include/json_client.h"
#include "include/alpaca_trading_constants.h"

// init
TradeAPI::TradeAPI() { updateAccount(); }

// destructor
TradeAPI::~TradeAPI() {}

// get trading account
std::unordered_map<std::string, std::string> TradeAPI::getAccount() {
  return m_trading_acc;
}

// account member variables
bool TradeAPI::getAccountBlockedStatus() { return m_acc_blocked; }
bool TradeAPI::getTradingBlockedStatus() { return m_trading_blocked; }
bool TradeAPI::getTransfersBlockedStatus() { return m_transfers_blocked; }
bool TradeAPI::getTradeSuspendByUserStatus() { return m_trade_suspend_by_user; }
std::string TradeAPI::getAccountStatus() { return m_acc_status; }
std::string TradeAPI::getAccountCurrency() { return m_acc_currency; }
double TradeAPI::getBuyingPower() { return m_acc_buying_power; }
double TradeAPI::getAccountEquity() { return m_acc_equity; }
double TradeAPI::getPortfolioValue() { return m_portfolio_val; }
double TradeAPI::getAccountCash() { return m_acc_cash; }

// update trading account by performing a GET request on alpaca's rest api
std::unordered_map<std::string, std::string> TradeAPI::updateAccount() {

  // setup curl client to fetch request
  const std::string alpaca_url = getAlpacaRESTUrl(ACCOUNT_ENDPOINT);
  SimpleCURLClient::CurlClient curl_client(alpaca_url);
  // CurlClient curl_client(alpaca_url);
  std::vector<std::string> hdrs = {APCA_API_KEY_ID, APCA_API_SECRET_KEY};
  curl_client.setHeader(hdrs);

  // get request and keep curl response code
  std::pair<CURLcode, std::string> curl_resp = curl_client.sendGETRequest();

  // parse json if curl was okay
  if (curl_resp.first == CURLE_OK) {
    JsonClient json_client;

    std::pair<bool, nlohmann::json> json_res =
        json_client.jsonParse(curl_resp.second);

    // parse json result into a map for ease of use (because of known types)
    if (json_res.first) {
      // m_trading_acc = json_res.second.get<std::unordered_map<std::string,
      // bool>>; Json::StreamWriterBuilder builder; builder["indentation"] = "";
      // for (const auto &json_id : json_res.second.getMemberNames()) {
      //   m_trading_acc[json_id.c_str()] = json_res.second[json_id].asString();
      //   std::transform(m_trading_acc[json_id.c_str()].begin(),
      //                  m_trading_acc[json_id.c_str()].end(),
      //                  m_trading_acc[json_id.c_str()].begin(), ::tolower);

      //   // std::cout << json_id.c_str() << ": " <<
      //   // m_trading_acc[json_id.c_str()]
      //   // << std::endl;
      // }
      // update member account variables
      update_all_account_vars();
    }
  }
  // curl got a bad response
  else {
    std::cout << "\nERROR: Unsuccessful response from " << alpaca_url
              << std::endl;
    std::fprintf(stderr, "ERROR: curl_easy_perform() failed -  %s\n",
                 curl_easy_strerror(curl_resp.first));
  }

  return m_trading_acc;
}

// update all member variables for the account
void TradeAPI::update_all_account_vars() {
  m_acc_blocked = m_trading_acc["account_blocked"] != "false";
  m_trading_blocked = m_trading_acc["trading_blocked"] != "false";
  m_transfers_blocked = m_trading_acc["transfers_blocked"] != "false";
  m_trade_suspend_by_user = m_trading_acc["trade_suspended_by_user"] != "false";
  m_acc_status = m_trading_acc["status"];
  m_acc_currency = m_trading_acc["currency"];
  m_acc_buying_power = std::stod(m_trading_acc["buying_power"]);
  m_acc_equity = std::stod(m_trading_acc["equity"]);
  m_portfolio_val = std::stod(m_trading_acc["portfolio_value"]);
  m_acc_cash = std::stod(m_trading_acc["cash"]);
}

void TradeAPI::submitOrder(std::string &order_symbol, int &order_quantity,
                           std::string &order_side, std::string &order_type,
                           std::string &order_time_in_force) {

  // setup params
  nlohmann::json data;
  // data["symbol"] = order_symbol;
  // data["qty"] = std::to_string(order_quantity);
  // data["side"] = order_side;
  // data["type"] = order_type;
  // data["time_in_force"] = order_time_in_force;

  // // if(type == "limit")
  // // 	data["limit_price"] = limit_price;
  // // if(type == "stop" || type == "stop_limit")
  // // 	data["stop_price"] = stop_price;

  // Json::StreamWriterBuilder builder;
  // builder["indentation"] = "";
  // std::string params = Json::writeString(builder, data);

  // // setup curl client to fetch request
  // const std::string alpaca_url = getAlpacaRESTUrl(ORDER_ENDPOINT);
  // CurlClient curl_client(alpaca_url);
  // std::vector<std::string> hdrs = {APCA_API_KEY_ID, APCA_API_SECRET_KEY};
  // curl_client.setHeader(hdrs);

  // // get request and keep curl response code
  // std::pair<CURLcode, std::string> curl_resp =
  //     curl_client.sendPOSTRequest(params);

  // // parse json if curl was okay
  // if (curl_resp.first == CURLE_OK) {
  //   std::cout << "Order submitted successfully \n" << std::endl;
  //   std::cout << "Order response: " << curl_resp.second << "\n" << std::endl;
  // }
  // // curl got a bad response
  // else {
  //   std::cout << "\nERROR: Unsuccessful response from " << alpaca_url
  //             << std::endl;
  //   std::fprintf(stderr, "ERROR: curl_easy_perform() failed -  %s\n",
  //                curl_easy_strerror(curl_resp.first));
  // }
}
