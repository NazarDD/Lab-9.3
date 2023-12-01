#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Unit { PIECES, KG, LITERS };

string UnitStr[] = { "��.", "��", "�" };

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
        cout << "1. ������ �����\n"
            << "2. �������� �����\n"
            << "3. ���������� �����\n"
            << "4. ��������� �� ������\n"
            << "5. ��������� �� ���������\n"
            << "6. ������� ���������� ��� �����\n"
            << "7. ������� ������ � �������\n"
            << "8. ������� ������� ��� ������\n"
            << "0. �����\n";
        cout << "������ ��� ����: ";
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
            cout << "������ ����� ������: ";
            cin >> productName;
            DisplayProductInfo(products, numProducts, productName);
            break;
        }
        case 7: {
            string storeName;
            cout << "������ ����� ��������: ";
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
            cout << "������� ����. ���� �����, ��������� �� ���.\n";
        }
    } while (menuItem != 0);

    delete[] products;

    return 0;
}


void AddProduct(Product* products, int& numProducts) {
    if (numProducts < 100) {
        cout << "������ ����� ������: ";
        cin >> products[numProducts].name;
        cout << "������ ����� ��������: ";
        cin >> products[numProducts].store;
        cout << "������ ����: ";
        cin >> products[numProducts].price;
        cout << "������ �������: ";
        cin >> products[numProducts].quantity;
        cout << "������ ������� ���������� (0 - ��., 1 - ��, 2 - �): ";
        int unit;
        cin >> unit;
        products[numProducts].unit = static_cast<Unit>(unit);

        numProducts++;
    }
    else {
        cout << "��������� ����������� ������� ������.\n";
    }
}

void RemoveProduct(Product* products, int& numProducts) {
    if (numProducts > 0) {
        string productName;
        cout << "������ ����� ������, ���� �� ������ ��������: ";
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
            cout << "����� ������ ��������.\n";
        }
        else {
            cout << "����� �� ��������.\n";
        }
    }
    else {
        cout << "���� ������ ��� ���������.\n";
    }
}

void EditProduct(Product* products, int numProducts) {
    if (numProducts > 0) {
        string productName;
        cout << "������ ����� ������, ���� �� ������ ������������: ";
        cin >> productName;

        int index = -1;
        for (int i = 0; i < numProducts; i++) {
            if (products[i].name == productName) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            cout << "������ ���� ����� ������: ";
            cin >> products[index].name;
            cout << "������ ���� ����� ��������: ";
            cin >> products[index].store;
            cout << "������ ���� ����: ";
            cin >> products[index].price;
            cout << "������ ���� �������: ";
            cin >> products[index].quantity;
            cout << "������ ���� ������� ���������� (0 - ��., 1 - ��, 2 - �): ";
            int unit;
            cin >> unit;
            products[index].unit = static_cast<Unit>(unit);

            cout << "����� ������ ������������.\n";
        }
        else {
            cout << "����� �� ��������.\n";
        }
    }
    else {
        cout << "���� ������ ��� �����������.\n";
    }
}

void DisplayProductsInStore(Product* products, int numProducts, const string& storeName) {
    bool found = false;
    cout << "������ � ������� '" << storeName << "':\n";
    for (int i = 0; i < numProducts; i++) {
        if (products[i].store == storeName) {
            cout << "�����: " << products[i].name << ", ֳ��: " << products[i].price << " UAH, ʳ������: " << products[i].quantity << " "
                << UnitStr[products[i].unit] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "������ �� �������� � ������� '" << storeName << "'.\n";
    }
}

void SortByName(Product* products, int numProducts) {
    if (numProducts > 1) {
        cout << "���������� �� ������ ������:\n";
        for (int i = 0; i < numProducts - 1; i++) {
            for (int j = 0; j < numProducts - i - 1; j++) {
                if (products[j].name > products[j + 1].name) {
                    swap(products[j], products[j + 1]);
                }
            }
        }
        cout << "������ ���������� �� ������.\n";
    }
    else {
        cout << "����������� ������ ��� ���������� �� ������.\n";
    }
}

void SortByStore(Product* products, int numProducts) {
    if (numProducts > 1) {
        cout << "���������� �� ������ ��������:\n";
        for (int i = 0; i < numProducts - 1; i++) {
            for (int j = 0; j < numProducts - i - 1; j++) {
                if (products[j].store > products[j + 1].store) {
                    swap(products[j], products[j + 1]);
                }
            }
        }
        cout << "������ ���������� �� ������ ��������.\n";
    }
    else {
        cout << "����������� ������ ��� ���������� �� ������ ��������.\n";
    }
}

void DisplayProductInfo(Product* products, int numProducts, const string& productName) {
    bool found = false;
    cout << "���������� ��� ����� '" << productName << "':\n";
    for (int i = 0; i < numProducts; i++) {
        if (products[i].name == productName) {
            cout << "�������: " << products[i].store << ", ֳ��: " << products[i].price << " UAH, ʳ������: " << products[i].quantity << " "
                << UnitStr[products[i].unit] << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "����� '" << productName << "' �� ��������.\n";
    }
}

void DisplayAllProducts(Product* products, int numProducts) {
    if (numProducts > 0) {
        cout << "========================================================================================" << endl;
        cout << "| ����� ������      | �������           | ֳ�� (UAH) | ʳ������ | ������� ���������� |" << endl;
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
        cout << "���� ������ ��� �����������." << endl;
    }
}
