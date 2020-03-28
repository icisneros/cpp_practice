//
//  main.cpp
//  hashmaps_practice
//
//  Created by Ivan Alexis Cisneros on 2/4/20.
//  Copyright © 2020 Ivan Alexis Cisneros. All rights reserved.
//

#include <iostream>
#include <unordered_map>

int main() {
    // declare the map <key type, value type>
    std::unordered_map<std::string, double> mymap;
    
    // add key value pairs to the map
    mymap["PI"] = 3.141;
    mymap["root2"] = 1.414;
    mymap["testval"] = 1.0;
    
    // to increment a value (e.g. for tracking unique keys)
    mymap["testval"] = mymap["testval"] + 1.0;
    
    // can also add key value pairs this way
    mymap.insert(std::make_pair("e", 2.718));
    
    
    // check whether a key value pair is already in the map
    if(mymap.find("LAMBDA") == mymap.end()){
        // if it's not there, add it to the map
        mymap["LAMBDA"] = 1.111;
    }
    
    // iterate over the map
    for(auto itr = mymap.begin(); itr != mymap.end(); itr++)
    {
        std::cout << "Key: " << itr->first << " Value: " << itr->second << "\n";
    }
    
    
    
    return 0;
}
