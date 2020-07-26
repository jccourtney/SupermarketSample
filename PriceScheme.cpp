//Class name: PriceScheme 
//Goals: To create a binary search tree full of product nodes where each product can be found by Item ID


//Include Section
#include <iostream>
#include <string>
#include "PriceScheme.h"



//Method Name: default constructor PriceScheme()
//Goals: Create default constructor for default values
//Input: none
//Output: none
PriceScheme::PriceScheme(){
    PriceScheme::head_node = NULL;
}//End default constructor


//Method Name: default dconstructor PriceScheme()
//Goals: Create default deconstructor
//Input: none  
//Output: none
PriceScheme::~PriceScheme(){
    if(PriceScheme::head_node != NULL){
        DeleteNode(PriceScheme::head_node);
    }

}//End default deconstructor

//Method Name: DeleteNode
//Goals: To delete each Product Node of the PriceScheme tree, starting with the leaf nodes
//Input: Product* current_node
//Output: none
void PriceScheme::DeleteNode(Product* current_node){
    if(current_node != NULL){
        //Check to see if left child is not NULL
        //If not NULL, call function again on Left Child.
        if(current_node->GetChildLeft() != NULL){
            DeleteNode(current_node->GetChildLeft());
        }

        //Check to see if right child is not NULL.
        //If not NULL, call function again on Right Child.
        if(current_node->GetChildRight() != NULL){
            DeleteNode(current_node->GetChildRight());
        }
        delete current_node;
    }
    else{
        std::cout << "Current Node is NULL." << std::endl;
    }

}//End DeleteNode method definition

//Method Name: AddProductToScheme
//Goals: To add a new product node to the correct lexographical spot by storing the Product nodes in acsending order
//Input: 
//      1. Product* new_product
//Output: none
void PriceScheme::AddProductToScheme(Product* new_product){
    if(PriceScheme::head_node == NULL){ //Head node of Price Scheme tree is empty
        PriceScheme::head_node = new_product;

    }
    else{ //Head Node is already defined, so add new word to child element
        AddProduct(new_product, PriceScheme::head_node);
    }
}//End AddProductToScheme method definition


//Method Name: AddProduct
//Goals: To add the Word to the correct lexographic spot by storing the WordNodes in acsending order
//Input: 
//      1. Product* new_product: new Product node to add to PriceScheme tree
//      2. Product* root_node: The current parent node
//Output: none
void PriceScheme::AddProduct(Product* new_product, Product* root_node){
    if(new_product != NULL){ //New Product node exists.
        if(root_node != NULL){ //Root node exists. So see if item_ID is greater than, equal to, or less than item_id of root_node
            std::string compare_new_ID = new_product->GetItemID();
            std::string compare_root_ID = root_node->GetItemID();
            int compare_value = compare_new_ID.compare(compare_root_ID.c_str());

            if(compare_value == 0){ //New Product to add is the same as Product stored in parent node
                std::cout << "Item ID: " << compare_new_ID << " is a duplicate. Ignoring." << std::endl;
            }
            else if(compare_value < 0){ //Add Product to Left Child Node
                if(root_node->GetChildLeft() != NULL){
                    AddProduct(new_product, root_node->GetChildLeft());
                }
                else{ //Add the Product node to root_node->child_left
                    root_node->SetChildLeft(new_product);
                    new_product->SetParent(root_node);
                }
            }
            else{ //Add Product Node to Right Child Node
                if(root_node->GetChildRight() != NULL){
                    AddProduct(new_product, root_node->GetChildRight());
                }
                else{ //Add the Product node to root_node->child_right
                    root_node->SetChildRight(new_product);
                    new_product->SetParent(root_node);
                }
            }
        }
        else{
            std::cout << "Error: Root Node is NULL. Product ID: " << new_product->GetItemID() << std::endl;
        }
    }
    else{
        std::cout << "Error: New Product is NULL." << std::endl;
    }
}


