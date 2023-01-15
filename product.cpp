#include <iostream>
#include <string>
#include "product.h"

Product::Product(std::string title, std::string description, int quantity, double price)
    : _title(title), _description(description), _quantity(quantity), _price(price) {}

std::string Product::getTitle() const { 
    return _title; 
    }

std::string Product::getDescription() const { 
    return _description; 
    }

int Product::getQuantity() const { 
    return _quantity; 
    }

double Product::getPrice() const { 
    return _price; 
    }

void Product::addQuantity(int amount) { 
    _quantity += amount; 
    }

void Product::removeQuantity(int amount) { 
    _quantity -= amount; 
    }

std::ostream& operator<<(std::ostream& out, const Product& p) {
  std::cout << "Title: " << p.getTitle() << std::endl;
  std::cout << "Description: " << p.getDescription() << std::endl;
  std::cout << "Quantity: " << p.getQuantity() << std::endl;
  std::cout << "Price: " << p.getPrice() << std::endl;
  return out;
}
