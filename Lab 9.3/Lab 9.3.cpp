#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Unit { PIECES, KG, LITERS };

string UnitStr[] = { "шт.", "кг", "л" };

struct Product {
    string name;
    string store;
    double price;
    int quantity;
    Unit unit;
};

void AddProduct(Product* products, int& numProducts);
void RemoveProduct(Product* products, int& numProducts);
void EditProduct(Product* products, int numProducts);
void SortByName(Product* products, int numProducts);
void SortByStore(Product* products, int numProducts);
void DisplayProductInfo(Product* products, int numProducts, const string& productName);
void DisplayProductsInStore(Product* products, int numProducts, const string& storeName);
void DisplayAllProducts(Product* products, int numProducts);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int numProducts = 0;
    const int maxProducts = 100;
    Product* products = new Product[maxProducts];

    int menuItem;
    do {
        cout << "1. Додати товар\n"
            << "2. Видалити товар\n"
            << "3. Редагувати товар\n"
            << "4. Сортувати за назвою\n"
            << "5. Сортувати за магазином\n"
            << "6. Вивести інформацію про товар\n"
            << "7. Вивести товари в магазині\n"
            << "8. Вивести таблицю всіх товарів\n"
            << "0. Вихід\n";
        cout << "Введіть ваш вибір: ";
        cin >> menuItem;

        switch (menuItem) {
        case 1:
            AddProduct(products, numProducts);
            break;
        case 2:
            RemoveProduct(products, numProducts);
            break;
        case 3:
            EditProduct(products, numProducts);
            break;
        case 4:
            SortByName(products, numProducts);
            break;
        case 5:
            SortByStore(products, numProducts);
            break;
        case 6: {
            string productName;
            cout << "Введіть назву товару: ";
            cin >> productName;
            DisplayProductInfo(products, numProducts, productName);
            break;
        }
        case 7: {
            string storeName;
            cout << "Введіть назву магазину: ";
            cin >> storeName;
            DisplayProductsInStore(products, numProducts, storeName);
            break;
        }
        case 8: {
            DisplayAllProducts(products, numProducts);
            break;
        }
              
        case 0:
            break;
        default:
            cout << "Невірний вибір. Будь ласка, спробуйте ще раз.\n";
        }
    } while (menuItem != 0);

    delete[] products;

    return 0;
}


void AddProduct(Product* products, int& numProducts) {
    if (numProducts < 100) {
        cout << "Введіть назву товару: ";
        cin >> products[numProducts].name;
        cout << "Введіть назву магазину: ";
        cin >> products[numProducts].store;
        cout << "Введіть ціну: ";
        cin >> products[numProducts].price;
        cout << "Введіть кількість: ";
        cin >> products[numProducts].quantity;
        cout << "Введіть одиницю вимірювання (0 - шт., 1 - кг, 2 - л): ";
        int unit;
        cin >> unit;
        products[numProducts].unit = static_cast<Unit>(unit);

        numProducts++;
    }
    else {
        cout << "Досягнуто максимальну кількість товарів.\n";
    }
}

void RemoveProduct(Product* products, int& numProducts) {
    if (numProducts > 0) {
        string productName;
        cout << "Введіть назву товару, який ви хочете видалити: ";
        cin >> productName;

        int index = -1;
        for (int i = 0; i < numProducts; i++) {
            if (products[i].name == productName) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < numProducts - 1; i++) {
                products[i] = products[i + 1];
            }
            numProducts--;
            cout << "Товар успішно видалено.\n";
        }
        else {
            cout << "Товар не знайдено.\n";
        }
    }
    else {
        cout << "Немає товарів для видалення.\n";
    }
}

void EditProduct(Product* products, int numProducts) {
    if (numProducts > 0) {
        string productName;
        cout << "Введіть назву товару, який ви хочете відредагувати: ";
        cin >> productName;

        int index = -1;
        for (int i = 0; i < numProducts; i++) {
            if (products[i].name == productName) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            cout << "Введіть нову назву товару: ";
            cin >> products[index].name;
            cout << "Введіть нову назву магазину: ";
            cin >> products[index].store;
            cout << "Введіть нову ціну: ";
            cin >> products[index].price;
            cout << "Введіть нову кількість: ";
            cin >> products[index].quantity;
            cout << "Введіть нову одиницю вимірювання (0 - шт., 1 - кг, 2 - л): ";
            int unit;
            cin >> unit;
            products[index].unit = static_cast<Unit>(unit);

            cout << "Товар успішно відредаговано.\n";
        }
        else {
            cout << "Товар не знайдено.\n";
        }
    }
    else {
        cout << "Немає товарів для редагування.\n";
    }
}

void DisplayProductsInStore(Product* products, int numProducts, const string& storeName) {
    bool found = false;
    cout << "Товари в магазині '" << storeName << "':\n";
    for (int i = 0; i < numProducts; i++) {
        if (products[i].store == storeName) {
            cout << "Назва: " << products[i].name << ", Ціна: " << products[i].price << " UAH, Кількість: " << products[i].quantity << " "
                << UnitStr[products[i].unit] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Товари не знайдено в магазині '" << storeName << "'.\n";
    }
}

void SortByName(Product* products, int numProducts) {
    if (numProducts > 1) {
        cout << "Сортування за назвою товару:\n";
        for (int i = 0; i < numProducts - 1; i++) {
            for (int j = 0; j < numProducts - i - 1; j++) {
                if (products[j].name > products[j + 1].name) {
                    swap(products[j], products[j + 1]);
                }
            }
        }
        cout << "Товари відсортовані за назвою.\n";
    }
    else {
        cout << "Недостатньо товарів для сортування за назвою.\n";
    }
}

void SortByStore(Product* products, int numProducts) {
    if (numProducts > 1) {
        cout << "Сортування за назвою магазину:\n";
        for (int i = 0; i < numProducts - 1; i++) {
            for (int j = 0; j < numProducts - i - 1; j++) {
                if (products[j].store > products[j + 1].store) {
                    swap(products[j], products[j + 1]);
                }
            }
        }
        cout << "Товари відсортовані за назвою магазину.\n";
    }
    else {
        cout << "Недостатньо товарів для сортування за назвою магазину.\n";
    }
}

void DisplayProductInfo(Product* products, int numProducts, const string& productName) {
    bool found = false;
    cout << "Інформація про товар '" << productName << "':\n";
    for (int i = 0; i < numProducts; i++) {
        if (products[i].name == productName) {
            cout << "Магазин: " << products[i].store << ", Ціна: " << products[i].price << " UAH, Кількість: " << products[i].quantity << " "
                << UnitStr[products[i].unit] << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Товар '" << productName << "' не знайдено.\n";
    }
}

void DisplayAllProducts(Product* products, int numProducts) {
    if (numProducts > 0) {
        cout << "========================================================================================" << endl;
        cout << "| Назва товару      | Магазин           | Ціна (UAH) | Кількість | Одиниця вимірювання |" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < numProducts; i++) {
            cout << "| " << setw(18) << left << products[i].name
                << "| " << setw(18) << left << products[i].store
                << "| " << setw(11) << right << products[i].price
                << "| " << setw(9) << right << products[i].quantity
                << "| " << setw(20) << left << UnitStr[products[i].unit] << "|" << endl;
        }

        cout << "========================================================================================" << endl;
    }
    else {
        cout << "Немає товарів для відображення." << endl;
    }
}
