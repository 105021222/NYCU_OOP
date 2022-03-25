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
#include <iostream>
#include <fstream>
#include "mySystem_GraphSystem.h"
#include <time.h>

using namespace std;

#define GRAPH_FILE_NAME "graph.txt"

int Param::GRAPH_MAX_NUM_NODES = 10000;
int Param::GRAPH_MAX_NUM_EDGES = 10000;
int Param::Export_Count_DrawingFX = 300;

GRAPH_SYSTEM::GRAPH_SYSTEM( )
{
    mFlgAutoNodeDeletion = false;
    mExport_Count_DrawingFX = 0;

    initMemoryPool();
    createDefaultGraph();
}

void GRAPH_SYSTEM::initMemoryPool( )
{
    mMaxNumNodes = Param::GRAPH_MAX_NUM_NODES;
    mMaxNumEdges = Param::GRAPH_MAX_NUM_EDGES;

    mNodeArr_Pool = new GRAPH_NODE[mMaxNumNodes];
    mEdgeArr_Pool = new GRAPH_EDGE[mMaxNumEdges];

    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;
    mActiveNodeArr = new int[mMaxNumNodes];
    mActiveEdgeArr = new int[mMaxNumEdges];

    mFreeNodeArr = new int[mMaxNumNodes];
    mFreeEdgeArr = new int[mMaxNumEdges];
    //
    for ( int i = 0; i < mMaxNumNodes; ++i ) {
        mNodeArr_Pool[ i ].id = i;
    }
    for ( int i = 0; i < mMaxNumEdges; ++i ) {
        mEdgeArr_Pool[ i ].id = i;
    }
    //
    reset( );
}

void GRAPH_SYSTEM::reset( )
{
    stopAutoNodeDeletion();

    //mNumPoints_DoubleCircles = 0;

    mCurNumOfActiveNodes = 0;
    mCurNumOfActiveEdges = 0;

    mCurNumOfFreeNodes = mMaxNumNodes;
    mCurNumOfFreeEdges = mMaxNumEdges;

    for ( int i = 0; i < mCurNumOfFreeNodes; ++i ) {
        mFreeNodeArr[ i ] = i;
    }
    for ( int i = 0; i < mCurNumOfFreeEdges; ++i ) {
        mFreeEdgeArr[ i ] = i;
    }

    mPassiveSelectedNode = 0;
    mSelectedNode = 0;
}

GRAPH_NODE *GRAPH_SYSTEM::getFreeNode( ) 
{
    if ( mCurNumOfFreeNodes == 0 ) return 0;
    --mCurNumOfFreeNodes;
    int id = mFreeNodeArr[ mCurNumOfFreeNodes ];
    GRAPH_NODE *n = &mNodeArr_Pool[id];
    mActiveNodeArr[mCurNumOfActiveNodes] = id;
    n->dynamicID = mCurNumOfActiveNodes;
    ++mCurNumOfActiveNodes;
    return n;

}

GRAPH_EDGE *GRAPH_SYSTEM::getFreeEdge( )
{
    if ( mCurNumOfFreeEdges == 0 ) return 0;
    --mCurNumOfFreeEdges;
    int id = mFreeEdgeArr[ mCurNumOfFreeEdges ];
    GRAPH_EDGE *e = &mEdgeArr_Pool[ id ];
    mActiveEdgeArr[ mCurNumOfActiveEdges ] = id; 
    e->dynamicID = mCurNumOfActiveEdges;
    ++mCurNumOfActiveEdges;
    return e;
}

void GRAPH_SYSTEM::createDefaultGraph( )
{
    cout << "here"<< endl;
    reset( );

    int n_0 = addNode( 0.0, 0.0, 0.0 );
    cout << "n_0:"<< n_0 << endl;

	int n_1 = addNode( 5.0, 0.0, 0.0 );
    cout << "n_1:"<< n_1 << endl;

    int n_2 = addNode( 0.0, 0.0, 5.0 );
    cout << "n_2:"<< n_2 << endl;
    int a=addEdge( n_0, n_1 );
	int b=addEdge( n_2, n_1 );
	int c=addEdge( n_0, n_2 );
	
	
	
	
	

}

void GRAPH_SYSTEM::createNet_Horizontal( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    vector<int> id;
	
	
}

