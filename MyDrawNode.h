//
//  MyDrawNode.h
//  First2DXPro
//
//  Created by mac on 15-3-16.
//
//

#ifndef __First2DXPro__MyDrawNode__
#define __First2DXPro__MyDrawNode__
//hsahsaoihoihcc
#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class MyDrawNode:public Node
{
public:
    CREATE_FUNC(MyDrawNode);
    
    
    CustomCommand _customCommand;
    void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);

};


#endif /* defined(__First2DXPro__MyDrawNode__) */