//Method Name: FindProductInScheme
//Goals: To retrieve the Product node by item_id from the PriceScheme tree
//Input: std::string item_id
//Output: Product* found_product
Product* PriceScheme::FindProductInScheme(std::string item_id){
    Product* found_product = NULL;
    if(PriceScheme::head_node != NULL){ //PriceScheme tree is not empty
        if(PriceScheme::head_node->GetItemID() == item_id){ //ItemID of head_node matches supplied Item ID
            found_product = PriceScheme::head_node;
        }
        else{
            found_product = FindProductFromNode(item_id, head_node);
        }
    }
    else{ //PriceScheme tree is empty
        found_product = NULL;
        std::cout << "Could not find Item ID: " << item_id << " in PriceScheme tree, as tree is empty." << std::endl;
    }
    return found_product;
}


//Method Name: FindProductFromNode
//Goals: To retrieve the Product node by item_id from a given Product node in the PriceScheme tree
//Input: 1. std::string item_id
//       2. Product* root_node
//Output: Product* found_product
Product* PriceScheme::FindProductFromNode(std::string item_id, Product* root_node){
    Product* found_product = NULL;
    Product* left_child = NULL;
    Product* right_child = NULL;

    if(root_node != NULL){ //Root node exists. So see if supplied item_ID is greater than, equal to, or less than item_id of root_node
        std::string compare_find_ID = item_id;
        std::string compare_root_ID = root_node->GetItemID();
        int compare_value = compare_find_ID.compare(compare_root_ID.c_str());

        if(compare_value < 0){ //Supplied Item ID is less than Item ID of root node, so check left child
            left_child = root_node->GetChildLeft();
            if(left_child != NULL){
                //Check if Item ID of left child matches supplied Item ID
                if(left_child->GetItemID() == item_id){
                    found_product = left_child;
                }
                else{
                    found_product = FindProductFromNode(item_id, left_child); //Continue searching for a match through the next node(s)
                }
            }
            else{ //As left child is NULL, product is not located in PriceScheme tree, so set found_product to NULL
                found_product = NULL;
                std::cout << "Item ID: " << item_id << " is NOT located in PriceScheme tree (Left Child)." << std::endl;
            }
        }
        else{ //Add Product Node to Right Child Node
            right_child = root_node->GetChildRight();
            if(right_child != NULL){
                //Check if Item ID of right child matches supplied Item ID
                if(right_child->GetItemID() == item_id){
                    found_product = right_child;
                }
                else{
                    found_product = FindProductFromNode(item_id, right_child); //Continue searching for a match through the next node(s)
                }
            }
            else{ //As right child is NULL, product is not located in PriceScheme tree, so set found_product to NULL
                found_product = NULL;
                std::cout << "Item ID: " << item_id << " is NOT located in PriceScheme tree (Right Child)." << std::endl;
            }
        }
    }
    else{
        std::cout << "Error: Root Node is NULL. Product ID: " << item_id << std::endl;
    }
    return found_product;
}



//Method Name: PrintScheme
//Goals: To print the PriceScheme tree in ascending order
//Input: None
//Output: None
void PriceScheme::PrintScheme(){
    if(PriceScheme::head_node != NULL){
        PrintProduct(PriceScheme::head_node);
    }
    else
    {
        std::cout << "PriceScheme tree is empty." << std::endl;
    }
    
    
}//End PrintScheme method definition


//Method Name: PrintProduct
//Goals: To print the tree in ascending order
//Input: Product* current_node: current node to print
//Output: None
void PriceScheme::PrintProduct(Product* current_node){
    if(current_node != NULL){
        //Check to see if left child is not NULL
        //If not NULL, call function again on Left Child.
        if(current_node->GetChildLeft() != NULL){
            PrintProduct(current_node->GetChildLeft());
        }

        //Print current value of current node
        current_node->Print();

        //Check to see if right child is not NULL.
        //If not NULL, call function again on Right Child.
        if(current_node->GetChildRight() != NULL){
            PrintProduct(current_node->GetChildRight());
        }
    }
    else{
        std::cout << "Current Node is NULL." << std::endl;
    }

}//End PrintProduct method definition

