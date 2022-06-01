#include <iostream>
#include <fstream>
#include <string>

void arrInit(int* arrTask1, const unsigned int iSize);
void arrPrint(int* arrTask1, const unsigned int iSize);
void RandFill(int** arrTask2, const unsigned int iXSize, const unsigned int iYSize);
void RandPrint(int** arrTask2, const unsigned int iXSize, const unsigned int iYSize);

int main()
{
    // Task #1
    int iSize = 0, *arrTask1;
 m0:   std::cout << "Task #1:\nPlease enter array size: ";
    std::cin >> iSize;
    if (iSize > 31) {
        std::cout << "Too big number!\n";
        goto m0;
    }
    else if (iSize < 1) {
        std::cout << "The number have to be >= 1\n";
        goto m0;
        }
    arrTask1 = new int[iSize];
    arrInit(arrTask1, iSize);
    arrPrint(arrTask1, iSize);
    delete arrTask1;
    std::cout << "\n";

    //Task #2
    std::cout << "\nTask #2:\n";
    const unsigned int DIM1 = 4;
    const unsigned int DIM2 = 4;
    int** pX;
    pX = new int* [DIM1];
    for (int i = 0; i < DIM1; i++) {
        pX[i] = new int[DIM2];
    }
    RandFill(pX, DIM1, DIM2);
    RandPrint(pX, DIM1, DIM2);

    // Task #3
    std::string strFile1, strFile2, strFile3;
    std::cout << "\nTask #3:\nPlease enter name for first file: ";
    std::cin >> strFile1;
    std::cout << "Please enter name for second file: ";
    std::cin >> strFile2;
    std::ofstream fFile1, fFile2;
    fFile1.open(strFile1, std::ios::out | std::ios::binary);
    fFile2.open(strFile2, std::ios::out | std::ios::binary);
    for (size_t i = 0; i < 60; i++)
    {
        fFile1.put(48 + i);
        fFile2 << (99 - i);
    }
    fFile1.close();
    fFile2.close();

    //Task #4
    std::ifstream fFile3, fFile4;
    std::ofstream fFile5;
    std::cout << "Please enter file name for union: ";
    std::cin >> strFile3;
    fFile3.open(strFile1, std::ios::in | std::ios::binary);
    fFile4.open(strFile2, std::ios::in | std::ios::binary);
    fFile5.open(strFile3, std::ios::out | std::ios::binary);
    if (fFile3.is_open())
    {
        char byte;
        while (1) {
            fFile3.get(byte);
            if (fFile3.eof()) break;
            fFile5.put(byte);
            std::cout << byte;
        }
        std::cout << std::endl;
        fFile3.close();
    }
    if (fFile4.is_open())
    {
        char byte;
        while (1) {
            fFile4.get(byte);
            if (fFile4.eof()) break;
            fFile5.put(byte);
            std::cout << byte;
        }
        std::cout << std::endl;
        fFile4.close();
    }
    fFile5.close();
}

//// Task #1 functions
void arrInit(int * arrTask1, const unsigned int iSize) {
    arrTask1[0] = 1;
    for (size_t i = 1; i < iSize; i++)
    {
        arrTask1[i] = arrTask1[i - 1] * 2;
    }
    return;
}

void arrPrint(int* arrTask1, const unsigned int iSize) {
    for (size_t i = 0; i < iSize; i++)
    {
        std::cout << arrTask1[i] << ' ';
    }
    return;
}

//// Task #2 functions
void RandFill(int** arrTask2, const unsigned int iXSize, const unsigned int iYSize) {
    for (int i = 0; i < iXSize; i++) {
        for (int j = 0; j < iYSize; j++) {
            arrTask2[i][j] = rand();
        }
    }
    return;
}

void RandPrint(int** arrTask2, unsigned const int iXSize, unsigned const int iYSize) {
    for (int i = 0; i < iXSize; i++) {
        for (int j = 0; j < iYSize; j++) {
            std::cout << arrTask2[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return;
}
