#include <iostream>

int main(){
    std::string name = "/home/diversario/Dropbox/Documents/Projects/C++/Exercises/9.14/Money.h";
    ifstream ifs(name.c_str());
    std::cout << ifs;
    return 0;
}
