// SoilMoistureControllerTester.cpp
#include "SoilMoistureController.h"

class SoilMoistureControllerTester {
public:
    static void DisplayMoistureLevels(SoilMoistureController& smc);
    static void IncrementMoisture(SoilMoistureController& smc);
    static void SetDesiredMoisture(SoilMoistureController& smc, double ml);
    static void DecrementMoisture(SoilMoistureController& smc);
    static void MainTesterLoop();
};

void SoilMoistureControllerTester::DisplayMoistureLevels(SoilMoistureController& smc) {
    auto actualMoisture = smc.GetActualMoisture();
    auto desiredMoisture = smc.GetDesiredMoisture();
    cout << "Current Actual Moisture: " << (actualMoisture ? to_string(*actualMoisture) : "Undefined") << endl;
    cout << "Current Desired Moisture: " << (desiredMoisture ? to_string(*desiredMoisture) : "Undefined") << endl;
}

void SoilMoistureControllerTester::IncrementMoisture(SoilMoistureController& smc) {
    auto result = smc.IncrementMoisture();
    cout << "Increment Result: " << signalToString(result) << endl;
}

void SoilMoistureControllerTester::SetDesiredMoisture(SoilMoistureController& smc, double ml) {
    smc.SetDesiredMoisture(ml);
    cout << "Moisture set to: " << ml << endl;
}

void SoilMoistureControllerTester::DecrementMoisture(SoilMoistureController& smc) {
    auto result = smc.DecrementMoisture();
    cout << "Decrement Result: " << signalToString(result) << endl;
}

void SoilMoistureControllerTester::MainTesterLoop() {
    double initMoisture;
    SoilMoistureController smc;
    cout << "Set Initial Moisture: \n";
    cin >> initMoisture;
    smc.SetInitialMoisture(initMoisture);

    char choice;
    do {
        cout << "\n\t\tSoilMoistureController Tester\n";
        cout << "1. Display moisture levels\n";
        cout << "2. Set desired moisture\n";
        cout << "3. Increment moisture\n";
        cout << "4. Decrement moisture\n";
        cout << "5. Quit\n";
        cout << "Enter choice (1-5): ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case '1': DisplayMoistureLevels(smc); break;
            case '2':
                double ml;
                cout << "Set Desired Moisture : " << endl;
                cin >> ml;
                SetDesiredMoisture(smc, ml);
                break;
            case '3': IncrementMoisture(smc); break;
            case '4': DecrementMoisture(smc); break;
            case '5': cout << "Exiting tester." << endl; break;
            default: cout << "Invalid choice, try again." << endl; break;
        }
    } while (choice != '5');
}

int main() {
    SoilMoistureControllerTester::MainTesterLoop();
    return 0;
}