void GRAPH_SYSTEM::createNet_Vertical( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    vector<int> id;
}

void GRAPH_SYSTEM::createRandomGraph( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;

}

void GRAPH_SYSTEM::createRadialGraph( int nx, int ny )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;

}

void GRAPH_SYSTEM::createRandomGraph_DoubleCircles(int n)
{
    reset( );

    //n = 36;
    float dx = 5.0;
    float dz = 5.0;
    float r = 15; // radius
    float d = 10; // layer distance
    float offset_x = 15.;
    float offset_z = 15.;
	float pi=3.14;
	vector<int> id;

	for(int i=0;i<n;i++){
		int n_0=addNode(r*cos(i*2*pi/n),0.0,r*sin(i*2*pi/n));
		id.push_back(n_0);
	}
	for(int i=0;i<n;i++){
		int n_0=addNode((r+d)*cos(i*2*pi/n),0.0,(r+d)*sin(i*2*pi/n));
		id.push_back(n_0);
	}
	int count=0;
	for(int i=n;i<2*n;i++){
		float x=mNodeArr_Pool[id[i]].p.nx;
		if(x>r){
			count++;
		}
	}
	srand(time(NULL));
	for(int i=0;i<n;i++){
		int n_0,n_1;
		n_0=id[i];
		n_1=id[n+(n+i+rand()%count-count/2)%n];
		addEdge(n_0,n_1);
	}
}

void GRAPH_SYSTEM::createNet_Circular( int n, int num_layers )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
	float pi=3.14;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 15.;
    float offset_z = 15.;
    vector<int> id;
    id.resize( n*(num_layers+1) );
	for(int j=0;j<num_layers+1;j++){
		for(int i=0;i<n;i++){
			int nodeID=addNode((j*d+r)*cos(2*i*pi/n),0.0,(j*d+r)*sin(2*i*pi/n));
			id[n*j+i]=nodeID;
		}
	}
	for(int j=0;j<num_layers;j++){
		for(int i=0;i<n;i++){
			int n_0,n_1;
			n_0=i+n*j;
			n_1=(i+1)%n+n*j;
			addEdge( id[n_0], id[n_1] );
		}
	}
	for(int i=0;i<n*(num_layers);i++){
		int n_0,n_1;
		n_0=i;
		n_1=i+n;
		addEdge( id[n_0], id[n_1] );
	}

}
void GRAPH_SYSTEM::createNet_Square( int n, int num_layers )
{
    reset( );

    float dx = 5.0;
    float dz = 5.0;
    float r = 5; // radius
    float d = 5; // layer distance 
    float offset_x = 5.;
    float offset_z = 5.;

	vector<int> id;
	for(int i=0;i<num_layers;i++){
		for(int j=0;j<num_layers;j++){
			int nodeID=addNode(j*d,0.0,i*d);
			id.push_back(nodeID);
		}
	}
	for(int i=0;i<num_layers;i++){
		for(int j=0;j<num_layers-1;j++){
			int n_0,n_1;
			n_0=num_layers*i+j;
			n_1=num_layers*i+j+1;
			addEdge( id[n_0], id[n_1] );
			n_0=num_layers*j+i;
			n_1=num_layers*j+i+num_layers;
			addEdge( id[n_0], id[n_1] );
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int base;
			base=(num_layers-n)/2*num_layers+(num_layers-n)/2;
			deleteNode(id[base+j+num_layers*i]);
		}
	}
}
void GRAPH_SYSTEM::createNet_RadialCircular( int n ) {

    reset( );

    float offset_x = 15.0;
    float offset_z = 15.0;

    float r = 15; // radius
	float pi=3.14;

	int n_0=addNode(offset_x,0.0,offset_z);
	for(int i=0;i<n;i++){
		int n_1=addNode(offset_x+r*cos(i*2*pi/n),0.0,offset_z+r*sin(i*2*pi/n));
		addEdge( n_0, n_1 );
	}
}

int GRAPH_SYSTEM::addNode( float x, float y, float z, float r )
{
    GRAPH_NODE *g;
    g=getFreeNode();
	if (g==0) return -1; 
    g->p = vector3( x, y, z );
    g->r = r;
    g->edgeID.clear( );
    return g->id;
}

