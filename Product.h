//Class name: Product 
//Goals: To create an object that stores the different pricing scheme parameters for a given product.
//       Products will be sorted in a binary search tree to allow for quicker lookup times


#ifndef PRODUCT_H_EXISTS
#define PRODUCT_H_EXISTS

//Include Section
#include <iostream>
#include <string>

class Product {
    private:
        Product* parent; //Parent node
        Product* child_left;  //Child node to the left (decreasing)
        Product* child_right; //Child node to the right (increasing)
        
        std::string item_id; //Item ID of product
        int price; //Simple price of product ($30.37 is represented as 3037)
        int buy_x; //Buy X amount of product to get Y amount free
        int get_y; //Get Y amount of product free if X amount is bought
        int buy_x_count; //Counter to keep track of how many products have been bought
        int get_y_count; //Counter to keep track of how many free products have been credited
        float added_tax; //Added tax percent (Ex. 9.25%)
        std::string bundle_other; //Item ID of other bundled product
        int bundle_price; //Price of bundled items 
        

    public:
        //Constructors
        Product();
        Product(std::string item_id, int price, int buy_x, int get_y, 
                int buy_x_count, int get_y_count, float added_tax,
                std::string bundle_other, int bundle_price);
        
        //Deconstructors
        ~Product();
        
        //Getters
        std::string GetItemID();
        int GetPrice();
        int GetBuyX();
        int GetGetY();
        int GetBuyXCount();
        int GetGetYCount();
        float GetAddedTax();
        std::string GetBundleOther();
        int GetBundlePrice();
        Product* GetParent();
        Product* GetChildLeft();
        Product* GetChildRight();

        //Setters
        void SetItemID(std::string item_id);
        void SetPrice(int price);
        void SetBuyX(int buy_x);
        void SetGetY(int get_y);
        void SetBuyXCount(int buy_x_count);
        void SetGetYCount(int get_y_count);
        void SetAddedTax(float added_tax);
        void SetBundleOther(std::string bundle_other);
        void SetBundlePrice(int bundle_price);
        void SetParent(Product* parent);
        void SetChildLeft(Product* child_left);
        void SetChildRight(Product* child_right);

        //Additional Methods
        void Print();

    protected:

};//End Product class declaration

#endif