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

void BalanceTrade::drawPointsBT(){
    
    glPushMatrix();
    glTranslatef(0, 20.8, 0);
    bh.drawPointsBH(0, 0);
    glPopMatrix();
    
    bs.drawPointsBS();
}

void BalanceTrade::drawEdgeBT(){
    
    glPushMatrix();
    glTranslatef(0, 20.8, 0);
    bh.drawEdgeBH(0, 0);
    glPopMatrix();
    
    bs.drawEdgeBS();
}

void BalanceTrade::drawSolidBT(){
    
    glPushMatrix();
    glTranslatef(0, 20.8, 0);
    bh.drawSolidBH(0, 0);
    glPopMatrix();
    
    bs.drawSolidBS();
}

void BalanceTrade::drawChessBT(){
    
    glPushMatrix();
    glTranslatef(0, 20.8, 0);
    bh.drawChessBH(0, 0);
    glPopMatrix();
    
    bs.drawChessBS();
}