int GRAPH_SYSTEM::addEdge( int nodeID_0, int nodeID_1 )
{
    GRAPH_EDGE *e;
    e = getFreeEdge( );
    if ( e == 0 ) return -1;
    e->nodeID[ 0 ] = nodeID_0;
    e->nodeID[ 1 ] = nodeID_1;
    mNodeArr_Pool[ nodeID_0 ].edgeID.push_back( e->id );
    mNodeArr_Pool[ nodeID_1 ].edgeID.push_back( e->id );
    return e->id;
}

void GRAPH_SYSTEM::askForInput( )
{
    cout << "GRAPH_SYSTEM" << endl;
    cout << "Key usage:" << endl;
    cout << "1: create a default graph." << endl;
    cout << "2: create a Net_Circular graph." << endl;
    cout << "3: create a Net_Square graph." << endl;
    cout << "4: create a Net_RadialCircular graph." << endl;
    cout << "5: create a RandomGraph_DoubleCircles graph." << endl;
    cout << "Delete: delete a node and all the edges attached at it" << endl;
    cout << "Spacebar: unselect the selected node" << endl;
    cout << " " << endl;
    cout << "Use the mouse to select nodes and add edges" << endl;
    cout << "Click the left button to select/unselect or create an edge" << endl;
    cout << " " << endl;
    cout << "A selected node is highlighted as red." << endl;

}

GRAPH_NODE *GRAPH_SYSTEM::findNearestNode( double x, double z, double &cur_distance2 ) const
{
    GRAPH_NODE *n = 0;
    cur_distance2=100;
    for ( int i = 0; i < mCurNumOfActiveNodes; ++i ) {
		GRAPH_NODE *m=0;
		m=&mNodeArr_Pool[mActiveNodeArr[i]];
		if((m->p.nx-x)*(m->p.nx-x)+(m->p.nz-z)*(m->p.nz-z) < cur_distance2*cur_distance2){
			cur_distance2=sqrt((m->p.nx-x)*(m->p.nx-x)+(m->p.nz-z)*(m->p.nz-z));
			n=m;
		}
    }

    return n;
}

void GRAPH_SYSTEM::clickAt(double x, double z)
{
    double cur_d2;
    GRAPH_NODE *n = findNearestNode( x, z, cur_d2 );
    if ( n == 0 ) {
        mSelectedNode = 0;
        return;
    }
    if ( cur_d2 > n->r*n->r ) {
        mSelectedNode = 0;
        return;

    }
    if ( mSelectedNode == n ) {
        mSelectedNode = 0;
        return;
    }
    if ( mSelectedNode != 0 ) {
        addEdge( mSelectedNode->id, n->id );
        mSelectedNode = 0;
        return;
    }
    mSelectedNode = n;
}

void GRAPH_SYSTEM::deleteEdge( int edgeID )
{
	mFreeEdgeArr[ mCurNumOfFreeEdges ]=edgeID;
	mCurNumOfFreeEdges++;
	GRAPH_EDGE *e = &mEdgeArr_Pool[ edgeID ];
	int dynamicID = e->dynamicID;
	mCurNumOfActiveEdges--;
	int moveID=mActiveEdgeArr[mCurNumOfActiveEdges];//ID
	mActiveEdgeArr[dynamicID]=moveID;
	GRAPH_EDGE *m = &mEdgeArr_Pool[ moveID ];
	m->dynamicID=e->dynamicID;
	removeEdgeFromNode( e, e->nodeID[0] );
	removeEdgeFromNode( e, e->nodeID[1] );
}

void GRAPH_SYSTEM::removeEdgeFromNode( const GRAPH_EDGE *e, int nodeID )
{
    GRAPH_NODE *n = &mNodeArr_Pool[ nodeID ];
	vector<int>::iterator i;
	for(i=n->edgeID.begin();i!=n->edgeID.end();){
		if(*i==e->id){
			n->edgeID.erase(i);
		}
		else{
			i++;
		}
	}
}
void GRAPH_SYSTEM::deleteEdgesOfNode( int nodeID )
{
    GRAPH_NODE *n  = &mNodeArr_Pool[ nodeID ];
	int size=n->edgeID.size();
	for(int i=0;i<size;i++){
		deleteEdge( n->edgeID[0] );
	}
	
	n->edgeID.clear();
}

