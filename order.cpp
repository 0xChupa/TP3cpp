#include "order.h"
#include "client.h"

Order::Order(Client client, std::vector<Product> products, std::string status, int id) 
    : _client(client), _products(products), _status(status), _id(id) {}

Client Order::getClient() {
     return _client; 
}

std::vector<Product> Order::getProducts() { 
    return _products; 
}

std::string Order::getStatus() { 
    return _status; 
}

void Order::addProduct(Product& p) { 
    _products.push_back(p); 
}

std::ostream& operator<<(std::ostream& os, Order& o) {
    os << "Client: " << o._client.getFirstName() << " " << o._client.getLastName() << std::endl;
    os << "Products: " << std::endl;
    for (Product p : o._products) {
        os << p << std::endl;
    }
    os << "Status: " << o._status << std::endl;
    return os;
}

std::string Order::setStatus() {
    std::string status;
    std::cout << "Enter status: \n 1. Pending \n 2. Shipped \n 3. Delivered \n";
    std::cin >> status;
    if (status == "1") {
        _status = "Pending";
    } else if (status == "2") {
        _status = "Shipped";
    } else if (status == "3") {
        _status = "Delivered";
    } else {
        std::cout << "Invalid status" << std::endl;
    }
}

int Order::getId() {
    return _id;
}