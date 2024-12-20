#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

class InventoryItem {
private:
    int itemID;
    std::string name;
    std::string category;
    int quantity;
    int reorderLevel;

public:
    InventoryItem(int id, const std::string& itemName, const std::string& itemCategory, int qty, int reorderLvl)
        : itemID(id), name(itemName), category(itemCategory), quantity(qty), reorderLevel(reorderLvl) {}

    void updateStock(int qtyChange) {
        quantity += qtyChange;
    }

    bool isBelowReorderLevel() const {
        return quantity < reorderLevel;
    }

    void displayItem() const {
        std::cout << std::left << std::setw(10) << itemID
                  << std::setw(20) << name
                  << std::setw(20) << category
                  << std::setw(10) << quantity
                  << std::setw(15) << reorderLevel << "\n";
    }

    int getItemID() const { return itemID; }
    std::string getName() const { return name; }
    std::string getCategory() const { return category; }
    int getQuantity() const { return quantity; }

    std::string toCSV() const {
        return std::to_string(itemID) + "," + name + "," + category + "," + std::to_string(quantity) + "," + std::to_string(reorderLevel);
    }
};

class Inventory {
private:
    std::vector<InventoryItem> items;

public:
    void addItem(const InventoryItem& item) {
        items.push_back(item);
    }

    void updateItemStock(int itemID, int qtyChange) {
        for (auto& item : items) {
            if (item.getItemID() == itemID) {
                item.updateStock(qtyChange);
                std::cout << "Stock updated successfully.\n";
                return;
            }
        }
        std::cout << "Item ID not found!\n";
    }

    void displayAllItems() const {
        std::cout << std::left << std::setw(10) << "ID"
                  << std::setw(20) << "Name"
                  << std::setw(20) << "Category"
                  << std::setw(10) << "Quantity"
                  << std::setw(15) << "Reorder Level\n";
        std::cout << "-----------------------------------------------------------------\n";
        for (const auto& item : items) {
            item.displayItem();
        }
    }

    void searchItemByName(const std::string& name) const {
        for (const auto& item : items) {
            if (item.getName() == name) {
                item.displayItem();
                return;
            }
        }
        std::cout << "Item not found!\n";
    }

    void searchItemByCategory(const std::string& category) const {
        bool found = false;
        for (const auto& item : items) {
            if (item.getCategory() == category) {
                item.displayItem();
                found = true;
            }
        }
        if (!found) {
            std::cout << "No items found in this category!\n";
        }
    }

    void generateLowStockReport() const {
        std::cout << "Low Stock Items:\n";
        std::cout << std::left << std::setw(10) << "ID"
                  << std::setw(20) << "Name"
                  << std::setw(20) << "Category"
                  << std::setw(10) << "Quantity"
                  << std::setw(15) << "Reorder Level\n";
        std::cout << "-----------------------------------------------------------------\n";
        bool found = false;
        for (const auto& item : items) {
            if (item.isBelowReorderLevel()) {
                item.displayItem();
                found = true;
            }
        }
        if (!found) {
            std::cout << "No low stock items!\n";
        }
    }

    void exportDataToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            std::cout << "Error opening file for writing!\n";
            return;
        }

        file << "ID,Name,Category,Quantity,Reorder Level\n";
        for (const auto& item : items) {
            file << item.toCSV() << "\n";
        }

        std::cout << "Data exported to " << filename << " successfully.\n";
        file.close();
    }
};

void displayMenu() {
    std::cout << "\nWarehouse Inventory Management System\n";
    std::cout << "1. Add New Item\n";
    std::cout << "2. Update Stock Levels\n";
    std::cout << "3. View All Inventory\n";
    std::cout << "4. Search Item by Name\n";
    std::cout << "5. Search Item by Category\n";
    std::cout << "6. Generate Low Stock Report\n";
    std::cout << "7. Export Inventory Data to File\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Inventory inventory;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();  // Ignore newline character left in input buffer

        switch (choice) {
        case 1: {
            int id, quantity, reorderLevel;
            std::string name, category;

            std::cout << "Enter Item ID: ";
            std::cin >> id;
            std::cin.ignore();

            std::cout << "Enter Item Name: ";
            std::getline(std::cin, name);

            std::cout << "Enter Category: ";
            std::getline(std::cin, category);

            std::cout << "Enter Quantity: ";
            std::cin >> quantity;

            std::cout << "Enter Reorder Level: ";
            std::cin >> reorderLevel;

            InventoryItem item(id, name, category, quantity, reorderLevel);
            inventory.addItem(item);
            std::cout << "Item added successfully!\n";
            break;
        }
        case 2: {
            int id, qtyChange;
            std::cout << "Enter Item ID: ";
            std::cin >> id;
            std::cout << "Enter Quantity Change (+/-): ";
            std::cin >> qtyChange;

            inventory.updateItemStock(id, qtyChange);
            break;
        }
        case 3:
            inventory.displayAllItems();
            break;

        case 4: {
            std::string name;
            std::cout << "Enter Item Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            inventory.searchItemByName(name);
            break;
        }
        case 5: {
            std::string category;
            std::cout << "Enter Category: ";
            std::cin.ignore();
            std::getline(std::cin, category);

            inventory.searchItemByCategory(category);
            break;
        }
        case 6:
            inventory.generateLowStockReport();
            break;

        case 7: {
            std::string filename;
            std::cout << "Enter filename to export (e.g., inventory.csv): ";
            std::cin >> filename;

            inventory.exportDataToFile(filename);
            break;
        }
        case 8:
            std::cout << "Exiting the program. Goodbye!\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
