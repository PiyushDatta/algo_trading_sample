#include <algorithm>
#include <curl_client.h>
#include <iostream>
#include <string>
#include <typeinfo>
#include <unordered_map>

#ifndef ALGO_TRADING_ALPACATRADINGAPI_H
#define ALGO_TRADING_ALPACATRADINGAPI_H

class TradeAPI {
public:
  TradeAPI();
  ~TradeAPI();
  bool getAccountBlockedStatus();
  bool getTradingBlockedStatus();
  bool getTransfersBlockedStatus();
  bool getTradeSuspendByUserStatus();
  std::string getAccountStatus();
  std::string getAccountCurrency();
  double getBuyingPower();
  double getAccountEquity();
  double getPortfolioValue();
  double getAccountCash();
  std::unordered_map<std::string, std::string> getAccount();
  std::unordered_map<std::string, std::string> updateAccount();
  void submitOrder(std::string &order_symbol, int &order_quantity,
                   std::string &order_side, std::string &order_type,
                   std::string &order_time_in_force);

private:
  std::unordered_map<std::string, std::string> m_trading_acc;
  bool m_acc_blocked;
  bool m_trading_blocked;
  bool m_transfers_blocked;
  bool m_trade_suspend_by_user;
  std::string m_acc_status;
  std::string m_acc_currency;
  double m_acc_buying_power;
  double m_acc_equity;
  double m_portfolio_val;
  double m_acc_cash;
  void update_all_account_vars();
};

#endif // ALGO_TRADING_ALPACATRADINGAPI_H