void GRAPH_SYSTEM::deleteNode( int nodeID ) {
    if ( mCurNumOfActiveNodes <= 0 ) return;
	deleteEdgesOfNode( nodeID );
	mFreeNodeArr[ mCurNumOfFreeNodes ]=nodeID;
	mCurNumOfFreeNodes++;
	GRAPH_NODE *n = &mNodeArr_Pool[ nodeID ];
	int dynamicID = n->dynamicID;
	mCurNumOfActiveNodes--;
	int moveID=mActiveNodeArr[mCurNumOfActiveNodes];//ID
	mActiveNodeArr[dynamicID]=moveID;
	GRAPH_NODE *m = &mNodeArr_Pool[ moveID ];
	m->dynamicID=n->dynamicID;
}

void GRAPH_SYSTEM::deleteSelectedNode(  ) {
    if ( mSelectedNode == 0 ) return;
    deleteNode( mSelectedNode->id );
    deleteEdgesOfNode( mSelectedNode->id );
    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}

bool GRAPH_SYSTEM::isSelectedNode( ) const
{
    return mSelectedNode != 0;
}

void GRAPH_SYSTEM::getInfoOfSelectedPoint( double &r, vector3 &p ) const
{
    if ( isSelectedNode( ) == false ) return;
    r = mSelectedNode->r;
    p = mSelectedNode->p;

}



void GRAPH_SYSTEM::handleKeyPressedEvent( unsigned char key )
{
    
    switch( key ) {
    case 127: // delete
        mFlgAutoNodeDeletion = false;
        deleteSelectedNode( );
        break;
    case '1':
        mFlgAutoNodeDeletion = false;
        createDefaultGraph( );
        mSelectedNode = 0;
        break;
    case '2':
        mFlgAutoNodeDeletion = false;
        createNet_Circular(12, 3);
        mSelectedNode = 0;

        break;
    case '3':
        mFlgAutoNodeDeletion = false;
        createNet_Square(3, 11);
        mSelectedNode = 0;

        break;
    case '4':
        mFlgAutoNodeDeletion = false;
        createNet_RadialCircular(24);
        mSelectedNode = 0;

        break;
    case '5':
        mNumPoints_DoubleCircles = 24;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;
    case '<':
        mNumPoints_DoubleCircles--;
        if (mNumPoints_DoubleCircles<3) 
            mNumPoints_DoubleCircles = 3;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;
    case '>':
        mNumPoints_DoubleCircles++;
        if (mNumPoints_DoubleCircles> 36) 
            mNumPoints_DoubleCircles = 36;
        mFlgAutoNodeDeletion = false;
        createRandomGraph_DoubleCircles(mNumPoints_DoubleCircles);
        mSelectedNode = 0;
        break;

    case ' ':
        mFlgAutoNodeDeletion = false;
        mSelectedNode = 0;
        break;
    case 'd':
        mFlgAutoNodeDeletion = !mFlgAutoNodeDeletion;
        break;
    case 'e':
        mFlgAutoNodeDeletion = false;
        mSelectedNode = 0;
        exportGraph( GRAPH_FILE_NAME );
        break;
    }
}

void GRAPH_SYSTEM::handlePassiveMouseEvent( double x, double z )
{
    double cur_d2;
    GRAPH_NODE *n = findNearestNode( x, z, cur_d2 );
    if ( n == 0 ) return;
    if ( cur_d2 > n->r*n->r ) {
        mPassiveSelectedNode = 0;
        return;
    }
    mPassiveSelectedNode = n;
}

int GRAPH_SYSTEM::getNumOfNodes( ) const
{
    return mCurNumOfActiveNodes;
}

int GRAPH_SYSTEM::getNodeID( int nodeIndex ) const
{
    int nodeID = mActiveNodeArr[ nodeIndex ];
    return nodeID;
}

int GRAPH_SYSTEM::getNodeInfo( int nodeIndex, double &r, vector3 &p ) const
{
    int nodeID = mActiveNodeArr[ nodeIndex ];
    GRAPH_NODE *n = &mNodeArr_Pool[ nodeID ];
    r = n->r;
    p = n->p;
    return nodeID;
}

int GRAPH_SYSTEM::getNumOfEdges( ) const
{
    return mCurNumOfActiveEdges;
}

