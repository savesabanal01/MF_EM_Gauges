#pragma once

#include <Arduino.h>
#include "FFGauge/FFGauge.h"
#include "FuelGauge/FuelGauge.h"
#include "OTOPGauge/OTOPGauge.h"
#include "NPGauge/NPGauge.h"
#pragma once


// only one entry required if you have only one custom device
enum {
    NP_GAUGE = 1,
    FF_GAUGE,
    FUEL_GAUGE,
    OTOP_GAUGE
};
class MFCustomDevice
{
public:
    MFCustomDevice();
    void attach(uint16_t adrPin, uint16_t adrType, uint16_t adrConfig, bool configFromFlash = false);
    void detach();
    void update();
    void set(int16_t messageID, char *setPoint);

private:
    bool           getStringFromMem(uint16_t addreeprom, char *buffer, bool configFromFlash);
    bool           _initialized = false;
    NPGauge         *_myNPGauge;
    FFGauge         *_myFFGauge;
    FuelGauge       *_myFuelGauge;
    OTOPGauge       *_myOTOPGauge;
    uint8_t        _pin1, _pin2, _pin3;
    uint8_t        _customType = 0;
};