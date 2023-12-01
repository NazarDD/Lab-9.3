#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 9.3/Lab 9.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(ProductFunctionsTest)
    {
    public:
        TEST_METHOD(TestSortByName)
        {
            int numProducts = 3;
            Product* products = new Product[numProducts];

            products[0] = { "Banana", "StoreA", 2.5, 10, Unit::KG };
            products[1] = { "Apple", "StoreB", 1.8, 15, Unit::PIECES };
            products[2] = { "Orange", "StoreC", 3.0, 8, Unit::KG };

            SortByName(products, numProducts);

            Assert::AreEqual(products[0].name, std::string("Apple"));
            Assert::AreEqual(products[1].name, std::string("Banana"));
            Assert::AreEqual(products[2].name, std::string("Orange"));

            delete[] products;
        }

        TEST_METHOD(TestSortByStore)
        {
            int numProducts = 3;
            Product* products = new Product[numProducts];

            products[0] = { "Banana", "StoreC", 2.5, 10, Unit::KG };
            products[1] = { "Apple", "StoreA", 1.8, 15, Unit::PIECES };
            products[2] = { "Orange", "StoreB", 3.0, 8, Unit::KG };

            SortByStore(products, numProducts);

            Assert::AreEqual(products[0].store, std::string("StoreA"));
            Assert::AreEqual(products[1].store, std::string("StoreB"));
            Assert::AreEqual(products[2].store, std::string("StoreC"));

            delete[] products;
        }
    };
}
