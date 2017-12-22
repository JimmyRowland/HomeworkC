// Declaration of class FlashDrive
#ifndef FLASHDRIVE_H
#define FLASHDRIVE_H


//#include <iostream>
#include <string>
class FlashDrive
{
private:
    int my_StorageCapacity;  //Capacity of the flash drive(in MB)
    int my_StorageUsed;      //Amount of storage used(in MB)
    bool me_IsPluggedIn;     //Whether the flash drive is plugged in

    double my_Specification; //USB 1.1, 2.0 and 3.0
    int my_TransferRate;     //12 Mbits/s for USB 1.1, 480 Mbits/s for USB 2.0, 5000 Mbit/s for USB 3.0
    string my_FileSystem;    //File system can be NTFS, FAT, FAT32, and exFAT
    string my_ConnectorType; //Connector types can be Standard , Mini and  Micro

public:
    FlashDrive();
    FlashDrive(int capacity, int used, bool pluggedIn);
    FlashDrive(int capacity, int used, bool pluggedIn,
               double specification, int transferRate,
               string fileSystem, string connectorType);

    void pluugedIn();
    void pullOut();
    void writeData(int amount);
    void eraseData(int amount);
    void formatDrive();

    int getCapacity();
    void setCapacity(int amount);

    int getUsed();
    void setUsed(int amount);

    bool isPluugedIn();

    void setSpecification(double specification);
    void setTransferRate(int transferRate);
    void setFileSystem(string fileSystem);
    void setConnectorType(string connectorType);

    double getSpecification();
    int getTransferRate();
    string getFileSystem() const;
    string getConnectorType() const;
};

#endif
