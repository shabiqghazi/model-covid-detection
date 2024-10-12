#include <iostream>
#include <fstream>
#ifndef INPUT_H
#define INPUT_H

#define SAMPLE_MAX 48000
#define DIMENSION 1
double series[DIMENSION][SAMPLE_MAX];

void get_data(std::string filename) {
    std::cout << filename + ',';
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Gagal membuka file!" << std::endl;
    }
    int index = 0;
    double value;
    while (file >> value && index < SAMPLE_MAX) {
        series[0][index] = value;  // Menyimpan nilai ke dalam array
        index++;
    }

    file.close();  // Menutup file setelah selesai membaca

}

#endif // INPUT_H
