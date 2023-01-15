#pragma once
#include <string>

class Product {
private:
  std::string _title;
  std::string _description;
  int _quantity;
  double _price;

public:
  Product(std::string title, std::string description, int quantity, double price);

  std::string getTitle() const;
  std::string getDescription() const;
  int getQuantity() const;
  double getPrice() const;

  void addQuantity(int amount);
  void removeQuantity(int amount);
  friend std::ostream& operator<<(std::ostream& out, const Product& p);
};
