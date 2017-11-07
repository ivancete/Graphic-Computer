//
//  branchMJ.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 2/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "branchMJ.h"

BranchMJ::BranchMJ(){
    
    vector<_vertex3f> tuboV ={{0.5,-0.5,0},{0.5,0.5,0}};
    tubo = FiguraPly(tuboV);
    tubo.revolution(20);
}

void BranchMJ::drawPointsBranch(){
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    glScalef(1, 20, 1);
    tubo.draw_points();
    glPopMatrix();
}

void BranchMJ::drawEdgeBranch(){
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    glScalef(1, 20, 1);
    tubo.draw_edges();
    glPopMatrix();
}

void BranchMJ::drawSolidBranch(){
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    glScalef(1, 20, 1);
    tubo.draw_solid();
    glPopMatrix();
}

void BranchMJ::drawChessBranch(){
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    glScalef(1, 20, 1);
    tubo.draw_chess();
    glPopMatrix();
}
