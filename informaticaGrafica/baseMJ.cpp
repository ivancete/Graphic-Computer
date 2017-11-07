//
//  baseMJ.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 2/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "baseMJ.h"

BaseMJ::BaseMJ(){
    cubo = Cubo::Cubo(2);
}

void BaseMJ::drawPointsBase(){
    glPushMatrix();
    glScalef(1, 0.2, 1);
    cubo.draw_points();
    glPopMatrix();
}

void BaseMJ::drawEdgeBase(){
    glPushMatrix();
    glScalef(1, 0.2, 1);
    cubo.draw_edges();
    glPopMatrix();
}

void BaseMJ::drawSolidBase(){
    glPushMatrix();
    glScalef(1, 0.2, 1);
    cubo.draw_solid();
    glPopMatrix();
}

void BaseMJ::drawChessBase(){
    glPushMatrix();
    glScalef(1, 0.2, 1);
    cubo.draw_chess();
    glPopMatrix();
}
