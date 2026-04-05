#include <iostream>

int main() {
    int x = 5; // Copy-initialization
    int y(5); // Direct-initialization
    int z{5}; // List-initialization (also called uniform initialization)

    /* 
        Copy-initialization is not as efficient as the other 2.
        
        Direct-initialization is less efficient than list-initializaiton, 
        and is only really used when values are going to be cast to 
        another type.

        List-initialization is most efficient and helps identifiy 
        spaces where objects are initialized. Also allows for multiple vals
        to be assigned to an object, however it doesn't allow for narrowing
        conversions (aka setting int x = 2.4 which would normally just set
        x = 2 but with list-initialization would cause a compile error)



        if we don't use x, y, or z, or aren't sure if we will use them we
        can preceed them with [[maybe_unused]] to prevent compiler warnings


        in order to print to a new line use '\n' (faster than std::endl)
    */


    int a {};
    std::cout << "Enter a number: ";
    std::cin >> a;
    std::cout << "You wrote: " << a << '\n';

    return 0;
}