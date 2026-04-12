#include <iostream>
#include <cmath>
#include <string>
#include <vector>

float midiToFrequency (int midiNote){
    return 440.0f * std::pow(2.0f, (midiNote - 69) / 12.0f);
}

std::string noteName(int midiNote){
    if (midiNote < 0 || midiNote > 127){
        return "invalid";
    }
    else if (midiNote == 69) {
        return "A4";
    }
    else {
        return "other";
    }
}

std::vector<float> generateSineWave(float frequency, float sampleRate, int numSamples) {
    std::vector<float> buffer;

    for (int i =0; i < numSamples; i++) {
        float time = i / sampleRate;
        float sample = std::sin(2.0f * 3.14159f * frequency * time);
        buffer.push_back(sample);
    }

    return buffer;
}

void applyGain(std::vector<float>& buffer, float gain) {
    for (int i = 0; i < buffer.size(); i++) {
        buffer[i] *= gain;
    }
}

int main () {
    int sampleRate = 44100;
    float frequency = 440.0;
    bool isPlaying = true;
    float freq = midiToFrequency(69);
    std::vector<float> sineBuffer = generateSineWave(440.0f, 44100.0f, 44100);

    std::cout << sampleRate << std::endl;
    std::cout << frequency << std::endl;
    std::cout << isPlaying << std::endl;
    std::cout << freq << std::endl;
    std::cout << noteName(69) << std::endl;
    std::cout << noteName(200) << std::endl;

    for (int i = 0; i < 4; i++){
        std::cout << "beat " << i << std::endl;
    }

    std::cout << "Buffer size: " << sineBuffer.size() << std::endl;
    std::cout << "First sample " << sineBuffer[0] << std::endl;
    std::cout << "Mid sample " << sineBuffer[22049] << std::endl;

    std::cout << "Before gain: " << sineBuffer[1] << std::endl;
    applyGain(sineBuffer, 0.5f);
    std::cout << "After gain: " << sineBuffer[1] << std::endl;

    return 0;
}