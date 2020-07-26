//Class name: Product 
//Goals: To create an object that stores the different pricing scheme parameters for a given product.
//       Products will be sorted in a binary search tree to allow for quicker lookup times


//Include Section
#include <iostream>
#include <string>
#include "Product.h"



//Method Name: default constructor Product()
//Goals: Create default constructor for default values
//Input: none
//Output: none
Product::Product(){
     Product::item_id = "0000";
     Product::price = 0; 
     Product::buy_x = 0; 
     Product::get_y = 0;
     Product::buy_x_count = 0; 
     Product::get_y_count = 0; 
     Product::added_tax = 0.00; 
     Product::bundle_other = "0000";
     Product::bundle_price = 0;

     Product::parent = NULL;
     Product::child_left = NULL;
     Product::child_right = NULL;
    
}//End default constructor


//Method Name: defined constructor Product()
//Goals: Create defined constructor for defined values
//Input: 
//      1. std::string item_id; //Item ID of product
//      2. int price; //Simple price of product
//      3. int buy_x; //Buy X amount of product to get Y amount free
//      4. int get_y; //Get Y amount of product free if X amount is bought
//      5. int buy_x_count; //Counter to keep track of how many products have been bought
//      6. int get_y_count; //Counter to keep track of how many free products have been credited
//      7. float added_tax; //Added tax percent (Ex. 9.25%)
//      8. std::string bundle_other; //Item ID of other bundled product
//      9. int bundle_price; //Price of bundled items 
//Output: none
Product::Product(std::string item_id, int price, int buy_x, int get_y, 
                int buy_x_count, int get_y_count, float added_tax,
                std::string bundle_other, int bundle_price){
    
    Product::item_id = item_id;
    Product::price = price; 
    Product::buy_x = buy_x; 
    Product::get_y = get_y;
    Product::buy_x_count = buy_x_count; 
    Product::get_y_count = get_y_count; 
    Product::added_tax = added_tax; 
    Product::bundle_other = bundle_other;
    Product::bundle_price = bundle_price;

    Product::parent = NULL;
    Product::child_left = NULL;
    Product::child_right = NULL;

}//End defined constructor


//Method Name: default deconstructor ~Product()
//Goals: Create default deconstructor
//Input: none
//Output: none
Product::~Product(){

    
}//End default deconstructor


//Method Name: GetItemID
//Goals: Return product item id
//Input: none
//Output: std::string item_id
std::string Product::GetItemID(){
    return Product::item_id;
}//End GetItemID method


//Method Name: GetPrice
//Goals: Return product simple price
//Input: none
//Output: int price
int Product::GetPrice(){
    return Product::price;
}//End GetPrice method


//Method Name: GetBuyX
//Goals: Return X amount of product needed to buy to get Y product free
//Input: none
//Output: int buy_x
int Product::GetBuyX(){
    return Product::buy_x;
}//End GetBuyX method


//Method Name: GetGetY
//Goals: Return Y amount of free product when X product is bought
//Input: none
//Output: int get_y
int Product::GetGetY(){
    return Product::get_y;
}//End GetGetY method


//Method Name: GetBuyXCount
//Goals: Return counter for how many products have been bought so far for Buy X, Get Y deal
//Input: none
//Output: int buy_x_count
int Product::GetBuyXCount(){
    return Product::buy_x_count;
}//End GetBuyXCount method


//Method Name: GetGetYCount
//Goals: Return counter for how many free products have been credited so far for Buy X, Get Y deal
//Input: none
//Output: int get_y_count
int Product::GetGetYCount(){
    return Product::get_y_count;
}//End GetGetYCount method


//Method Name: GetAddedTax
//Goals: Return percentage of added tax to be added
//Input: none
//Output: float added_tax
float Product::GetAddedTax(){
    return Product::added_tax;
}//End GetAddedTax method


//Method Name: GetBundleOther
//Goals: Return item_id of other product that is bundled with current product
//Input: none
//Output: std::string bundle_other
std::string Product::GetBundleOther(){
    return Product::bundle_other;
}//End GetBundleOther method


