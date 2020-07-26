//Class name: PriceScheme 
//Goals: To create a binary search tree full of product nodes where each product can be found by Item ID


#ifndef PRICESCHEME_H_EXISTS
#define PRICESCHEME_H_EXISTS

//Include Section
#include <iostream>
#include <string>

#include "Product.h"

class PriceScheme {
    private:
    Product* head_node;
        
    public:
        PriceScheme();
        ~PriceScheme();
        void DeleteNode(Product* current_node);
        void AddProductToScheme(Product* new_product);
        void AddProduct(Product* new_product, Product* root_node);
        Product* FindProductInScheme(std::string item_id);
        Product* FindProductFromNode(std::string item_id, Product* root_node);
        void PrintScheme();
        void PrintProduct(Product* current_node);
        

    protected:

};//End PriceScheme class declaration

#endif