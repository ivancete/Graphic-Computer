//
//  handMJ.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 2/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "handMJ.h"

HandMJ::HandMJ(){
    
    vector<_vertex3f> cilindroV ={{0.5,-0.5,0},{0.5,0.5,0},{0,-0.5,0},{0,0.5,0}};
    vector<_vertex3f> vasoV ={{0.25,-0.5,0},{0.5,0.5,0},{0,-0.5,0}};
    
    cilindro_1 = FiguraPly(cilindroV);
    cilindro_1.revolution(20);
    
    vaso = FiguraPly(vasoV);
    vaso.revolution(20);
}

void HandMJ::drawPointsHand(){
    
    glPushMatrix();
    glTranslatef(0, -11, 0);
    glScalef(8, 4, 6);
    vaso.draw_points();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(20, 0, 0, 1);
    glTranslatef(0, -5, 0);
    glScalef(1, 10, 1);
    cilindro_1.draw_points();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glTranslatef(0, -5, 0);
    glScalef(1, 10, 1);
    cilindro_1.draw_points();
    glPopMatrix();
}

void HandMJ::drawEdgeHand(){
    
    glPushMatrix();
    glTranslatef(0, -11, 0);
    glScalef(8, 4, 6);
    vaso.draw_edges();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(20, 0, 0, 1);
    glTranslatef(0, -5, 0);
    glScalef(1, 10, 1);
    cilindro_1.draw_edges();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glTranslatef(0, -5, 0);
    glScalef(1, 10, 1);
    cilindro_1.draw_edges();
    glPopMatrix();
}

void HandMJ::drawSolidHand(){

    glPushMatrix();
    glTranslatef(0, -11, 0);
    glScalef(8, 4, 6);
    vaso.draw_solid();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(20, 0, 0, 1);
    glTranslatef(0, -5, 0);
    glScalef(1, 10, 1);
    cilindro_1.draw_solid();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glTranslatef(0, -5, 0);
    glScalef(1, 10, 1);
    cilindro_1.draw_solid();
    glPopMatrix();
}

void HandMJ::drawChessHand(){
    
    glPushMatrix();
    glTranslatef(0, -11, 0);
    glScalef(8, 4, 6);
    vaso.draw_chess();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(20, 0, 0, 1);
    glTranslatef(0, -5, 0);
    glScalef(1, 10, 1);
    cilindro_1.draw_chess();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(-20, 0, 0, 1);
    glTranslatef(0, -5, 0);
    glScalef(1, 10, 1);
    cilindro_1.draw_chess();
    glPopMatrix();
}
