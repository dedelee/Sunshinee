//
//  MyDrawNode.cpp
//  First2DXPro
//
//  Created by mac on 15-3-16.
//
//

#include "MyDrawNode.h"

void MyDrawNode::onDraw(const cocos2d::Mat4 &transform, uint32_t flags)
{
    
    Size s(20,20);
    
    //绘制直线
    glLineWidth(5);
    glColorMask(255, 0, 0, 255);
    DrawPrimitives::drawLine(Vec2(240,240),Vec2(s.width,s.height));
    
    //绘制圆形
    glLineWidth(2);
    glColorMask(0, 255, 0, 255);
    DrawPrimitives::drawCircle(Point(s.width/2, s.height/2), 50, CC_DEGREES_TO_RADIANS(90),100, true, 1, 1);
    
    //绘制点
    Vec2 points[4]={Vec2(60,60),Vec2(70,70), Vec2(60,70),Vec2(70,60)};
    DrawPrimitives::setPointSize(4);
    glColorMask(0, 0, 255, 255);
    DrawPrimitives::drawPoints (points,4);
    
    //绘制多边形
    glLineWidth(2);
    Vec2 vertices2[3]={Vec2(30,130),Vec2(30,230),Vec2(50,200)};
    DrawPrimitives::drawPoly(vertices2, 3, true);
    
    
    
    
    
    
    //画贝塞尔曲线
    // 函数的第一个参数为一个控制点；第二个和第三个参数为两个控制点；最后一个参数为分段线，代码如下：
    
    DrawPrimitives::drawQuadBezier(Point(0,s.height), Point(s.width/2,s.height/2), Point(s.width,s.height), 50);
    
    
    
    DrawPrimitives::drawCubicBezier(Point(s.width/2,s.height/2), Point(s.width/2+30,s.height/2+50),
                                    Point(s.width/2+60,s.height/2-50), Point(s.width,s.height/2), 100);
    
    

}

void MyDrawNode::draw(cocos2d::Renderer *renderer,const cocos2d::Mat4& transform,uint32_t flags)
{
    /*从Cocos2d-x 3.0开始，Cocos2d-x引入了新的渲染流程，它不像2.x版本直接在每一个node中的draw函数中直接调用OpenGL代码进行图形渲染，而是通过各种RenderCommand封装起来，然后添加到一个CommandQueue队列里面去，而现在draw函数的作用就是在此函数中设置好相对应的RenderCommand参数，然后把此RenderCommand添加到CommandQueue中。最后在每一帧结束时调用renderer函数进行渲染，在renderer函数中会根据ID对RenderCommand进行排序，然后才进行渲染。*/
    //
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(MyDrawNode::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);
}


