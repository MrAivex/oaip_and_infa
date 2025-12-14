#include <iostream>
#include <fstream>
#include <string>

class Light {
    bool isOn;
public:
    Light() : isOn(false) {}
    void turnOn() { isOn = true; }
    void turnOff() { isOn = false; }
    std::string getStatus() { return isOn ? "On" : "Off"; }
    bool getState() { return isOn; }
    void setState(bool state) { isOn = state; }
};

class Thermostat {
    int temperature;
public:
    Thermostat() : temperature(20) {}
    void setTemperature(int t) { temperature = t; }
    int getTemperature() { return temperature; }
};

class SecuritySystem {
    bool isArmed;
public:
    SecuritySystem() : isArmed(false) {}
    void arm() { isArmed = true; }
    void disarm() { isArmed = false; }
    std::string getStatus() { return isArmed ? "Armed" : "Disarmed"; }
    bool getState() { return isArmed; }
    void setState(bool state) { isArmed = state; }
};

class Curtains {
    bool isUp;
public:
    Curtains() : isUp(false) {}
    void raise() { isUp = true; }
    void lower() { isUp = false; }
    std::string getStatus() { return isUp ? "Raised" : "Lowered"; }
    bool getState() { return isUp; }
    void setState(bool state) { isUp = state; }
};

class AirConditioner {
    bool isOn;
public:
    AirConditioner() : isOn(false) {}
    void turnOn() { isOn = true; }
    void turnOff() { isOn = false; }
    std::string getStatus() { return isOn ? "On" : "Off"; }
    bool getState() { return isOn; }
    void setState(bool state) { isOn = state; }
};

class SmartHome {
    Light light;
    Thermostat thermostat;
    SecuritySystem security;
    Curtains curtains;
    AirConditioner ac;
    std::string stateFile = "home_state.txt";
public:
    void controlLight(bool state) { light.setState(state); }
    void setTemperature(int temp) { thermostat.setTemperature(temp); }
    void controlSecurity(bool state) { security.setState(state); }
    void controlCurtains(bool state) { curtains.setState(state); }
    void controlAirConditioner(bool state) { ac.setState(state); }
    
    void displayStatus() {
        std::cout << "Current State:\n";
        std::cout << "Light: " << light.getStatus() << "\n";
        std::cout << "Temperature: " << thermostat.getTemperature() << "°C\n";
        std::cout << "Security System: " << security.getStatus() << "\n";
        std::cout << "Curtains: " << curtains.getStatus() << "\n";
        std::cout << "Air Conditioner: " << ac.getStatus() << "\n";
    }
    
    void saveState() {
        std::ofstream file(stateFile);
        file << light.getState() << "\n";
        file << thermostat.getTemperature() << "\n";
        file << security.getState() << "\n";
        file << curtains.getState() << "\n";
        file << ac.getState() << "\n";
    }
    
    void loadState() {
        std::ifstream file(stateFile);
        if (file) {
            int temp;
            bool state;
            file >> state; light.setState(state);
            file >> temp; thermostat.setTemperature(temp);
            file >> state; security.setState(state);
            file >> state; curtains.setState(state);
            file >> state; ac.setState(state);
            std::cout << "State loaded from file.\n";
        } else {
            std::cout << "No previous state file found. Using default settings.\n";
        }
    }
};

int main() {
    SmartHome home;
    home.loadState();
    
    int choice;
    do {
        home.displayStatus();
        std::cout << "\nChoose an action:\n";
        std::cout << "1. Turn on light\n2. Turn off light\n3. Set temperature\n";
        std::cout << "4. Arm security system\n5. Disarm security system\n";
        std::cout << "6. Raise curtains\n7. Lower curtains\n";
        std::cout << "8. Turn on air conditioner\n9. Turn off air conditioner\n10. Exit\n";
        std::cin >> choice;
        
        switch(choice) {
            case 1: home.controlLight(true); break;
            case 2: home.controlLight(false); break;
            case 3: {
                int temp;
                std::cout << "Enter temperature: ";
                std::cin >> temp;
                home.setTemperature(temp);
                break;
            }
            case 4: home.controlSecurity(true); break;
            case 5: home.controlSecurity(false); break;
            case 6: home.controlCurtains(true); break;
            case 7: home.controlCurtains(false); break;
            case 8: home.controlAirConditioner(true); break;
            case 9: home.controlAirConditioner(false); break;
            case 10: 
                home.saveState();
                std::cout << "State saved to home_state.txt. Exiting...\n";
                break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 10);
    
    return 0;
}