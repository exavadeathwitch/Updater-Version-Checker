// Updater Version Checker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;
//Main Program
bool loopconsole = 1;
int ApplicationVersions[5] = { 1, 2, 3, 4, 5 };
string ApplicationDownloadLinks[5] = { "https://drive.google.com/file/d/1Q3IX0djxodFcfyN9EuqtDySaS5pIZRju/view?usp=sharing", "https://drive.google.com/file/d/1zwYe5SDqJH_cw8zOSfUd6-mq7PCFvPqO/view?usp=sharing", "https://drive.google.com/file/d/1Z4DlPo56a5ZEZD-Wp-jduz25m1lp1cO8/view?usp=sharing", "https://drive.google.com/file/d/1oB8Azt6DM5zz2bCrBsfoSzkf92528vrE/view?usp=sharing", "https://drive.google.com/file/d/1Y0AG8uaME9tn1lu6Rv-A9Ao8co9R92lv/view?usp=sharing" };
bool WantToDownload(void)
{
    int Download;
    cout << "Type 1 if you would like to download an application." << endl;
    cin >> Download;
    switch (Download)
    {
    case 1: return 1;
        break;
    default: return 0;
        break;
    }
    return 1;
}
int main()
{
    bool WantToDownload();
    /*
    if (loopconsole == 0)
    {
        exit(EXIT_FAILURE);
    }
    
    //Find application version number
    string line;
    ifstream myfile("Application.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << "Current Application Version: " << line << '\n';
        }
        myfile.close();
    }
    */


}

