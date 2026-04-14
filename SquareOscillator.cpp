#include "SquareOscillator.h"

float SquareOscillator::getNextSample() {
    float sample = (phase < 0.5f) ? 1.0f : -1.0f;
    phase += frequency / sampleRate;
    if (phase >= 1.0f)
        phase -= 1.0f;
    return sample;
}