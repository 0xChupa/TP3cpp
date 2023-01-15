#include <iostream>
#include <string>
#include <vector>
#include "client.h"

Client::Client(int id, std::string firstName, std::string lastName) {
  _id = id;
  _firstName = firstName;
  _lastName = lastName;
}

int Client::getId() {
  return _id;
}

std::string Client::getFirstName() {
  return _firstName;
}

std::string Client::getLastName() {
  return _lastName;
}

std::vector<Product> Client::getShoppingCart() const {
  return _shoppingCart;
}

void Client::addProductToShoppingCart(const Product& p) {
  _shoppingCart.push_back(p);
}

void Client::clearShoppingCart() {
  _shoppingCart.clear();
}

void Client::updateProductQuantityInShoppingCart(const std::string& name, int quantity) {
  for (Product& p : _shoppingCart) {
    if (p.getTitle() == name) {
      p.addQuantity(quantity);
      return;
    }
  }
  std::cout << "Product not found" << std::endl;
}

void Client::removeProductFromShoppingCart(const std::string& name) {
  for (int i = 0; i < _shoppingCart.size(); i++) {
    if (_shoppingCart[i].getTitle() == name) {
      _shoppingCart.erase(_shoppingCart.begin() + i);
      return;
    }
  }
  std::cout << "Product not found" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Client& c) {
  os << "Client: " << c._firstName << " " << c._lastName << " (id: " << c._id << ")" << std::endl;
  os << "Shopping cart:" << std::endl;
  for (const Product& p : c._shoppingCart) {
    os << p << std::endl;
  }
  return os;
}