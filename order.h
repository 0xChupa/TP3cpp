#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "client.h"
#include "product.h"

class Order {
private:
  Client _client;
  std::vector<Product> _products;
  std::string _status;
  int _id; 

public:
  Order(Client client, std::vector<Product> products, std::string status, int id);
  int getId();
  Client getClient();
  std::vector<Product> getProducts();
  std::string getStatus();
  std::string setStatus();
  void addProduct(Product& p);
  friend std::ostream& operator<<(std::ostream& os, Order& o);
};
