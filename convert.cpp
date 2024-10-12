#include <iostream>
#include <sndfile.h>
#include <vector>

#define SAMPLE_MAX 48000

int main() {
    const char *filename = "0052ea2e-021b-4442-a86d-8b5f70a0db97.wav";  // Ganti dengan path file suara Anda
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(filename, SFM_READ, &sfinfo);
    
    if (!infile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    // Allocate space for the samples
    std::vector<double> samples(sfinfo.frames * sfinfo.channels);

    // Read the samples
    sf_count_t num_samples_read = sf_read_double(infile, &samples[0], samples.size());

    if (num_samples_read != sfinfo.frames * sfinfo.channels) {
        std::cerr << "Error reading samples from file." << std::endl;
        sf_close(infile);
        return 1;
    }

    // Close the file
    sf_close(infile);

    // Convert samples to your array format (if necessary)
    double series[SAMPLE_MAX];
    for (int i = 0; i < SAMPLE_MAX && i < num_samples_read; ++i) {
        series[i] = samples[i];
    }

    // You can now process the 'series' array as needed
    for (int i = 0; i < SAMPLE_MAX; ++i) {
        std::cout << "Sample[" << i << "] = " << series[i] << std::endl;
    }

    return 0;
}
