#pragma once
#include <cmath>

class Oscillator {
    public:
        void setFrequency(float freq) {frequency = freq;}
        void setSampleRate(float sr) {sampleRate = sr;}
        void reset() {phase = 0.0f;}

        virtual float getNextSample() = 0;

    protected:
        float frequency = 0.0f;
        float sampleRate = 44100.0f;
        float phase = 0.0f;
};