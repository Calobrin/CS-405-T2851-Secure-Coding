// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Create a custom exception so I can create my own custom message by the return value.
// http://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners/
struct customException : public std::exception {
    const char* what() const throw() {
        return "The Custom Exception throw has occured";
    }
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception

    //Simply threw the standard exception
    throw std::exception();

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    // Implement a try catch block here.
    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    // Catch handles the exception, and uses the exception.what()
    catch (const std::exception& exception) {
        std::cerr << "The 'do_custom_application_logic' method threw an exception: " << exception.what() << std::endl;
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    throw customException();
    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    //If the 'float den' parameter passed into this method happens to be zero, it will throw an exception. (you cannot divide by 0)
    // https://www.geeksforgeeks.org/handling-the-divide-by-zero-exception-in-c/
    if (den == 0) {
        throw std::runtime_error("Error: Attempted to divide by zero");
    }

    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    //Implement a try catch block here
    try {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    // Catch handles the exception
    catch (const std::exception& exception) {
        std::cerr << "The 'do_division' method threw an exception: " << exception.what() << std::endl;
    }
}

int main()
{
    // Implements a try catch (multi catch) block for the following
    try {
        std::cout << "Exceptions Tests!" << std::endl;

        // TODO: Create exception handlers that catch (in this order):
        //  your custom exception
        //  std::exception
        //  uncaught exception 
        //  that wraps the whole main function, and displays a message to the console.
        do_division();
        do_custom_application_logic();
    }
    // Implementing a catch using my customException created at the top
    catch (const customException& exception) {
        std::cerr << "From 'main': Custom exception has been thrown: " << exception.what() << std::endl;
    }
    // Implementing a catch using the standard exception
    catch (const std::exception& exception) {
        std::cerr << "From 'main': Standard exception has been thrown: " << exception.what() << std::endl;
    }
    // Implementing a catch to handle any potential exception
    // https://www.w3schools.com/cpp/cpp_exceptions.asp
    catch (...) {
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu