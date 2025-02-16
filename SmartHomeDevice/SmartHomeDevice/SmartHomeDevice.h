#ifndef SMARTHOME_H
#define SMARTHOME_H



#include<iostream>

using namespace std;


typedef enum {
	VERY_LOW_ENERGY = 0,
	LOW_ENERGY,
	STANDARD_ENERGY,
	HIGH_ENERGY,
	VERY_HIGH_ENERGY
} device_energy;

class Device {

	string deviceName;
	bool   deviceStatus, deviceEcoMode, deviceWifiConnected;
	float devicePowerConsumption, deviceTemperature;
	int   deviceId, deviceBrightness;
	device_energy  deviceEnergySavingLevel;
public:

	Device(string deviceName, int id, device_energy deviceEnergySavingLevel, bool deviceWifiConnected);
	~Device();
	Device(const Device& oth);
	bool controlName(string name);
	void setDeviceName(string name);

	bool isDeviceOn()const;

	string getDeviceName() const;
	bool	getdeviceEcoMode();
	bool	getDeviceStatus();
	bool	getDeviceWifiConnected();
	float	getPowerConsumption();
	float	getTemperature();
	int		getDeviceId();
	string  getdeviceEnergySaving();
	device_energy		getDeviceEnergy();
	int		getDeviceBrightness();
	bool	setdeviceStatus(bool state);
	void	setDeviceEcoMode(bool mode);
	void	setDeviceWifiConnected(bool connect);
	void	setDevicePower(float power);
	void	setTemperature(float temp);
	void	setDeviceID(int id);
	void	setDeviceBrig(int brig);
	void	setDeviceEnergySaving(device_energy deviceEnergySavingLevel);
	void	deactiveEcoMode();
	void	connectWifi();
	void	disconnectWifi();
	void	displayDevice();

	bool   deviceTurnOn();
	bool   deviceTurnOff();
	
};



Device::Device(string deviceName, int id, device_energy deviceEnergySavingLevel, bool deviceWifiConnected) {
	cout << "Device olusturuluyor..." << endl;
	setDeviceName(deviceName);
	setDeviceID(id);
	setDeviceEnergySaving(deviceEnergySavingLevel);
	setDeviceWifiConnected(deviceWifiConnected);
	setDeviceEcoMode(false);
	setDevicePower(0.0);
	setdeviceStatus(true);
	setTemperature(0.0);
	setDeviceBrig(0);
}


Device::~Device()
{
	cout << "Deconstructor worked !" << endl;
}

Device::Device(const Device& oth)
{
	this->deviceBrightness = oth.deviceBrightness;
	this->deviceEcoMode = oth.deviceEcoMode;
	this->deviceEnergySavingLevel = oth.deviceEnergySavingLevel;
	this->deviceId = oth.deviceId;
	this->deviceName = oth.deviceName;
	this->devicePowerConsumption = oth.devicePowerConsumption;
	this->deviceStatus = oth.deviceStatus;
	this->deviceTemperature = oth.deviceTemperature;
	this->deviceWifiConnected = oth.deviceWifiConnected;

	cout << " Hedefe Kopyalandi. " << endl;
}
bool Device::isDeviceOn() const {
	if (!this->deviceStatus) {
		cout << "Islem yapabilmek icin cihazi aciniz.." << endl;
		return false;
	}
	return true;
}

bool Device::controlName(string name)
{
	for (size_t i = 0; i < name.length(); ++i)
	{
		if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')))
		{
			return false;
		}

	}
	return !name.empty();
}

void Device::setDeviceName(string name)
{
	while (!controlName(name))
	{
		cout << "Gecersiz isim lutfen gecerli bir isim giriniz : ";
		cin >> name;
		cout << endl;
	}
	this->deviceName = name;
}

string Device::getDeviceName() const
{
	return this->deviceName;
}

bool Device::getDeviceStatus() {
	return this->deviceStatus;
}

bool Device::getDeviceWifiConnected()
{
	return this->deviceWifiConnected;
}

float Device::getPowerConsumption()
{
	return this->devicePowerConsumption;
}
float Device::getTemperature()
{
	return this->deviceTemperature;
}
 
int    Device::getDeviceId()
{
	return this->deviceId;
}
device_energy    Device::getDeviceEnergy()
{
	return this->deviceEnergySavingLevel;

}
int    Device::getDeviceBrightness()
{

	return this->deviceBrightness;

}