//Method Name: GetBundlePrice
//Goals: Return price of the cost of the bundled deal
//Input: none
//Output: int bundle_price
int Product::GetBundlePrice(){
    return Product::bundle_price;
}//End GetBundlePrice method


//Method Name: GetParent
//Goals: Return parent of the current tree node
//Input: none
//Output: Product* parent
Product* Product::GetParent(){
    return Product::parent;
}//End GetParent method


//Method Name: GetChildLeft
//Goals: Return left child of the current tree node
//Input: none
//Output: Product* child_left
Product* Product::GetChildLeft(){
    return Product::child_left;
}//End GetChildLeft method


//Method Name: GetChildRight
//Goals: Return right child of the current tree node
//Input: none
//Output: Product* child_right
Product* Product::GetChildRight(){
    return Product::child_right;
}//End GetChildRight method





//Method Name: SetItemID
//Goals: Set product item id
//Input: std::string item_id
//Output: none
void Product::SetItemID(std::string item_id){
    Product::item_id = item_id;
}//End SetItemID method


//Method Name: SetPrice
//Goals: Set product simple price
//Input: int price
//Output: none
void Product::SetPrice(int price){
    Product::price = price;
}//End SetPrice method


//Method Name: SetBuyX
//Goals: Set X amount of product needed to buy to get Y product free
//Input: int buy_x
//Output: none
void Product::SetBuyX(int buy_x){
    Product::buy_x = buy_x;
}//End SetBuyX method


//Method Name: SetGetY
//Goals: Set Y amount of free product when X product is bought
//Input: int get_y
//Output: none
void Product::SetGetY(int get_y){
    Product::get_y = get_y;
}//End SetGetY method


//Method Name: SetBuyXCount
//Goals: Set counter for how many products have been bought so far for Buy X, Get Y deal
//Input: int buy_x_count
//Output: none
void Product::SetBuyXCount(int buy_x_count){
    Product::buy_x_count = buy_x_count;
}//End SetBuyXCount method


//Method Name: SetGetYCount
//Goals: Set counter for how many free products have been credited so far for Buy X, Get Y deal
//Input: int get_y_count
//Output: none
void Product::SetGetYCount(int get_y_count){
    Product::get_y_count = get_y_count;
}//End SetGetYCount method


//Method Name: SetAddedTax
//Goals: Set percentage of added tax to be added
//Input: float added_tax
//Output: none
void Product::SetAddedTax(float added_tax){
    Product::added_tax = added_tax;
}//End SetAddedTax method


//Method Name: SetBundleOther
//Goals: Set item_id of other product that is bundled with current product
//Input: std::string bundle_other
//Output: none
void Product::SetBundleOther(std::string bundle_other){
    Product::bundle_other = bundle_other;
}//End SetBundleOther method


//Method Name: SetBundlePrice
//Goals: Set price of the cost of the bundled deal
//Input: int bundle_price
//Output: none
void Product::SetBundlePrice(int bundle_price){
    Product::bundle_price = bundle_price;
}//End SetBundlePrice method


//Method Name: SetParent
//Goals: Set parent of the current tree node
//Input: Product* parent
//Output: none
void Product::SetParent(Product* parent){
    Product::parent = parent;
}//End SetParent method


//Method Name: SetChildLeft
//Goals: Set left child of the current tree node
//Input: Product* child_left
//Output: none
void Product::SetChildLeft(Product* child_left){
    Product::child_left = child_left;
}//End SetChildLeft method


//Method Name: SetChildRight
//Goals: Set right child of the current tree node
//Input: Product* child_right
//Output: none
void Product::SetChildRight(Product* child_right){
    Product::child_right = child_right;
}//End SetChildRight method



//Method Name: Print
//Goals: Print all member data to console, except for parent and children
//Input: none
//Output: none
void Product::Print(){
    std::cout << "Item ID: " << Product::item_id << " Price: " << Product::price << " Buy X: " << Product::buy_x
    << " Get Y: " << Product::get_y << " Buy X Count: " << Product::buy_x_count << " Get Y Count " << Product::get_y_count
    << " Added Tax: " << Product::added_tax << " Other Bundle ID: " << Product::bundle_other << " Bundle Price: " << Product::bundle_price << std::endl;
}
//End Print method