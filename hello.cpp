#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "SineOscillator.h"
#include "SquareOscillator.h"
#include <fstream>

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

void writeWavFile(const std::string& filename,
                    const std::vector<float>& buffer,
                    int sampleRate) {
    std::ofstream file(filename, std::ios::binary);

    int numSamples = buffer.size();
    int byteRate = sampleRate * 2;
    int dataSize = numSamples * 2;
    int chunkSize = 36 + dataSize;

    //WAV header
    file.write("RIFF", 4);
    file.write((char*)&chunkSize, 4);
    file.write("WAVE", 4);
    file.write("fmt ", 4);

    int subchunk1Size = 16;
    short audioFormat = 1;
    short numChannels = 1;
    short bitsPerSample = 16;
    short blockAlign = 2;

    file.write((char*)&subchunk1Size, 4);
    file.write((char*)&audioFormat, 2);
    file.write((char*)&numChannels, 2);
    file.write((char*)&sampleRate, 4);
    file.write((char*)&byteRate, 4);
    file.write((char*)&blockAlign, 2);
    file.write((char*)&bitsPerSample, 2);
    file.write("data", 4);
    file.write((char*)&dataSize,4);

    //Audio data
    for (float sample : buffer) {
        short s = static_cast<short>(sample * 32767.0f);
        file.write((char*)&s, 2);
    }
}


int main () {
    const int sampleRate = 44100;
    const int numSeconds = 3;
    const int numSamples = sampleRate * numSeconds;

    SineOscillator osc;
    osc.setSampleRate(sampleRate);
    osc.setFrequency(440.0f);

    std::vector<float> buffer;
    for(int i = 0; i < numSamples; i++) {
        buffer.push_back(osc.getNextSample());
    }

    writeWavFile("output.wav", buffer, sampleRate);
    std::cout << "WAV file written." << std::endl;

    return 0;
}