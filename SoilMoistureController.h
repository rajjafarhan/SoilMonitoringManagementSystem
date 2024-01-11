#pragma once

#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

using namespace std;

enum class Signal {
    INCREASE,
    DECREASE,
    MAINTAIN
};

string signalToString(Signal signal);

// SoilMoistureController class definition
class SoilMoistureController {
private:
    optional<double> actualMoisture;
    optional<double> desiredMoisture;

    const double MIN_MOISTURE = 20.0;
    const double MAX_MOISTURE = 60.0;

    bool inRange(double ml);

    // Function to check the precondition and throw an error if out of range
    void checkPrecondition(double ml, const string& operation);

public:
    SoilMoistureController();

    void SetInitialMoisture(double ml);

    Signal RequestMoistureChange();

    void SetDesiredMoisture(double ml);

    Signal IncrementMoisture();

    Signal DecrementMoisture();

    optional<double> GetActualMoisture();

    optional<double> GetDesiredMoisture();
};
