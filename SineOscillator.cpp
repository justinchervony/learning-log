#include "SineOscillator.h"

float SineOscillator::getNextSample() {
    float sample = std::sin(2.0f * 3.14159f * phase);
    phase += frequency / sampleRate;
    if (phase >= 1.0f)
        phase -= 1.0f;
    return sample;
}