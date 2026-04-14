#pragma once
#include "Oscillator.h"

class SquareOscillator : public Oscillator {
    public:
        float getNextSample() override;
};