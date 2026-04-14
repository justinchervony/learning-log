#pragma once
#include "Oscillator.h"

class SineOscillator : public Oscillator {
    public:
        float getNextSample() override;
};