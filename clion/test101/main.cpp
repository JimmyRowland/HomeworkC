
	//This is the driver to test FlashDrive
#include<iostream>
	using namespace std;

#include "FlashDrive.h"

//Function prototype
void showFlashDriveInfo(FlashDrive);

//Main function
int main()
{
	cout << "Welcome to Howie's Flash USB Drive Store!"
		<< endl;
	//Create the first FlashDrive
	FlashDrive fd1 = FlashDrive();

	//Create the second FlashDrive
	FlashDrive fd2 = FlashDrive(512, 0, false);

	//Create the third FlashDrive
	FlashDrive fd3 = FlashDrive(1000, 0, false, 2.0, 480, "NTFS", "Standard");

	//Information of the first FlashDrive
	cout << "\nInformation of the first flash drive" << endl;
	cout << "------------------------------------" << endl;
	showFlashDriveInfo(fd1);

	//Information of the second FlashDrive
	cout << "\nInformation of the second flash drive" << endl;
	cout << "-------------------------------------" << endl;
	showFlashDriveInfo(fd2);

	fd3.setUsed(256);
	//Information of the third FlashDrive
	cout << "\nInformation of the third flash drive" << endl;
	cout << "------------------------------------" << endl;
	showFlashDriveInfo(fd3);
	
	return 0;

}

//This function prints all information of a FlashDrive
void showFlashDriveInfo(FlashDrive drive)
{
	cout << "Specification: USB " << drive.getSpecification() << endl;
	cout << "Transfer Rate: " << drive.getTransferRate() << " Mbits/s" << endl;
	cout << "Capacity: " << drive.getCapacity() << " MB" << endl;
	cout << "File System: " << drive.getFileSystem() << endl;
	cout << "Connector Type: " << drive.getConnectorType() << endl;
	cout << "Used space: " << drive.getUsed() << " MB" << endl;
}
