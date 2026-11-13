#include "Matrix.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Matrix m1;       
    Matrix m2(3);     
    Matrix m3(3, 4);  
    Matrix m4(2, 3);  
    std::cout << "m1 size: " << m1.getRows() << "x" << m1.getCols() << "\n\n";
    std::cout << "m2 (identity 3x3):\n";
    m2.print();
    std::cout << "\nm3 (3x4, zeros):\n";
    m3.print();
    std::cout << "\nm4 (2x3, zeros):\n";
    m4.print();

    for (int i = 0; i < m2.getRows(); ++i) {
        for (int j = 0; j < m2.getCols(); ++j) {
            m2.set(i, j, i * j);
        }
    }

    std::cout << "\nm2 after filling by formula i * j:\n";
    m2.print();
    m3.fillRandom();

    std::cout << "\nm3 after fillRandom():\n";
    m3.print();
    Matrix mm = m3;
    std::cout << "\nmm = m3 (shallow copy demonstration):\n";
    mm.print();

    std::cout << "\nEnter " << m4.getRows() * m4.getCols()
              << " integers for m4 (2x3):\n";
    m4.inputFromKeyboard();

    std::cout << "\nm4 after inputFromKeyboard():\n";
    m4.print();

    std::cout << "\nSum of m3 = " << m3.sum() << '\n';

    Matrix transposed = m3.transpose();
    std::cout << "\nm3 transposed (4x3):\n";
    transposed.print();

    try {
        Matrix bad(-1, 5);
    } catch (const std::invalid_argument& e) {
        std::cout << "\nCaught invalid_argument: " << e.what() << '\n';
    }

    try {
        m3.get(100, 100);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range: " << e.what() << '\n';
    }

    std::cout << "\nEnd of main. Now the matrix destructors will run.\n";
    std::cout.flush();

    return 0;
}
