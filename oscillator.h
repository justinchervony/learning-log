#pragma once
#include <cmath>

class Oscillator {
    public:
        Oscillator();

        void setFrequency(float freq);
        void setSampleRate(float sr);
        void reset();
        float getNextSample();

    private:
        float frequency = 0.0f;
        float sampleRate = 44100.0f;
        float phase = 0.0f;
};