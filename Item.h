//Class name: Item 
//Goals: To create a basic object to store a product that is in a customer's cart


#ifndef ITEM_H_EXISTS
#define ITEM_H_EXISTS

//Include Section
#include <iostream>
#include <string>

class Item {
    private:
        std::string item_id;  
        int subtotal;  
        

    public:
        Item();
        Item(std::string input_value, int price);

        void SetItemID(std::string);
        std::string GetItemID(void);
        void SetSubtotal(int);
        int GetSubtotal(void);

    protected:

};//End Item class declaration

#endif