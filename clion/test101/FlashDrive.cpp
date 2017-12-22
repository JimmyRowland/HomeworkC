// Constructors and member functions definitions for class FlashDrive

using namespace std;

#include "FlashDrive.h"

// Constructors

//Default constructor
FlashDrive::FlashDrive( )
{
    my_StorageCapacity = 128;       //Default capacity is 128 MB
    my_StorageUsed = 0;
    me_IsPluggedIn = false;

    my_Specification = 1.1;         //Default specification is USB 1.1
    my_TransferRate = 12;           //Default transfer rate is 12 Mbits/s
    my_FileSystem = "FAT";          //Default file system is FAT
    my_ConnectorType = "Standard";  //Default connector type is "Standard"
}

//Parameterized constructor
FlashDrive::FlashDrive(int capacity, int used, bool pluggedIn)
{
    my_StorageCapacity = capacity;
    my_StorageUsed = used;
    me_IsPluggedIn = pluggedIn;

    my_Specification = 1.1;         //Default specification is USB 1.1
    my_TransferRate = 12;           //Default transfer rate is 12 Mbits/s
    my_FileSystem = "FAT";          //Default file system is FAT
    my_ConnectorType = "Standard";  //Default connector type is "Standard"
}

//Parameterized constructor
FlashDrive::FlashDrive(int capacity, int used, bool pluggedIn,
                       double specification, int transferRate,
                       string fileSystem, string connectorType)
{
    my_StorageCapacity = capacity;
    my_StorageUsed = used;
    me_IsPluggedIn = pluggedIn;

    my_Specification = specification;
    my_TransferRate = transferRate;
    my_FileSystem = fileSystem;
    my_ConnectorType = connectorType;
}

//Member functions /methods definitions

//This method plug in the flash drive
void FlashDrive::pluugedIn()
{
    me_IsPluggedIn = true;
}

//This method unplug the flash drive
void FlashDrive::pullOut()
{
    me_IsPluggedIn = false;
}

//This method writes the specified amount of data on the drive
void FlashDrive::writeData(int amount)
{
    if(amount>=0 && ((my_StorageCapacity-my_StorageUsed)>=amount))
        my_StorageUsed += amount;
}

//This method deletes the specified amount of data from the drive
void FlashDrive::eraseData(int amount)
{
    if(amount>=0 && (amount<=my_StorageUsed))
        my_StorageUsed -= amount;
}

//This method formats(deletes all data) the drive
void FlashDrive::formatDrive()
{
    my_StorageUsed = 0;
}

//This method returns the capacity of the flash drive
int FlashDrive::getCapacity()
{
    return my_StorageCapacity;
}

//This method sets the capacity of the flash drive
void FlashDrive::setCapacity(int amount)
{
    my_StorageCapacity = amount;
}

//This method returns the amount of space used in the drive
int FlashDrive::getUsed()
{
    return my_StorageUsed;
}

//This method sets the amount of space to be used
void FlashDrive::setUsed(int amount)
{
    my_StorageUsed = amount;
}

//This method returns true if the drive is plugged in otherwise false
bool FlashDrive::isPluugedIn( )
{
    return me_IsPluggedIn;
}

//This method sets the USB specification(1.1, 2.0, 3.0)
void FlashDrive::setSpecification(double specification)
{
    my_Specification = specification;
}

//This method sets the data transfer rate
void FlashDrive::setTransferRate(int transferRate)
{
    my_TransferRate = transferRate;
}

//This method sets the file system of the drive
void FlashDrive::setFileSystem(string fileSystem)
{
    my_FileSystem = fileSystem;
}

//This method sets the type of connector of the drive
void FlashDrive::setConnectorType(string connectorType)
{
    my_ConnectorType = connectorType;
}

//This method returns the USB specification
double FlashDrive::getSpecification()
{
    return my_Specification;
}

//This method returns the data transfer rate
int FlashDrive::getTransferRate()
{
    return my_TransferRate;
}

//This method returns the type of file system of the drive
string FlashDrive::getFileSystem() const
{
    return my_FileSystem;
}

//This method returns the type of connector of the drive
string FlashDrive::getConnectorType() const
{
    return my_ConnectorType;
}
