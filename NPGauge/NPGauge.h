#pragma once

#include "Arduino.h"

class NPGauge
{
public:
    NPGauge(uint8_t Pin1, uint8_t Pin2);
    void begin();
    void attach(uint16_t Pin3, char *init);
    void detach();
    void set(int16_t messageID, char *setPoint);
    void update();

private:
    bool    _initialised;
    uint8_t _pin1, _pin2, _pin3;

// Function declarations
float scaleValue(float x, float in_min, float in_max, float out_min, float out_max);
void  setInstrumentBrightnessRatio(float ratio);
void  setRPM(float value);
void  setPowerSave(bool enabled);
void  drawGauge();
};