bool	Device::setdeviceStatus(bool state)
{
	if (getDeviceStatus() == state)
	{
		cout << "Cihazin durumu zaten ayni." << endl;
		return false;
	}
	state == true ? cout << "Cihaz aciliyor.." : cout << "Cihaz kapatiliyor..." << endl;
	this->deviceStatus = state;

	return true;

}

bool   Device::deviceTurnOn()
{

	return setdeviceStatus(true);

	
}
bool   Device::deviceTurnOff()
{
	return setdeviceStatus(false);
} 


void	Device::setDeviceEcoMode(bool mode)
{
	if (!isDeviceOn()) return;
	this->deviceEcoMode = mode;
	this->deviceEnergySavingLevel =  mode ? VERY_LOW_ENERGY : STANDARD_ENERGY;
	cout << "Cihaz eco modu " << (mode ? "ENABLE" : "DISABLE") << " edildi." << endl;

}
void	Device::setDeviceWifiConnected(bool connect)
{	
	this->deviceWifiConnected = connect;

}
void	Device::setDevicePower(float power)
{
	if (!isDeviceOn()) return;
	power <= 100 && power >= 0 ? this->devicePowerConsumption = power : this->devicePowerConsumption = 0.0;
}
void	Device::setTemperature(float temp)
{
	temp <= 100 && temp >= 0 ? this->deviceTemperature = temp : this->deviceTemperature = 0.0;
}
void	Device::setDeviceID(int id)
{
	if (!isDeviceOn()) return;
	this->deviceId = id;
}
void	Device::setDeviceBrig(int brig)
{
	if (!isDeviceOn()) return;
	this->deviceBrightness =  brig <= 100 && brig >= 0 ?  brig : 0;
	cout << "deviceBrightness %" << this->deviceBrightness << " 'e set edildi." << endl;
}
void	Device::setDeviceEnergySaving(device_energy deviceEnergySavingLevel)
{
	if (!isDeviceOn()) return;
	this->deviceEnergySavingLevel = deviceEnergySavingLevel;
	cout << "Cihaz'in energy saving seviyesi " <<"'" << getdeviceEnergySaving() <<"'" << " olarak ayarlandi." << endl;

}

void	Device::deactiveEcoMode()
{
	if (!isDeviceOn()) return;
	setDeviceEcoMode(false);
}
void	Device::connectWifi()
{
	if (!isDeviceOn()) return;
	setDeviceWifiConnected(true);
	cout << "Wi-Fi baglandi." << endl;
}
void	Device::disconnectWifi()
{
	if (!isDeviceOn()) return;
	setDeviceWifiConnected(false);
}

string  Device::getdeviceEnergySaving() 
{
	switch (this->deviceEnergySavingLevel)
	{
		case VERY_LOW_ENERGY:
			return "VERY_LOW_ENERGY";
		case LOW_ENERGY:
			return "LOW_ENERGY";
		case STANDARD_ENERGY:
			return"STANDARD_ENERGY";
		case HIGH_ENERGY:
			return "HIGH_ENERGY";
		case VERY_HIGH_ENERGY:
			return "VERY_HIGH_ENERGY";
	}

	return "NONE";
}


void	Device::displayDevice()
{
	cout << "---------------------------------\n";
	cout << " Cihaz Bilgileri \n";
	cout << "---------------------------------\n";
	cout << "Cihaz Adi           : " << this->deviceName << endl;
	cout << "Durum               : " << (this->deviceStatus ? "ACIK" : "KAPALI") << endl;
	cout << "Eco Modu            : " << (this->deviceEcoMode ? "ACIK" : "KAPALI") << endl;
	cout << "Wi-Fi Baglantisi    : " << (this->deviceWifiConnected ? "BAGLI" : "BAGLI DEGIL") << endl;
	cout << "Guc Tuketimi (Watt) : " << this->devicePowerConsumption << " W" << endl;
	cout << "Sicaklik (C)        : " << this->deviceTemperature << "C" << endl;
	cout << "Parlaklik           : " << this->deviceBrightness << "%" << endl;
	cout << "Enerji Tasarrufu    : " << getdeviceEnergySaving() << endl;
	cout << "---------------------------------\n";
}

#endif