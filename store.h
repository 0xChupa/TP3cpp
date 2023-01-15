#pragma once

#include <string>
#include <vector>
#include "product.h"
#include "client.h"
#include "order.h"

class Store {
private:
  std::vector<Product> _products;

    std::string _name;
    std::string _address;
    std::string _phone;

public:
    std::vector<Client> _clients;
    std::vector<Order> _orders;
    Store(std::string name, std::string address, std::string phone);
    std::string getName();
    std::string getAddress();
    std::string getPhone();
    void addProduct(Product& p);
    void printAllProducts();
    Product printProductByName(std::string& name);
    void updateProductQuantityByName(std::string& name, int quantity);

    void addClient(Client& c);
    void addOrder(Order& o);
    void printAllClients();
    Client printClientByIdOrName(int id);
    void addProductToClientShoppingCart(std::string& clientIdOrName, Product& p);
    void removeProductFromClientShoppingCart( std::string& clientIdOrName, std::string& productName);
    void updateProductQuantityInClientShoppingCart( std::string& clientIdOrName,  std::string& productName, int quantity);

    void validateClientOrder(std::string& clientIdOrName);
    void updateOrderStatus(int orderId, std::string newStatus);
    void printAllOrders();
    void printClientOrders(std::string& clientIdOrName);
};