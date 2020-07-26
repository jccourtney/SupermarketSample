//Class name: Checkout 
//Goals: To create a basic object to store the functionality of the checkout lane

//Include Section
#include <iostream>
#include <string>
#include <list>
#include "Checkout.h"



//Method Name: default constructor Checkout()
//Goals: Create default constructor for default values
//Input: none
//Output: none
Checkout::Checkout(){
    Checkout::price_scheme = NULL;
    
}//End default constructor


//Method Name: defined constructor Checkout()
//Goals: Create defined constructor for defined values
//Input: 
//      1. PriceScheme* new_scheme
//Output: none
Checkout::Checkout(PriceScheme* new_scheme){
    Checkout::price_scheme = new_scheme;

}//End defined constructor


//Method Name: default dconstructor ~Checkout()
//Goals: Create defined constructor for defined values
//Input: none
//Output: none
Checkout::~Checkout(){
    

}//End defined constructor



//Method Name: Scan
//Goals: Add a new item to the cart in the checkout
//Input: std::string item_id
//Output: none
void Checkout::Scan(std::string item_id){
    Checkout::cart.push_back(Item(item_id, 0));
}//End Scan method


//Method Name: Print
//Goals: Print the IDs and subtotals of the items in the cart
//Input: none
//Output: none
void Checkout::Print(){
    for(it = cart.begin(); it != cart.end(); it++){
        std::cout << it->GetItemID() << " " << it->GetSubtotal() << std::endl;
    }
}//End Print method

//Method Name: GetTotal
//Goals: Calculate the total of the items in the cart
//Input: none
//Output: none
int Checkout::GetTotal(){
    int total = 0;
    ApplySimplePrice();
    ApplyBuyXGetY();
    ApplyBundle();
    ApplyTaxes();
      
    for(it = cart.begin(); it != cart.end(); it++){
        total = total + it->GetSubtotal();
    }

    return total;
}//End GetTotal method


//Method Name: ApplySimplePrice
//Goals: Apply the simple price to each Item in the cart using the Price product parameter from the PriceScheme tree
//Input: none
//Output: none
void Checkout::ApplySimplePrice(){
    int subtotal = 0;
    Product* found_product;
    for(it = cart.begin(); it != cart.end(); it++){
        if(price_scheme != NULL){
            found_product = price_scheme->FindProductInScheme(it->GetItemID());
            if(found_product != NULL){
                subtotal = found_product->GetPrice();
                it->SetSubtotal(subtotal);
            }
            else{
                std::cout << "Found Product is NULL." << std::endl;
            }
        }
        else{
            std::cout << "price_scheme is NULL" << std::endl;
        }
    }   
}//End ApplySimplePrice() method definition


//Method Name: ApplyBuyXGetY
//Goals: Apply Buy X, Get Y deal to items in the cart
//Input: none
//Output: none
void Checkout::ApplyBuyXGetY(){
    int buy_x_count = 0;
    int get_y_count = 0;
    Product* found_product;
    for(it = cart.begin(); it != cart.end(); it++){
        if(price_scheme != NULL){
            found_product = price_scheme->FindProductInScheme(it->GetItemID());
            if(found_product != NULL && it->GetSubtotal() != 0){
                if(found_product->GetBuyX() >= 0 && found_product->GetGetY() >= 0){ //If either is equal to zero, a Buy X, Get Y deal doesn't exist
                    buy_x_count = found_product->GetBuyXCount();
                    if(buy_x_count < found_product->GetBuyX()){ //Not enough Buy X credits have been earned to get a Get Y free credit
                        found_product->SetBuyXCount(buy_x_count + 1);
                    }
                    else{
                        get_y_count = found_product->GetGetYCount();
                        if(get_y_count < found_product->GetGetY()){ //Enough Buy X credits have been earned, Check for Get Y free credits
                            it->SetSubtotal(0); //Free Get Y credit
                            found_product->SetGetYCount(get_y_count + 1);
                        }
                        else{ //Reset Buy X and Get Y counters
                            found_product->SetBuyXCount(0);
                            found_product->SetGetYCount(0);
                        }
                    }
                }
            }
        }
    } 
}//End ApplyBuyXGetY method definition


//Method Name: ApplyBundle
//Goals: Apply Bundle pricing deal to items in the cart
//Input: none
//Output: none
void Checkout::ApplyBundle(){
    int subtotal = 0;
    bool keep_going = true;
    std::string bundle_other_id = "";
    Product* found_product;
    std::list<Item>::iterator it_bundle;

    for(it = cart.begin(); it != cart.end(); it++){
        if(price_scheme != NULL){
            if(it->GetSubtotal() > 0){ //Only check for bundle deals on items have not been set to free
                found_product = price_scheme->FindProductInScheme(it->GetItemID());
                if(found_product != NULL){
                    bundle_other_id = found_product->GetBundleOther();
                    if(bundle_other_id != "0000"){ //A bundle deal exists
                        //Search through the remainder of cart to see if other bundled item exists
                        if(it != cart.end()){
                            it_bundle = it;
                            it_bundle++;

                                keep_going = true;
                                while(keep_going){
                                    if(it_bundle != cart.end()){
                                        if(it_bundle->GetItemID() == bundle_other_id && it_bundle->GetSubtotal() > 0){ //Other bundle item found
                                            it_bundle->SetSubtotal(0);
                                            it->SetSubtotal(found_product->GetBundlePrice());
                                            keep_going = false;
                                        }
                                        else{
                                            if(it_bundle != cart.end()){
                                                it_bundle++;
                                            }
                                            else{
                                                keep_going = false;
                                            }                               
                                        }
                                    }
                                    else{
                                        keep_going = false;
                                    }

                                }
                        }
                    }
                }
            }
        }
    }


}//End ApplyBundle method definition

//Method Name: ApplyBundle
//Goals: Apply Bundle pricing deal to items in the cart
//Input: none
//Output: none
void Checkout::ApplyTaxes(){
    int subtotal = 0;
    float added_tax = 0.00;
    Product* found_product;
    for(it = cart.begin(); it != cart.end(); it++){
        if(price_scheme != NULL){
            found_product = price_scheme->FindProductInScheme(it->GetItemID());
            if(found_product != NULL){
                added_tax = found_product->GetAddedTax();
                subtotal = (int) it->GetSubtotal() * (1.0 + (added_tax / 100.0));
                it->SetSubtotal(subtotal);
            }
        }
    }
}//End ApplyTaxes method definition