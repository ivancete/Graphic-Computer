//
//  balanceTrade.cpp
//  informaticaGrafica
//
//  Created by Iván Rodríguez Millán on 7/11/17.
//  Copyright © 2017 Iván Rodríguez Millán. All rights reserved.
//

#include "balanceTrade.h"

BalanceTrade::BalanceTrade(){
    bh = BranchHandMJ::BranchHandMJ();
    bs = BaseStickMJ::BaseStickMJ();
}

void BalanceTrade::drawPointsBT(float angle1, float angle2, float translation){
    
    glPushMatrix();
    glTranslatef(0, translation, 0);
    glRotatef(angle1, 0, 1, 0);
    bh.drawPointsBH(angle1, angle2);
    glPopMatrix();
    
    bs.drawPointsBS();
}

void BalanceTrade::drawEdgeBT(float angle1, float angle2, float translation){
    
    glPushMatrix();
    glTranslatef(0, translation, 0);
    glRotatef(angle1, 0, 1, 0);
    bh.drawEdgeBH(angle1, angle2);
    glPopMatrix();
    
    bs.drawEdgeBS();
}

void BalanceTrade::drawSolidBT(float angle1, float angle2, float translation){
    
    glPushMatrix();
    glTranslatef(0, translation, 0);
    glRotatef(angle1, 0, 1, 0);
    bh.drawSolidBH(angle1, angle2);
    glPopMatrix();
    
    bs.drawSolidBS();
}

void BalanceTrade::drawChessBT(float angle1, float angle2, float translation){
    
    glPushMatrix();
    glTranslatef(0, translation, 0);
    glRotatef(angle1, 0, 1, 0);
    bh.drawChessBH(angle1, angle2);
    glPopMatrix();
    
    bs.drawChessBS();
}
