#include <iostream>
#include <cmath>

float midiToFrequency (int midiNote){
    return 440.0f * std::pow(2.0f, (midiNote - 69) / 12.0f);
}

int main () {
    int sampleRate = 44100;
    float frequency = 440.0;
    bool isPlaying = true;
    float freq = midiToFrequency(69);

    std::cout << sampleRate << std::endl;
    std::cout << frequency << std::endl;
    std::cout << isPlaying << std::endl;
    std::cout << freq << std::endl;

    return 0;
}