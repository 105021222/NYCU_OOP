//********************************************
// Student Name			:
// Student ID			:
// Student Email Address:
//********************************************
//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2021/07/13
//
#include <sstream>
#include "mySystemApp.h"

using namespace std;

#define cn_StudentInfo "Student Name:Yu-Cheng CHANG. ID:310554025"

void MY_SYSTEM_APP::askForInput( )
{
}

void MY_SYSTEM_APP::update_GraphSystemTitle( )
{
    string title;
    string result;
    ostringstream strs;
    ostringstream strs_int;

    double area;
    int numSamples;
    title = cn_StudentInfo;
    title = title + "  " + "Graph System. 2021 Summer.";

    ostringstream strs_d;
    {
        int numNodes = mGraphSystem->getNumOfNodes();
    strs_d.str("");
    strs_d.clear();
    strs_d << numNodes;
    title = title + "  #Nodes:";
    title = title + strs_d.str();
    }

    {
        int numEdges = mGraphSystem->getNumOfEdges();
    strs_d.str("");
    strs_d.clear();
    strs_d << numEdges;
    title = title + "  #Edges:";
    title = title + strs_d.str();
    }

    glutSetWindowTitle(title.data());

}

void MY_SYSTEM_APP::update_ImageSystemTitle( )
{

       string title;
    string result;
    ostringstream strs;
    ostringstream strs_int;

    double area;
    int numSamples;
    title = cn_StudentInfo;
    title = title + "  " + "Image System. 2021 Summer";

    ostringstream strs_d;
    {
        int numNodes = mImageSystem->getNumberOfNodes();
    strs_d.str("");
    strs_d.clear();
    strs_d << numNodes;
    title = title + "  #Nodes:";
    title = title + strs_d.str();
    }

    glutSetWindowTitle(title.data());
}

void MY_SYSTEM_APP::reset( )
{
}

void MY_SYSTEM_APP::clickAt(float x, float y )
{
    if ( mCurSystem ) {
        mCurSystem->clickAt( x, y );
    }
}

bool MY_SYSTEM_APP::specialFunc(int key, int x, int y)
{
    //cout << "special key:" << key << endl;

    bool flgHandled = false;

    if ( mCurSystem == mGraphSystem) {
        mGraphSystem->stopAutoNodeDeletion();
    }
    switch( key ) {
    case GLUT_KEY_F1:
        //glutSetWindowTitle("Graph System");
        update_GraphSystemTitle();
        flgHandled = true;
        mCurSystem = mGraphSystem;
         mCamera->setZoom(53.0);
        mCamera->set( vec3(-22.8, -23.4, 0.0) );
    break;
        case GLUT_KEY_F4:
        //glutSetWindowTitle("Image System");
            update_ImageSystemTitle();
        mCurSystem = mImageSystem;
        mCamera->setZoom(-289);
        mCamera->set( vec3(-241.3, -255.6, 0.0) );

         break;
        case GLUT_KEY_F5:
        glutSetWindowTitle(cn_StudentInfo);

        flgHandled = true;
        break;

    };

    return true;
}

