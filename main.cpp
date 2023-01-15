#include <string>
#include <vector>
#include <iostream>
#include "store.h"
#include "client.h"
#include "product.h"
#include "order.h"

int main()
{
    Store s("EasyStore", "1 rue de la Boutique", "01 02 03 04 05");
    bool continueProgram = true;
    while (true)
    {
        std::cout << "Menu principal :" << std::endl;
        std::cout << "1. Gestion du magasin" << std::endl;
        std::cout << "2. Gestion des utilisateurs" << std::endl;
        std::cout << "3. Gestion des commandes" << std::endl;
        std::cout << "4. Quitter" << std::endl;
        std::cout << "Votre choix : ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Sous-menu de gestion du magasin
            while (continueProgram = true)
            {
                std::cout << "Gestion du magasin :" << std::endl;
                std::cout << "1. Ajouter un produit" << std::endl;
                std::cout << "2. Afficher les produits" << std::endl;
                std::cout << "3. Mettre à jour les quantités" << std::endl;
                std::cout << "4. Retour" << std::endl;
                std::cout << "Votre choix : ";

                int choice;
                std::cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    // Ajout d'un produit
                    std::string title;
                    std::string description;
                    int quantity;
                    double unitPrice;
                    std::cout << "Titre : ";
                    std::cin >> title;
                    std::cout << "Description : ";
                    std::cin >> description;
                    std::cout << "Quantité : ";
                    std::cin >> quantity;
                    std::cout << "Prix unitaire : ";
                    std::cin >> unitPrice;
                    Product p(title, description, quantity, unitPrice);
                    s.addProduct(p);
                    break;
                }
                case 2:
                {
                    // Affichage des produits
                    s.printAllProducts();
                    break;
                }
                case 3:
                {
                    // Mise à jour des quantités
                    std::string name;
                    int quantity;
                    std::cout << "Nom : ";
                    std::cin >> name;
                    std::cout << "Quantité : ";
                    std::cin >> quantity;
                    s.updateProductQuantityByName(name, quantity);
                    break;
                }
                case 4:
                {
                    // Retour au menu principal
                    continueProgram = false;
                    break;
                }
                default:
                {
                    std::cout << "Choix invalide" << std::endl;
                    break;
                }
                }
            }
        }
        case 2:
        {
            // sous-menu de gestion des utilisateurs
            while (continueProgram = true)
            {
                std::cout << "Gestion des utilisateurs :" << std::endl;
                std::cout << "1. Ajouter un client" << std::endl;
                std::cout << "2. Afficher les clients" << std::endl;
                std::cout << "3. Retour" << std::endl;
                std::cout << "Votre choix : ";

                int choice;
                std::cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    // Ajout d'un client
                    int id;
                    std::string firstName;
                    std::string lastName;
                    std::cout << "Nom : ";
                    std::cin >> firstName;
                    std::cout << "Prénom : ";
                    std::cin >> lastName;
                    std::cout << "ID : ";
                    std::cin >> id;
                    Client c(id, firstName, lastName);
                    s.addClient(c);
                    break;
                }
                case 2:
                {
                    // Affichage des clients
                    s.printAllClients();
                    break;
                }
                case 3:
                {
                    // Retour au menu principal
                    continueProgram = false;
                    break;
                }
                default:
                {
                    std::cout << "Choix invalide" << std::endl;
                    break;
                }
                }
            }
        }
        case 3:
        {
            // sous-menu de gestion des commandes
            while (continueProgram = true)
            {
                std::cout << "Gestion des commandes :" << std::endl;
                std::cout << "1. Ajouter une commande" << std::endl;
                std::cout << "2. Afficher les commandes" << std::endl;
                std::cout << "3. Retour" << std::endl;
                std::cout << "Votre choix : ";

                int choice;
                std::cin >> choice;

                switch (choice)
                {
                case 1:
                {
                    // Création d'une commande
                    int clientID;
                    std::cout << "ID om du client: " << std::endl;
                    std::cin >> clientID;
                    for (int i = 0; i < s._clients.size(); i++)
                    {
                        if (s._clients[i].getId() == clientID)
                        {
                            std::cout << "Client trouvé" << std::endl;
                        }
                    }

                    Client c = s.printClientByIdOrName(clientID);
                    Order o(c, std::vector<Product>(), "Pending", s._orders.size() + 1);
                    std::string productName;
                    while (true)
                    {
                        std::cout << "Ajouter un produit (ou entrez 'done' pour valider la commande): ";
                        std::cin >> productName;
                        if (productName == "done")
                        {
                            break;
                        }
                        Product p = s.printProductByName(productName);
                        o.addProduct(p);
                    }
                    s.addOrder(o);
                    break;
                }
                case 2:
                {
                    // Valider la commande d'un client
                    std::string clientIdOrName;
                    std::cout << "ID ou nom du client: ";
                    std::cin >> clientIdOrName;
                    s.validateClientOrder(clientIdOrName);
                    break;
                }
                case 3:
                {
                    // Modifier le statut d'une commande
                    int orderId;
                    std::string newStatus;
                    std::cout << "ID de la commande: ";
                    std::cin >> orderId;
                    std::cout << "Nouveau statut: ";
                    std::cin >> newStatus;
                    s.updateOrderStatus(orderId, newStatus);
                    break;
                }
                case 4:
                {
                    // Afficher toutes les commandes
                    s.printAllOrders();
                    break;
                }
                case 5:
                {
                    // Retour au menu principal
                    continueProgram = false;
                    break;
                }
                default:
                {
                    std::cout << "Choix invalide" << std::endl;
                    break;
                }
                }
            }
        }
        case 4:
        {
            // Quitter le programme
            continueProgram = false;
            break;
        }
        default:
        {
            std::cout << "Choix invalide" << std::endl;
            break;
        }
        }
    }
    return 0;
}
