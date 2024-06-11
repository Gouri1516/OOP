#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Product {
    std::string name;
    int id;
    double price;
};

void writeProductData(const std::vector<Product>& products) {
    std::ofstream outputFile("products.txt"); 

    if (outputFile.is_open()) {
        for (const auto& product : products) {
            outputFile << product.name << "," << product.id << "," << product.price << "\n";
        }
        outputFile.close();
        std::cout << "Product data has been written to products.txt successfully.\n";
    } else {
        std::cerr << "Error: Unable to open file for writing.\n";
    }
}

std::vector<Product> readProductData() {
    std::vector<Product> products;
    std::ifstream inputFile("products.txt"); 

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            Product product;
            std::istringstream iss(line);
            std::getline(iss, product.name, ',');
            iss >> product.id;
            iss.ignore(); 
            iss >> product.price;
            products.push_back(product);
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file for reading.\n";
    }

    return products;
}

void searchProduct(const std::vector<Product>& products, const std::string& searchTerm) {
    bool found = false;
    for (const auto& product : products) {
        if (product.name == searchTerm) {
            std::cout << "Product found:\n";
            std::cout << "Name: " << product.name << ", ID: " << product.id << ", Price: " << product.price << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Product not found.\n";
    }
}

int countProducts(const std::vector<Product>& products) {
    return products.size();
}

void displayAllProducts(const std::vector<Product>& products) {
    std::cout << "All products:\n";
    for (const auto& product : products) {
        std::cout << "Name: " << product.name << ", ID: " << product.id << ", Price: " << product.price << "\n";
    }
}

int main() {
    std::vector<Product> products = {
        {"Product1", 1, 10.0},
        {"Product2", 2, 20.0},
        {"Product3", 3, 30.0}
    };

    writeProductData(products);

    products = readProductData();

    std::string searchTerm = "Product2";
    searchProduct(products, searchTerm);

    int productCount = countProducts(products);
    std::cout << "Total number of products: " << productCount << "\n";

    displayAllProducts(products);

    return 0;
}

