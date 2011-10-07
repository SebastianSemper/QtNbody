#include "NbVis.h"

using namespace std;

NbVis::NbVis(int x,int y,int r,int g,int b){
	col.setRed(r);
	col.setGreen(g);
	col.setBlue(b);
	this->setPos(x,y);

}

void NbVis::setCol(int r,int g,int b){
	col.setRed(r);
	col.setGreen(g);
	col.setBlue(b);
}

NbVis::~NbVis(){}

QRectF NbVis::boundingRect() const{
	return QRectF(-20, -20, 20, 20);
}
void NbVis::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	painter->setRenderHint(QPainter::Antialiasing);
	
        painter->setBrush(col); 
        painter->setPen(col);        
        painter->drawRect(0,0,10,10);
}

