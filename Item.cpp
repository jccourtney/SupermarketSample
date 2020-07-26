//Class name: Item 
//Goals: To create a basic object to store a product that is in a customer's cart


//Include Section
#include <iostream>
#include <string>
#include "Item.h"


//Method Name: default constructor Item()
//Goals: Create default constructor for default values
//Input: none
//Output: none
Item::Item(){
    Item::item_id = "";
    Item::subtotal = 0;
}//End default constructor


//Method Name: defined constructor Item()
//Goals: Create defined constructor for defined values
//Input: 
//      1. std::string input_value
//      2. int price
//Output: none
Item::Item(std::string input_value, int price){
    Item::item_id = input_value;
    Item::subtotal = price;

}//End defined constructor


//Method Name: SetItemID
//Goals: Set the value for the item ID of a product in the cart
//Input: std::string new_item_id
//Output: none
void Item::SetItemID(std::string new_item_id){
    Item::item_id = new_item_id;
}//End SetItemID method


//Method Name: GetItemID
//Goals: Get the value for the item ID of the product in the cart
//Input: none
//Output: std::string
std::string Item::GetItemID(){
    return Item::item_id;

}//End GetItemID method


//Method Name: SetSubtotal
//Goals: Set the value for the item subtotal of a product in the cart
//Input: std::string new_subtotal
//Output: none
void Item::SetSubtotal(int new_subtotal){
    Item::subtotal = new_subtotal;
}//End SetSubtotal method


//Method Name: GetItemID
//Goals: Get the value for the item subtotal of the product in the cart
//Input: none
//Output: int
int Item::GetSubtotal(){
    return Item::subtotal;

}//End GetSubtotal method