#include "NbPartikel.h"

using namespace std;

NbPartikel::NbPartikel(QPointF Vel, QPointF Ma, double rad){
	
}

NbPartikel::~NbPartikel(){

}

QRectF NbPartikel::boundingRect() const{
	return QRectF(-20, -20, 20, 20);
}
void NbPartikel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	painter->setRenderHint(QPainter::Antialiasing);
	
        painter->setBrush(Qt::black);        
        
        painter->drawEllipse(-Radius/2, -Radius/2, Radius, Radius);
}


