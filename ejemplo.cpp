#include<iostream>
int main(){
    int x,y;
    int aux;
    float height = 1.6;
    double pi = 3.1416;
    char character = 'a';
    bool isStudent = true;
    
    std :: cin >> x  >>y;
    aux = x;
    y = aux;
    std :: cout << x << y;
    //print initialed variables
    /* 
    multi
    line
    comment 
    */
    std :: cout << "height:\t" << height << std :: endl;
    std :: cout << "pi:\t" << pi << std :: endl;
    std :: cout << "character:\t" << character << std :: endl;
    std :: cout << "isStudent:\t" << isStudent << std :: endl;
   }