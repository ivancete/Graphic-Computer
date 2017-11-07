//
//  baseStickMJ.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 2/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "baseStickMJ.h"

BaseStickMJ::BaseStickMJ(){
    stick = StickMJ::StickMJ();
    base = BaseMJ::BaseMJ();
}

void BaseStickMJ::drawPointsBS(){
    
    glPushMatrix();
    stick.drawPointsStick();
    base.drawPointsBase();
    glPopMatrix();
}

void BaseStickMJ::drawEdgeBS(){
    
    glPushMatrix();
    stick.drawEdgeStick();
    base.drawEdgeBase();
    glPopMatrix();
}

void BaseStickMJ::drawSolidBS(){
    
    glPushMatrix();
    stick.drawSolidStick();
    base.drawSolidBase();
    glPopMatrix();
}

void BaseStickMJ::drawChessBS(){
    
    glPushMatrix();
    stick.drawChessStick();
    base.drawChessBase();
    glPopMatrix();
}
