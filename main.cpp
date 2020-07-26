//Name: John Courtney
//Date: 7/14/2020
//Software Engineer I interview for Anthem Engineering.
//Supermarket Exercise

//Include Section
#include <cassert>
#include <string>
#include <list>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>
#include <fstream>
#include "Checkout.h"
#include "Product.h"
#include "PriceScheme.h"

//Function Declaration Section
void BuildPriceScheme(std::string filename, PriceScheme* price_scheme);

//Global Variables


//Main Loop
int main(){
    //Local Declarations
    int cents = 0;

    PriceScheme* todays_scheme = new PriceScheme();



    //Executable Statements
    BuildPriceScheme("input.txt", todays_scheme);
    
    Checkout checkout = Checkout(todays_scheme);
    checkout.Scan("1983"); //toothbrush
    checkout.Scan("4900"); //salsa
    checkout.Scan("8873"); //milk
    checkout.Scan("6732"); //chips
    checkout.Scan("0923"); //wine  
    checkout.Scan("1983"); //toothbrush
    checkout.Scan("1983"); //toothbrush
    checkout.Scan("1983"); //toothbrush
 
    
    cents = checkout.GetTotal();
    assert (3037 == cents);

    delete todays_scheme;


}//End Main



void BuildPriceScheme(std::string filename, PriceScheme* price_scheme){
    //Local Declarations
    std::ifstream in_file;
    int line_number = 0;
    
    int i; //Counter to keep track of where along a line we are currently at
    int param_start = 0;
    int param_end = 0;
    int param_count = 0;

    std::string param_item_id = "0000"; //ItemID
    int param_price = 0; //Price
    int param_buy_x = 0; //Buy X
    int param_get_y = 0; //Get Y
    int param_buy_x_count = 0; //Buy X Count
    int param_get_y_count = 0; //Buy Y Count
    float param_added_tax = 0.00; //Added Tax
    std::string param_bundle_other = "0000"; //Bundle Other
    int param_bundle_price = 0; //Bundle Price

    std::string line_string = "";
    std::string found_param = "";
    bool keep_going = true;
    bool first_char_found = false;
    bool second_char_found = false;

    in_file.open(filename);


    //Find first character to start a new word
    while(getline(in_file, line_string)){
        i = 0;
        param_count = 0;
        keep_going = true;
        line_number = line_number + 1;
        while(keep_going){
            if(first_char_found != true && 
            line_string.at(i) != ' ' &&
            line_string.at(i) != ',' 
            ){
                param_start = i;
                first_char_found = true;
            }
            else if(first_char_found == true &&
            (line_string.at(i) == ' ' || line_string.at(i) == ',')
            ){
                param_end = i;
                second_char_found = true;

            }
            //If both first and second characters of a parameter are found, save to a substring
            if(first_char_found == true && second_char_found == true){
                found_param = line_string.substr(param_start, param_end - param_start);
                param_count++;
                if(param_count == 1){ //Item ID (string)
                    param_item_id = found_param;
                }
                else if(param_count == 2){ //Price (int)
                    param_price = std::stoi(found_param);
                }
                else if(param_count == 3){ //Buy X
                    param_buy_x = std::stoi(found_param);
                }
                else if(param_count == 4){ //Get Y
                    param_get_y = std::stoi(found_param);
                }
                else if(param_count == 5){ //Buy X Count
                    param_buy_x_count = std::stoi(found_param);
                }
                else if(param_count == 6){ //Get Y Count
                    param_get_y_count = std::stoi(found_param);
                }
                else if(param_count == 7){ //Added Tax
                    param_added_tax = std::stof(found_param);
                }
                else if(param_count == 8){
                    param_bundle_other = found_param;
                                     
                }                                 
                else if(param_count == 9){
                    param_bundle_price = std::stoi(found_param); 
                    
                    //Create new product node, fill in parameter info, and add to PriceScheme
                    Product* new_product = new Product();
                    new_product->SetItemID(param_item_id);
                    new_product->SetPrice(param_price);
                    new_product->SetBuyX(param_buy_x);
                    new_product->SetGetY(param_get_y);
                    new_product->SetBuyXCount(param_buy_x_count);
                    new_product->SetGetYCount(param_get_y_count);
                    new_product->SetAddedTax(param_added_tax);
                    new_product->SetBundleOther(param_bundle_other);
                    new_product->SetBundlePrice(param_bundle_price);
                    price_scheme->AddProductToScheme(new_product);
                    
                    //Reset parameter count
                    keep_going = false;

                    param_item_id = "0000"; //ItemID
                    param_price = 0; //Price
                    param_buy_x = 0; //Buy X
                    param_get_y = 0; //Get Y
                    param_buy_x_count = 0; //Buy X Count
                    param_get_y_count = 0; //Buy Y Count
                    param_added_tax = 0.00; //Added Tax
                    param_bundle_other = "0000"; //Bundle Other
                    param_bundle_price = 0; //Bundle Price
                } 
                                    
                //reset the boolean flags for first and second characters of a word so a new word can be found
                first_char_found = false;
                second_char_found = false;
            }

            i++;
            if(i > (line_string.size() - 1)){
                keep_going = false;
                first_char_found = false;
                second_char_found = false;
            }
        }
    }

}