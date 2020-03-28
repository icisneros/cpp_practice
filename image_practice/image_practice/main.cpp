//
//  main.cpp
//  image_practice
//
//  Created by Ivan Alexis Cisneros on 3/9/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdint.h>

using std::cout;
using std::endl;
using std::vector;

vector<vector<uint8_t>> create_image(int size){
    // Creates a square image of sizexsize
    // Init value of 0
    vector<vector<uint8_t>> image;
    
    for(int i = 0; i < size; i++){
        vector<uint8_t> row;
        row.resize(size, 0); // initialize to 0s
        image.push_back(row);
    }
    return image;
}

void print_image(vector<vector<uint8_t>> image){
    cout << "\nThe image:" << endl;
    int size = (int) image.size();
    for(int i = 0; i < size; i++){
        cout << "[ ";
        for(int j = 0; j < size; j++){
            cout << (int) image[i][j] << " ";
        }
        cout << "] " << endl;
    }
    cout << endl;
}

void add_noise(vector<vector<uint8_t>> &image){
    // White noise generator
    int size = (int) image.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            image[i][j] = rand() % 255;
        }
    }
}

void contrast(vector<vector<uint8_t>> &image, uint8_t level){
    uint8_t low_range = 0 + level;
    uint8_t high_range = 255 - level;
    
    int size = (int) image.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            uint8_t pixel = image[i][j];
            if (pixel <= low_range){
                image[i][j] = 0;
            }
            else if (pixel >= high_range){
                image[i][j] = 255;
            }
        }
    }
}


int main() {
    
    vector<vector<uint8_t>> image = create_image(10);
    print_image(image);
    add_noise(image);
    cout << "Adding noise..." << endl;
    print_image(image);
    contrast(image, 10);
    cout << "Increasing contrast..." << endl;
    print_image(image);

    return 0;
}
