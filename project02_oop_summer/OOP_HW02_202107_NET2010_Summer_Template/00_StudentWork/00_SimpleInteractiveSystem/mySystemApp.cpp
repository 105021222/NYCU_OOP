//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2021/07/13
//
#include "mySystemApp.h"

using namespace std;

void MY_SYSTEM_APP::showStudentInfo_2021_Summer( ) const
{
	cout << "*******************************" << endl;
    cout << "Date: 2021/07/13" << endl;
	cout << "Student ID:\t310554025" << endl;
	cout << "Student Name:\tYu-Cheng CHANG" << endl;
	cout << "Student Email:\tycc210012@gmail.com" << endl;
	cout << "*******************************" << endl;
}

void MY_SYSTEM_APP::showMenu( ) const
{
    cout << "Welcome to our mini-galaxy!" << endl;
    cout << "Menu----------------------" << endl;
    cout << "Key usage:" << endl;
    cout << "F1: Monte Carlo Simulation" << endl;
    cout << "F2: Galaxy" << endl;
    cout << "F3: Painter" << endl;
    cout << "F4: Visualization of Bubble Sort" << endl;
    cout << "F5: Simple File Reader" << endl;
    cout << endl;
    cout << "r: reset" << endl;

    cout << "--------------------------" << endl;

}

MY_SYSTEM_APP::MY_SYSTEM_APP( )
{
	mSystemType = SYSTEM_TYPE_GALAXY_SYSTEM;
    mColorPalette = new COLOR_PALETTE;
    //
    mCurSystem = 0;
}

void MY_SYSTEM_APP::initApp( )
{
	mFlgShow_Grid = false;
    showMenu( );
    //
    mGraphSystem = new GRAPH_SYSTEM;

    //
    mCurSystem = mGraphSystem;
    mImageSystem = new IMAGE_SYSTEM;

    mCurSystem = mImageSystem;

    ////////////////////////////////////////////
    //
    specialFunc(GLUT_KEY_F1, 0, 0);
}

void MY_SYSTEM_APP::update( )
{
    mCurSystem->update( );
}




