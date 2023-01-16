#include <iostream>
#include <string>
#include <vector>
#include "client.h"
#include "product.h"
#include "order.h"
#include "store.h"

int main()
{
    // Création du magasin
    Store store("Easy Store", "Rue de la paix", "01 02 03 04 05");
    // Création des clients
    Client client1(1, "Alexandre", "Tavernier");
    Client client2(2, "Nina", "Guerin");
    Client client3(3, "Clois", "Fernandes");
    store.addClient(client1);
    store.addClient(client2);
    store.addClient(client3);

    // Création de quelques produits
    Product product1("Livre", "Harry Potter et la Chambre des Secrets", 10, 8);
    Product product2("Livre", "Harry Potter et le Prisonnier d'Azkaban", 8, 8);
    Product product3("Livre", "Harry Potter et la Coupe de Feu", 3, 8);
    Product product4("Cartable", "Cartable Tintin", 5, 30);
    Product product5("Cartable", "Cartable Harry Potter", 2, 30);
    Product product6("Cartable", "Cartable Pokemon", 1, 30);
    Product product7("PS4", "PS4 Slim", 2, 300);
    Product product8("PS4", "PS4 Pro", 1, 400);
    Product product9("Nintendo Switch", "Switch Lite", 0, 200);
    Product product10("Nintendo Switch", "Switch Pro", 1, 300);
    store.addProduct(product1);
    store.addProduct(product2);
    store.addProduct(product3);
    store.addProduct(product4);
    store.addProduct(product5);
    store.addProduct(product6);
    store.addProduct(product7);
    store.addProduct(product8);
    store.addProduct(product9);
    store.addProduct(product10);

    bool quit = false;

    while (!quit)
    {
        std::cout << "1. Gestion du magasin \n2. Gestion des utilisateurs \n3. Gestion des commandes \n4. Quitter \n"
                  << std::endl;
        int choiceInitial;
        std::cin >> choiceInitial;

        switch (choiceInitial)
        {
        case 1:
        {
            while(true)
            std::cout << "Gestion du magasin \n1. Ajouter un produit \n2. Afficher les produits \n3. Mettre à jour les quantités \n4. Retour \n"
                      << std::endl;
            int choiceSecondaire;
            std::cin >> choiceSecondaire;
            switch (choiceSecondaire)
            {
            case 1:
            {
                std::string title;
                std::cout << "Entrez le titre du produit" << std::endl;
                std::cin >> title;
                std::string description;
                std::cout << "Entrez la description du produit" << std::endl;
                std::cin >> description;
                int quantity;
                std::cout << "Entrez la quantité du produit" << std::endl;
                std::cin >> quantity;
                double unitPrice;
                std::cout << "Entrez le prix unitaire du produit" << std::endl;
                std::cin >> unitPrice;
                Product product(title, description, quantity, unitPrice);
                store.addProduct(product);
                break;
            }
            case 2:
            {
                store.printAllProducts();
                break;
            }
            case 3:
            {
                std::string title;
                std::cout << "Entrez le titre du produit" << std::endl;
                std::cin >> title;
                int quantity;
                std::cout << "Entrez la quantité de produit à ajouter" << std::endl;
                std::cin >> quantity;
                store.updateProductQuantityByName(title, quantity);
                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                std::cout << "Choix invalide" << std::endl;
                break;
            }
            }
        }
        case 2:
        {
            std::cout << "Gestion des utilisateurs \n1. Ajouter un client \n2. Afficher les clients \n3. Retour \n"
                      << std::endl;
            int choiceSecondaire;
            std::cin >> choiceSecondaire;
            switch (choiceSecondaire)
            {
            case 1:
            {
                std::string firstName;
                std::cout << "Entrez le prénom du client" << std::endl;
                std::cin >> firstName;
                std::string lastName;
                std::cout << "Entrez le nom du client" << std::endl;
                std::cin >> lastName;
                Client client(store._clients.size() + 1, firstName, lastName);
                store.addClient(client);
                break;
            }
            case 2:
            {
                store.printAllClients();
                break;
            }
            case 3:
            {
                exit;
            }
            default:
            {
                std::cout << "Choix invalide" << std::endl;
                break;
            }
            }
        }
        case 3:
        {
            std::cout << "Gestion des commandes \n1. Ajouter une commande \n2. Afficher les commandes \n3. Changer le statut d'une commande \n4. Retour \n"
                      << std::endl;
            int choiceSecondaire;
            std::cin >> choiceSecondaire;
            switch (choiceSecondaire)
            {
            case 1:
            {
                // Création d'une commande
                int clientID;
                std::cout << "ID du client: " << std::endl;
                std::cin >> clientID;
                for (int i = 0; i < store._clients.size(); i++)
                {
                    if (store._clients[i].getId() == clientID)
                    {
                        std::cout << "Client trouvé" << std::endl;
                    }
                }

                Client c = store.printClientByIdOrName(clientID);
                Order o(c, std::vector<Product>(), "Pending", store._orders.size() + 1);
                std::string productName;
                while (true)
                {
                    std::cout << "Ajouter un produit (ou entrez 'done' pour valider la commande): ";
                    std::cin >> productName;
                    if (productName == "done")
                    {
                        break;
                    }
                    Product product = store.printProductByName(productName);
                    o.addProduct(product);
                }
                store.addOrder(o);
                break;
            }
            case 2:
            {
                store.printAllOrders();
                break;
            }
            case 3:
            {
                int orderID;
                std::cout << "ID de la commande: " << std::endl;
                std::cin >> orderID;
                std::string status;
                std::cout << "Nouveau statut: (1. Pending / 2. Shipped / 3. Delivered ) " << std::endl;
                std::cin >> status;
                if (status == "1")
                {
                    status = "Pending";
                    store.updateOrderStatus(orderID, status);
                }
                else if (status == "2")
                {
                    status = "Shipped";
                    store.updateOrderStatus(orderID, status);
                }
                else if (status == "3")
                {
                    status = "Delivered";
                    store.updateOrderStatus(orderID, status);
                }
                else
                {
                    std::cout << "Statut invalide" << std::endl;
                }
            }
            case 4:
            {
                break;
            }
            default:
            {
                std::cout << "Choix invalide" << std::endl;
                break;
            }
            }
        }
        case 4:
        {
            quit = true;
            break;
        }
        default:
        {
            std::cout << "Choix invalide" << std::endl;
            break;
        }
        }
    }