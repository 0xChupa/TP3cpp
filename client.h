#pragma once

#include <string>
#include <vector>
#include "product.h"

class Client {
private:
  int _id;
  std::string _firstName;
  std::string _lastName;
  std::vector<Product> _shoppingCart;

public:
  Client(int id, std::string firstName, std::string lastName);
  int getId();
  std::string getFirstName();
  std::string getLastName();
  std::vector<Product> getShoppingCart() const;
  void addProductToShoppingCart(const Product& p);
  void clearShoppingCart();
  void updateProductQuantityInShoppingCart(const std::string& name, int quantity);
  void removeProductFromShoppingCart(const std::string& name);
  friend std::ostream& operator<<(std::ostream& os, const Client& c);
};


