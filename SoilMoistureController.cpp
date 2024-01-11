// SoilMoistureController.cpp
#include "SoilMoistureController.h"

string signalToString(Signal signal) {
    switch (signal) {
        case Signal::INCREASE: return "INCREASE";
        case Signal::DECREASE: return "DECREASE";
        case Signal::MAINTAIN: return "MAINTAIN";
        default: return "UNKNOWN";
    }
}

bool SoilMoistureController::inRange(double ml) {
    return ml >= MIN_MOISTURE && ml <= MAX_MOISTURE;
}

void SoilMoistureController::checkPrecondition(double ml, const string& operation) {
    if (!inRange(ml)) {
        throw out_of_range("Moisture level out of range for operation: " + operation);
    }
}

SoilMoistureController::SoilMoistureController() : actualMoisture(nullopt), desiredMoisture(nullopt) {}

void SoilMoistureController::SetInitialMoisture(double ml) {
    checkPrecondition(ml, "SetInitialMoisture");
    actualMoisture = ml;
}

Signal SoilMoistureController::RequestMoistureChange() {
    if (actualMoisture && desiredMoisture) {
        if (*actualMoisture < *desiredMoisture) return Signal::INCREASE;
        if (*actualMoisture > *desiredMoisture) return Signal::DECREASE;
    }
    return Signal::MAINTAIN;
}

void SoilMoistureController::SetDesiredMoisture(double ml) {
    checkPrecondition(ml, "SetDesiredMoisture");
    desiredMoisture = ml;
}

Signal SoilMoistureController::IncrementMoisture() {
    if (actualMoisture && desiredMoisture && *actualMoisture < *desiredMoisture) {
        checkPrecondition(*actualMoisture + 1, "IncrementMoisture");
        *actualMoisture += 1;
        return Signal::INCREASE;
    }
    return Signal::MAINTAIN;
}

Signal SoilMoistureController::DecrementMoisture() {
    if (actualMoisture && desiredMoisture && *actualMoisture > *desiredMoisture) {
        checkPrecondition(*actualMoisture - 1, "DecrementMoisture");
        *actualMoisture -= 1;
        return Signal::DECREASE;
    }
    return Signal::MAINTAIN;
}

optional<double> SoilMoistureController::GetActualMoisture() {
    return actualMoisture;
}

optional<double> SoilMoistureController::GetDesiredMoisture() {
    return desiredMoisture;
}
