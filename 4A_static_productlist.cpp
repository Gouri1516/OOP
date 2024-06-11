#include <iostream>
#include <string>

struct Product {
    int productId;
    std::string productName;
    double productPrice;
    double gst;
};

const int MAX_PRODUCTS = 100;
Product productList[MAX_PRODUCTS];
int productCount = 0;

void insertProduct() {
    if (productCount == MAX_PRODUCTS) {
        std::cout << "List is full. Cannot insert more products.\n";
        return;
    }
    Product newProduct;
    std::cout << "Enter product ID: ";
    std::cin >> newProduct.productId;
    std::cin.ignore(); // Ignore newline character
    std::cout << "Enter product name: ";
    std::getline(std::cin, newProduct.productName);
    std::cout << "Enter product price: ";
    std::cin >> newProduct.productPrice;
    std::cout << "Enter GST: ";
    std::cin >> newProduct.gst;

    productList[productCount++] = newProduct;
    std::cout << "Product inserted successfully.\n";
}

void deleteProduct() {
    int productId;
    std::cout << "Enter product ID to delete: ";
    std::cin >> productId;
    bool found = false;
    for (int i = 0; i < productCount; ++i) {
        if (productList[i].productId == productId) {
            for (int j = i; j < productCount - 1; ++j) {
                productList[j] = productList[j + 1];
            }
            --productCount;
            found = true;
            std::cout << "Product deleted successfully.\n";
            break;
        }
    }
    if (!found) {
        std::cout << "Product not found.\n";
    }
}

void searchProduct() {
    int productId;
    std::cout << "Enter product ID to search: ";
    std::cin >> productId;
    bool found = false;
    for (int i = 0; i < productCount; ++i) {
        if (productList[i].productId == productId) {
            std::cout << "Product found:\n";
            std::cout << "Product ID: " << productList[i].productId << "\n";
            std::cout << "Product Name: " << productList[i].productName << "\n";
            std::cout << "Product Price: " << productList[i].productPrice << "\n";
            std::cout << "GST: " << productList[i].gst << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Product not found.\n";
    }
}

void displayAllProducts() {
    if (productCount == 0) {
        std::cout << "No products in the list.\n";
        return;
    }
    std::cout << "Product List:\n";
    for (int i = 0; i < productCount; ++i) {
        std::cout << "Product ID: " << productList[i].productId << "\n";
        std::cout << "Product Name: " << productList[i].productName << "\n";
        std::cout << "Product Price: " << productList[i].productPrice << "\n";
        std::cout << "GST: " << productList[i].gst << "\n";
        std::cout << "-------------------------\n";
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert a new product\n";
        std::cout << "2. Delete a product\n";
        std::cout << "3. Search for a product\n";
        std::cout << "4. Display all products\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                insertProduct();
                break;
            case 2:
                deleteProduct();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                displayAllProducts();
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

