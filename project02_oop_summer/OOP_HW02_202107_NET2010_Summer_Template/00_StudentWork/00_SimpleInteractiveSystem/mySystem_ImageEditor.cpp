//
// Prof. Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2021/07/13
//
#include <iostream>
#include "mySystem_ImageEditor.h"

#define IMAGE_FILE_NAME "3d-flower-desktop.jpg"

#define IMAGE_MAX_HIERARCHY_DEPTH 8

IMAGE_SYSTEM::IMAGE_SYSTEM()
{
    mNumNodes = 0;
    m_ImageHierarchy = 0;
    m_Depth = 0;
    m_Image = new ns_opengl::Image;
    m_Image->readFile(IMAGE_FILE_NAME);

    int wImage, hImage;
        m_Image->getInfo(wImage, hImage);

    int cur_depth = 0;
        int start_x = 0;
    int start_y = 0;

        int w = wImage;
        int h = hImage;
        float sx = 2; 
        float sy = 2;

        float radius = wImage/2.0*(sx+sy)*0.5;

    m_ImageHierarchy = new IMAGE_NODE(
        cur_depth, 
        start_x,
        start_y,
        w,
        h,
        sx,
        sy,
        radius
        ); 
    float r, g, b;
    computeAverageColor(start_x, start_y, w, h, r, g, b);

    m_ImageHierarchy->setColor(r,g,b);
    m_ImageHierarchy->computeDrawPosition(
        wImage, hImage
        );

    countNodes( );
    //
}

void IMAGE_SYSTEM::reset(IMAGE_NODE *node)
{
    node->flg_explored = false;
}

void IMAGE_SYSTEM::reset()
{
    reset(m_ImageHierarchy);
}

void IMAGE_SYSTEM::handleKeyPressedEvent( unsigned char key )
{
    switch(key) {
    case 'r':
        reset();
        break;
    
    }
}

void IMAGE_SYSTEM::computeNodeColor(IMAGE_NODE *node)
{
    
    float r, g, b;
    computeAverageColor(
        node->start_x,
        node->start_y,
        node->w,
        node->h,
        r,
        g,
        b);
    node->setColor(r,g,b);
    
}

void IMAGE_SYSTEM::exploreImageNode(IMAGE_NODE *node, double x, double y)
{

    if (node->flg_explored) {
        for (int i =0; i <4; ++i) {
            exploreImageNode(node->children[i], x, y);//
        }
    } 
	else {
		if (node->w/2 ==0 || node->h/2 == 0){
			//node->flg_explored=false;
			return;
		}
        float dx = x - node->draw_x;
        float dy = y - node->draw_y;//
        float d2 = dx*dx + dy*dy;
        float r2 = node->radius*node->radius;
        if (d2 > r2) return;
        //
        node->flg_explored = true;
        if (node->children[0]) return;//

        int wImage, hImage;
        m_Image->getInfo(wImage, hImage);
        IMAGE_NODE *children[4];
        float radius = node->w/2.0;
        children[0] = new IMAGE_NODE(
            node->cur_depth+1, 
            node->start_x, 
            node->start_y,
            node->w/2, node->h/2, 
            node->sx, node->sy,
            radius
            );
        
        
        for (int i =0; i <4; ++i) {//
            computeNodeColor(children[i]);//
            children[i]->computeDrawPosition(//
            wImage, hImage
            );
            node->children[i] = children[i];//
        }
        
    }
}

void IMAGE_SYSTEM::handlePassiveMouseEvent( double x, double y )
{
    //std::cout << "IMAGE_SYSTEM Mouse:" << x << "\t" << y << std::endl;
    
    exploreImageNode(m_ImageHierarchy, x, y);
}

void IMAGE_SYSTEM::collapseImageNode(IMAGE_NODE *node)
{
    if (node ==0) return;
    node->flg_explored = false;
}

void IMAGE_SYSTEM::collapseImageNode(IMAGE_NODE *parent_node, IMAGE_NODE *node, double x, double y)
{
}

void IMAGE_SYSTEM::handleMotionMouseEvent( double x, double y )
{
    std::cout << "IMAGE_SYSTEM::handleMotionMouseEvent:" << x << "\t" << y << std::endl;
}

int IMAGE_SYSTEM::countNodes( const IMAGE_NODE *node) const
{
    int count = 0;
    if (node==0) {
    } else {


    }
    //std::cout << count << std::endl;

    return count;
}

int IMAGE_SYSTEM::countNodes( ) const
{
    return mNumNodes;
}

int IMAGE_SYSTEM::getNumberOfNodes( ) const
{
    return mNumNodes;
}
