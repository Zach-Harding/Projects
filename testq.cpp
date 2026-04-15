#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>

int absolute_value(int x) {
    if (x > 0) return x;
    return -x;
    
}


int main() {
    int x = -10;
    std::cout << "the absolute value of " << x << " is: " << absolute_value(x) << "\n";
    return 0;


}
