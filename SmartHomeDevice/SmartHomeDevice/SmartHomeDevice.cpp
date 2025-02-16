#include"SmartHomeDevice.h"

int main()
{
    Device d1("Arcelik Utu", 31, VERY_LOW_ENERGY, true);

    d1.displayDevice();
    cout << endl;
    d1.setDeviceBrig(88);
    d1.setDeviceEcoMode(true);
    d1.setDeviceEnergySaving(VERY_HIGH_ENERGY);
    d1.deviceTurnOff();
    d1.setDevicePower(72);
    d1.disconnectWifi();
    d1.setTemperature(23.32);
    //d1.connectWifi();
    d1.displayDevice();
}

