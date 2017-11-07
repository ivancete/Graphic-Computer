//
//  stickMJ.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 2/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "stickMJ.h"

StickMJ::StickMJ(){
    
    vector<_vertex3f> cilindroV ={{0.5,-0.5,0},{0.5,0.5,0},{0,-0.5,0},{0,0.5,0}};
    cilindro = FiguraPly(cilindroV);
    cilindro.revolution(20);
}

void StickMJ::drawPointsStick(){
    
    glPushMatrix();
    glTranslatef(0, 10.4, 0);
    glScalef(1, 20, 1);
    cilindro.draw_points();
    glPopMatrix();
}

void StickMJ::drawEdgeStick(){
    
    glPushMatrix();
    glTranslatef(0, 10.4, 0);
    glScalef(1, 20, 1);
    cilindro.draw_edges();
    glPopMatrix();
}

void StickMJ::drawSolidStick(){
    
    glPushMatrix();
    glTranslatef(0, 10.4, 0);
    glScalef(1, 20, 1);
    cilindro.draw_solid();
    glPopMatrix();
}

void StickMJ::drawChessStick(){
    
    glPushMatrix();
    glTranslatef(0, 10.4, 0);
    glScalef(1, 20, 1);
    cilindro.draw_chess();
    glPopMatrix();
}