int GRAPH_SYSTEM::getEdgeID( int edgeIndex ) const
{
    int edgeID = mActiveEdgeArr[ edgeIndex ];
    return edgeID;
}

int GRAPH_SYSTEM::getNodeIDOfEdge( int edgeIndex, int nodeIndex ) const
{
    int edgeID = mActiveEdgeArr[ edgeIndex ];
    GRAPH_EDGE *e = &mEdgeArr_Pool[ edgeID ];
    return e->nodeID[ nodeIndex ];
}

vector3 GRAPH_SYSTEM::getNodePositionOfEdge( int edgeIndex, int nodeIndex ) const
{
	int nodeID =getNodeIDOfEdge( edgeIndex, nodeIndex );
	GRAPH_NODE *n = &mNodeArr_Pool[ nodeID ];
    vector3 p;
	p= n->p;
    return p;
}

void GRAPH_SYSTEM::stopAutoNodeDeletion()
{
    mFlgAutoNodeDeletion = false;
}

//
// For every frame, update( ) function is called.
//
// 
void GRAPH_SYSTEM::update( )
{
    if (!mFlgAutoNodeDeletion) {
     
        return;
    }
    if (mCurNumOfActiveNodes<=0) {
     mFlgAutoNodeDeletion = false;
        return;
    }
    Sleep(250);

	int id=mActiveNodeArr[mCurNumOfActiveNodes-1];
	deleteNode( id );
    deleteEdgesOfNode( id );

    mSelectedNode = 0;
    mPassiveSelectedNode = 0;
}

//
// Export each node to the file steam fObj
// node_ID x y z
// The work flow
//
// Get the number of nodes
// For each node do
//    Get the node ID of the node
//    Get the radius and position of the node
//    Save the node information to the file stream
//
// Return
//
void GRAPH_SYSTEM::emitNodes( std::fstream *fObj ) const
{
    vector3 p;
    int num = getNumOfNodes( );
	for(int i=0;i<getNumOfNodes( );i++){
		int id=mActiveNodeArr[i];
		p=mNodeArr_Pool[id].p;
		*fObj<<i<<"\t"<<p.nx<<"\t"<<p.ny<<"\t"<<p.nz<<"\n";
	}
}

//
// Export each edge to the file stream fObj
// edge_ID node0_ID node1_ID
//
// The work flow
//
// Get the number of edges
// For each edge do
//    Get the edge ID of the edge
//    Get the node ID of the first node of the edge
//    Get the node ID of the second node of the edge
//    Save the edge information to the file stream
//
// Return
//
void GRAPH_SYSTEM::emitEdges( std::fstream *fObj ) const
{
    int num = getNumOfEdges( );
	for(int i=0;i<num;i++){
		int id=mActiveEdgeArr[i];
		*fObj<<i<<"\t"<<mEdgeArr_Pool[id].nodeID[0]<<"\t"<<mEdgeArr_Pool[id].nodeID[1]<<"\n";
	}
}

//
// The work flow
// Create a file stream object or pointer, fObj
// Use fObj to open a file for text output
// Check if the file is opened successfully
// If the file cannot be opened, show an error message and return
// Otherwise, go on to process the following steps.
// Get the number of nodes, n
// Get the number of edges, m
// Save n to fObj
// Save m to fObj
// Call emitNodes
// Call emitEdges
// Close the file
// Delete the object fObj if necessary
// Show a message
//
void GRAPH_SYSTEM::exportGraph(const std::string &fileName) const
{
    cout << "BEGIN GRAPH_SYSTEM::exportGraph" << endl;

    //////////////////////////////////////
    // DO NOT DELETE THE FOLLOWING LINE
    mExport_Count_DrawingFX = Param::Export_Count_DrawingFX;
    //////////////////////////////////////

    cout << "Filename:" << fileName << endl;
    fstream *fObj = new fstream;
	fObj->open(fileName);
	*fObj<<"-------------------"<<"\n";
	*fObj<<getNumOfNodes( )<<"\n";
	*fObj<<getNumOfEdges( )<<"\n";
	*fObj<<"\n";
	emitNodes(fObj);
	*fObj<<"\n";
	emitEdges(fObj);
	*fObj<<"-------------------"<<"\n";
    cout << "END GRAPH_SYSTEM::exportGraph" << endl;
	fObj->close();

}