bool MY_SYSTEM_APP::handleKeyEvent( unsigned char key )
{
    bool flgHandled = false;
    cout << "key:" << (int) key << endl;

    if ( key == 's' || key == 'S') {
        showStudentInfo_2021_Summer();
        return true;
    }

    if ( key == 'i' || key == 'I') {
        mCurSystem->askForInput( );
        return true;
    }

    
    if ( mCurSystem ) {
        //mPrev_2048->copy( mCurSystem );
        mCurSystem->handleKeyPressedEvent( key );
        if (mCurSystem==mImageSystem) {
            update_ImageSystemTitle( );
        }
        if ( mCurSystem == mGraphSystem) {
            update_GraphSystemTitle( );
        }
        return true;
    }
    /*
    if ( mSystemType == SYSTEM_TYPE_SIMPLE_PAINTER ) {
        if ( mSimplePainter.handleKeyPressedEvent(key) ) return true;
    }

    if ( mSystemType == SYSTEM_TYPE_GALAXY_SYSTEM ) {
        if ( mGalaxySystem.handleKeyPressedEvent(key) ) return true;
    }

    if ( mSystemType == SYSTEM_TYPE_MONTE_CARLO_SIMULATION ) {
        if ( mMonteCarloSystem.handleKeyPressedEvent(key) ) {
            updateMonteCarloTitle( );
            return true;
        }

    }
    */

    switch ( key ) {
    case 'm':
    case 'M':
        showMenu( );
        break;
    case 's':
    case 'S':
        showStudentInfo_2021_Summer( );
        break;
    case 'i':
    case 'I':
        askForInput( );
        break;
    case 'g':
    case 'G':
        mFlgShow_Grid = !mFlgShow_Grid;
        break;
    case 'r':
    case 'R':
        reset( );
        flgHandled = true;
        break;
    case 'z':
    case 'Z':
        mCamera->setZoom(-44.0);
        break;
    case 'c':
    case 'C':
        mCamera->setZoom(1.0);
        break;
    }
    return flgHandled;
}

bool MY_SYSTEM_APP::mouseMotionFunc( int mx, int my )
{
    static vector3 color( 1.0, 0.0, 0.0 );


    float x, y, z;
    mCamera->getCoordinates( x, y, z, (float) mx, (float) my );

    mMouseX_2DSpace = x;
    mMouseY_2DSpace = z;

    if ( mMouseButton == GLUT_LEFT_BUTTON ) {
        //cout << "mouseMotionFunc GLUT_LEFT_BUTTON" << endl;

        if ( mCurSystem == mImageSystem) {
                float x, y, z;
    mCamera->getCoordinates( x, y, z, (float) mx, (float) my );

    mMouseX_2DSpace = x;
    mMouseY_2DSpace = z;
    if ( mCurSystem ) {
        mCurSystem->handleMotionMouseEvent( x, z );
    }
    return true;
        }

        float rf = (rand()%1000)/1000.0f*0.5f;
        color += vector3(0.1f, 0.07f, 0.11f*rf);
        //clickAt( (int) x, (int) z, color );
        clickAt( x, z );
        return true;

    } else {

        
        //if ( mPickedObj == 0 ) {
        return FREE_CANVAS_2D::mouseMotionFunc( mx, my );
        //}
    }

    //cout << "here 5" << endl;

    //float x, y, z;
    //mCamera->getCoordinates( x, y, z, mx, my );
    //cout << "Set Position XZ:" << x << "\t" << z << endl;
    return true;
}

bool MY_SYSTEM_APP::mouseFunc( int button, int state, int mx, int my )
{
    //cout << "button:" << button << endl;
    //if ( mPickedObj == 0 || button == GLUT_MIDDLE_BUTTON ) {
    //if ( button == 3 || button == 4 ) {

    float x, y, z;
    mCamera->getCoordinates( x, y, z, (float) mx, (float) my );

    vector3 color( 1.0, 0.0, 0.0 );
    mMouseButton = button;
    mMouseX = mx;
    mMouseY = mCanvasHeight - my;

    //cout << "mMouseX:" << mMouseX << endl;

    //cout << "mMouseY:" << mMouseY << endl;

    if ( button == GLUT_LEFT_BUTTON ) 
    {
        if ( state == GLUT_DOWN ) {
            clickAt( x, z );
        }   
    } else {
        return FREE_CANVAS_2D::mouseFunc( button, state, mx, my );
    }
    return true;
}


bool MY_SYSTEM_APP::passiveMouseFunc( int mx, int my )
{
    float x, y, z;
    mCamera->getCoordinates( x, y, z, (float) mx, (float) my );

    mMouseX_2DSpace = x;
    mMouseY_2DSpace = z;
    if ( mCurSystem ) {
        mCurSystem->handlePassiveMouseEvent( x, z );
        if ( mCurSystem == mImageSystem ) {
            update_ImageSystemTitle( );
        }
    }
    return true;
}