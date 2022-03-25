//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2020/07/14
//
#include "mySystemApp.h"

using namespace std;

#define STUDENT_INFO "Name:Yu-Cheng CHANG   ID:310554025"

void MY_SYSTEM_APP::showMyStudentInfo_2021_Summer( ) const
{
	cout << "*******************************" << endl;
    cout << "Date:2021/07/13" << endl;
	cout << "Student ID:\t310554025" << endl;
	cout << "Student Name:\tYu-Cheng CHANG" << endl;
	cout << "Student Email:\tycc210012@gmail.com" << endl;
	cout << "*******************************" << endl;
}

MY_SYSTEM_APP::MY_SYSTEM_APP( )
{
	mSystemType = SYSTEM_TYPE_MONTE_CARLO;
    string title = STUDENT_INFO;
        glutSetWindowTitle(title.data( ));
}

void MY_SYSTEM_APP::initApp( )
{
	mFlgShow_Grid = true;
}

void MY_SYSTEM_APP::update( )
{

}
// CODE: 2021/07/13. Do not delete this line.



