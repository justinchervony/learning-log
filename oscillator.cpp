#include "Oscillator.h"

Oscillator::Oscillator() {
    frequency = 0.0f;
    sampleRate = 44100.0f;
    phase = 0.0f;
}

void Oscillator::setFrequency(float freq) {
    frequency = freq;
}

void Oscillator::setSampleRate(float sr) {
    sampleRate = sr;
}

void Oscillator::reset() {
    phase = 0.0f;
}

float Oscillator::getNextSample() {
    float sample = std::sin(2.0f * 3.14159f * phase);
    phase += frequency / sampleRate;
    if (phase >= 1.0f)
        phase -= 1.0f;
    return sample;
}