#include <iostream>
#include <string>
#include "store.h"

Store::Store(std::string name, std::string address, std::string phone) {
    _name = name;
    _address = address;
    _phone = phone;
}

std::string Store::getName() {
    return _name;
}

std::string Store::getAddress() {
    return _address;
}

std::string Store::getPhone() {
    return _phone;
}

void Store::addProduct(Product& p) { 
    _products.push_back(p); 
}

void Store::printAllProducts()  {
  for (Product& p : _products) {
    std::cout << p << std::endl;
  }
}

void Store::validateClientOrder(std::string& clientIdOrName) {
  for (Client& c : _clients) {
    if (c.getId() == std::stoi(clientIdOrName) || c.getFirstName() == clientIdOrName || c.getLastName() == clientIdOrName) {
      if (c.getShoppingCart().size() == 0) {
        std::cout << "Shopping cart is empty" << std::endl;
        return;
      }
      Order o(c, c.getShoppingCart(), "Pending", _orders.size() + 1);
      _orders.push_back(o);
      c.clearShoppingCart();
      std::cout << "Order validated" << std::endl;
      return;
    }
  }
  std::cout << "Client not found" << std::endl;
}  

Product Store::printProductByName(std::string& name) {
  for (Product& p : _products) {
    if (p.getTitle() == name) {
      return Product(p);
    }
  }
  std::cout << "Product not found" << std::endl;
}

void Store::updateProductQuantityByName(std::string& name, int quantity) {
  for (Product& p : _products) {
    if (p.getTitle() == name) {
      p.addQuantity(quantity);
      return;
    }
  }
  std::cout << "Product not found" << std::endl;
}

void Store::addClient(Client& c) { 
  _clients.push_back(c); 
}

void Store::addOrder(Order& o) { 
  _orders.push_back(o); 
}

void Store::printAllClients() {
  for (Client& c : _clients) {
    std::cout << c << std::endl;
  }
}

Client Store::printClientByIdOrName(int id) {
  for (Client& c : _clients) {
    if (c.getId() == id) {
      return Client(c);
    }
  }
  std::cout << "Client not found" << std::endl;
}

void Store::addProductToClientShoppingCart(std::string& clientIdOrName, Product& p) {
  for (Client& c : _clients) {
    if (c.getFirstName() == clientIdOrName || c.getLastName() == clientIdOrName || std::to_string(c.getId()) == clientIdOrName) {
      c.addProductToShoppingCart(p);
      return;
    }
  }
  std::cout << "Client not found" << std::endl;
}

void Store::removeProductFromClientShoppingCart(std::string& clientIdOrName, std::string& productName) {
  for (Client& c : _clients) {
    if (c.getFirstName() == clientIdOrName || c.getLastName() == clientIdOrName || std::to_string(c.getId()) == clientIdOrName) {
      c.removeProductFromShoppingCart(productName);
      return;
    }
  }
  std::cout << "Client not found" << std::endl;
}

void Store::printAllOrders() {
  for (Order& o : _orders) {
    std::cout << o << std::endl;
  }
}

void Store::updateOrderStatus(int orderId, std::string newStatus) {
  for (Order& o : _orders) {
    if (o.getId() == orderId) {
      o.setStatus();
      return;
    }
  }
  std::cout << "Order not found" << std::endl;
}