#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <array>
#include <windows.h>
using namespace std;

//Variables
bool ApplicationExists = 0;
bool FileExists = 1;
bool LoopConsole = 1;
int WhichApplicationtoDownload;
int WanttoDownload;
int WanttoCheck;
string DownloadStatus;
//Lists
int ApplicationVersions[5] = { 1, 2, 3, 4, 5 };
string ApplicationDownloadLinks[5] = { "https://drive.google.com/file/d/1Q3IX0djxodFcfyN9EuqtDySaS5pIZRju/view?usp=sharing", "https://drive.google.com/file/d/1zwYe5SDqJH_cw8zOSfUd6-mq7PCFvPqO/view?usp=sharing", "https://drive.google.com/file/d/1Z4DlPo56a5ZEZD-Wp-jduz25m1lp1cO8/view?usp=sharing", "https://drive.google.com/file/d/1oB8Azt6DM5zz2bCrBsfoSzkf92528vrE/view?usp=sharing", "https://drive.google.com/file/d/1Y0AG8uaME9tn1lu6Rv-A9Ao8co9R92lv/view?usp=sharing" };
//Function Declaration
void ApplicationOnDisk();
int main()
{
    //Want to Download Application
    cout << "Type 1 if you would like to download an application." << endl;
    cin >> WanttoDownload;
    if (WanttoDownload != 1)
    {
        exit(EXIT_FAILURE);
    }

    //Which Application is Downloaded
    while (FileExists == 1)
    {
        ApplicationExists = 0;
        while (ApplicationExists == 0)
        {
            cout << "Which application would you like to download?" << endl;
            ApplicationOnDisk();
            cin >> WhichApplicationtoDownload;
            if (WhichApplicationtoDownload <= (sizeof(ApplicationVersions) / sizeof(ApplicationVersions[0])) && WhichApplicationtoDownload > 0)
            {
                ApplicationExists = 1;
            }
            else
            {
                cout << "Please pick a value from the list." << endl;
            }
        }

        //Check if Selected Application is Downloaded
        string line;
        string FileName = to_string(ApplicationVersions[WhichApplicationtoDownload - 1]) + ".txt";
        ifstream myfile(FileName);
        if (myfile)
        {
            cout << "The selected file is already downloaded. Please choose another file." << endl;
            myfile.close();
        }
        else
        {
            FileExists = 0;
        }
        if (FileExists == 0)
        {
            cout << "Application not downloaded." << endl;
        }
    }

    //Downloading Application
    cout << "Download link opened. \nPlease put the downloaded file in your program's directory." << endl;
    string DownloadURL = ApplicationDownloadLinks[WhichApplicationtoDownload - 1];
    ShellExecute(NULL, "open", DownloadURL.c_str(), NULL, NULL, SW_SHOWNORMAL);

    //See If Program Installed Correctly
    cout << "Type 1 to check if your program was installed correctly." << endl;
    cin >> WanttoCheck;
    if (WanttoCheck != 1)
    {
        exit(EXIT_FAILURE);
    }
    ApplicationOnDisk();

    //Exit
    cout << "Thank you! Input anything to exit this program. ";
    cin >> WanttoCheck;
    return 0;
}


void ApplicationOnDisk()
{
    for (int i = 0; i < sizeof(ApplicationVersions) / sizeof(ApplicationVersions[0]); i++)
    {
        string line;
        string FileName = to_string(ApplicationVersions[i]) + ".txt";
        ifstream myfile(FileName);
        if (myfile)
        {
            DownloadStatus = "Downloaded";
            myfile.close();
        }
        else
        {
            DownloadStatus = "Not Downloaded";
        }
        cout << ApplicationVersions[i] << " " << DownloadStatus << endl;
    }
}
