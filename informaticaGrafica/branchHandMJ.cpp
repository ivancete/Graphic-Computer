//
//  branchHandMJ.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 2/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "branchHandMJ.h"

BranchHandMJ::BranchHandMJ(){

    handmj = HandMJ::HandMJ();
    branchmj = BranchMJ::BranchMJ();
}

void BranchHandMJ::drawPointsBH(float angle, float angle1){
    
    glPushMatrix();
    glTranslatef(10, 0, 0);
    glRotatef(angle, 1, 0, 0);
    handmj.drawPointsHand();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-10, 0, 0);
    glRotatef(angle, 1, 0, 0);
    handmj.drawPointsHand();
    glPopMatrix();
    
    glPushMatrix();
    //glRotatef(angle1, 0, 1, 0);
    branchmj.drawPointsBranch();
    glPopMatrix();
}

void BranchHandMJ::drawEdgeBH(float angle, float angle1){
    
    glPushMatrix();
    glTranslatef(10, 0, 0);
    glRotatef(angle, 1, 0, 0);
    handmj.drawEdgeHand();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-10, 0, 0);
    glRotatef(angle, 1, 0, 0);
    handmj.drawEdgeHand();
    glPopMatrix();
    
    glPushMatrix();
    //glRotatef(angle1, 0, 1, 0);
    branchmj.drawEdgeBranch();
    glPopMatrix();
}

void BranchHandMJ::drawSolidBH(float angle, float angle1){
    
    glPushMatrix();
    glTranslatef(10, 0, 0);
    glRotatef(angle, 1, 0, 0);
    handmj.drawSolidHand();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-10, 0, 0);
    glRotatef(angle, 1, 0, 0);
    handmj.drawSolidHand();
    glPopMatrix();
    
    glPushMatrix();
    //glRotatef(angle1, 0, 1, 0);
    branchmj.drawSolidBranch();
    glPopMatrix();
}

void BranchHandMJ::drawChessBH(float angle, float angle1){
    
    glPushMatrix();
    glTranslatef(10, 0, 0);
    glRotatef(angle, 1, 0, 0);
    handmj.drawChessHand();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-10, 0, 0);
    glRotatef(angle, 1, 0, 0);
    handmj.drawChessHand();
    glPopMatrix();
    
    glPushMatrix();
    //glRotatef(angle1, 0, 1, 0);
    branchmj.drawChessBranch();
    glPopMatrix();
}
