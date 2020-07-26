//Class name: Checkout 
//Goals: To create a basic object to store the functionality of the checkout lane


#ifndef CHECKOUT_H_EXISTS
#define CHECKOUT_H_EXISTS

//Include Section
#include <iostream>
#include <string>
#include <list>
#include "Item.h"
#include "PriceScheme.h"

class Checkout {
    private:
        std::list<Item> cart;
        std::list<Item>::iterator it;
        PriceScheme* price_scheme;
        
        

    public:
        Checkout();
        Checkout(PriceScheme* new_scheme);
        ~Checkout();
        void Scan(std::string item_id);
        void Print();
        int GetTotal();
        void ApplySimplePrice();
        void ApplyBuyXGetY();
        void ApplyBundle();
        void ApplyTaxes();



    protected:

};//End Checkout class declaration

#endif