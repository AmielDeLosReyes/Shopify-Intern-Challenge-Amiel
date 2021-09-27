
// Shopify Intern Challenge for Amiel De Los Reyes
// Email: amielxvr@gmail.com
// Phone number: +1 306-201-5554


#include <iostream>
#include <string>
using namespace std;

// create a struct for Shopify Images
struct Images
{
    // work variable
public:
    string imageChar;
    string text;
    string image;
    double price;
    double discount;
    
    // no-arg constructor
    Images()
    {
        imageChar =" ";
        text = " ";
        image = " ";
        price = 0.0;
        discount = 0.0;
    }
    
    // parameterized constructor
    Images(string ImageChar, string Text, string Image, double Price, double Discount)
    {
        imageChar = ImageChar;
        text = Text;
        image = Image;
        price = Price;
        discount = Discount;
    }
   
};

// create a class node that has the data of the Shopify Image and a pointer to point to the next item
class Node
{
public:
    // node pointer
    Node* pNext;
    // create an instance of the struct Images to access its data
    Images datum;
    
    
    // no-arg constructor
    Node()
    {
        datum.imageChar = " ";
        datum.text = " ";
        datum.image = " ";
        pNext = NULL;
    }
    
    // parameterized constructor that contains the data of a single node
    Node(Images Datum, Node* node)
    {
        datum = Datum;
        pNext = node;
    }
};

// start of class linked list
class LinkedList
{
private:
    Node* pHead;
    
public:
    // no-arge constructor
    LinkedList()
    {
        pHead = NULL;
    }
    
    // parameterized constructor
    LinkedList(Node* link)
    {
        pHead = link;
    }
    
    // function to search the linked list
    Node* searchLinkedList(Node* pHead, string x)
    {
        // initialize pointers with appropriate value
        Node* pPrevious = NULL;
        Node* pCurrent = pHead;
        
        // while we are not on the last item on the list and the data image is in ascending order
        while(pCurrent != NULL && pCurrent -> datum.image < x)
        {
            pPrevious = pCurrent;
            pCurrent = pCurrent -> pNext;
        }
        
        // return the datum that was searched
        return pPrevious;
    }
    
    // function to insert an image inside the Shopify list
    void addImages(Images student)
    {
        Node* pPrevious = searchLinkedList(pHead, student.image);
        
        Node* pCurrent = new Node;
        pCurrent -> datum = student;
        
        if(pPrevious == NULL)
        {
            pCurrent -> pNext = pHead;
            pHead = pCurrent;
        }
        
        else
        {
            pCurrent -> pNext = pPrevious -> pNext;
            pPrevious -> pNext = pCurrent;
        }
    }
    
    // function to remove images in the linked list
    void deleteImages(Images images)
    {
        Node* pPrevious = searchLinkedList(pHead, images.image);
        
        // if we are not on the last item on the list
        if(pPrevious != NULL)
        {
            pPrevious -> pNext -> datum.image = images.image;
            
            Node* pToRemove = pPrevious -> pNext;
            pPrevious -> pNext = pToRemove -> pNext;
            delete pToRemove;
        }
        
        else
        {
            if(pHead == NULL || pHead -> datum.image != images.image)
            {
                Node* pToRemove = pHead;
                pHead = pToRemove -> pNext;
                delete pToRemove;
            }
            
        }
    }
    
    // function to sell images
    void sellImages(Images images) {
        
        // look for the image then delete it after selling
        Node* pPrevious = searchLinkedList(pHead, images.image);
        deleteImages(images);
    }
    
    // function to buy images
    void buyImages(Images images) {
        
        // look for the images to buy then buy it
        Node* pPrevious = searchLinkedList(pHead, images.image);
        
    }
    
    // function to set price
    void setPrice(Images images) {
        
        // look for the image then set the price of it
        double _price;
        Node* pPrevious = searchLinkedList(pHead, images.image);
        images.price = _price;
    }
    
    // function to give discounts
    void discounts(Images images) {
        // look for the image then set the price of it, 25% discount for now
        double discountPrice;
        Node* pPrevious = searchLinkedList(pHead, images.image);
        discountPrice = images.price * 0.25;
    }
 
}; // end of class Sorted Linked List


// start of the main function
int main()
{
    
    
    return 0;
} // end of program
