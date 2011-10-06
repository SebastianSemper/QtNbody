#include "NbPartikel.h"

using namespace std;

NbPartikel::NbPartikel(QPointF Pos, QPointF Vel, double Rad){
	Position = Pos;
	Velocity = Vel;
	Radius = Rad;
}

NbPartikel::~NbPartikel(){

}

QPointF NbPartikel::getPosition(){
	return Position;
}

QPointF NbPartikel::getVelocity(){
	return Velocity;
}

double NbPartikel::getRadius(){
	return Radius;
}

void NbPartikel::setPosition(QPointF pos){
	Position = pos;
}

void NbPartikel::setVelocity(QPointF vel){
	Velocity = vel;
}

double getDistance( NbPartikel * x, NbPartikel * y){
	return sqrt((x->Position.x()-y->Position.x())*(x->Position.x()-y->Position.x()) + (x->Position.y()-y->Position.y())*(x->Position.y()-y->Position.y()));
}

QRectF NbPartikel::boundingRect() const{
	return QRectF(-20, -20, 20, 20);
}
void NbPartikel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	painter->setRenderHint(QPainter::Antialiasing);
	
        painter->setBrush(Qt::black);        
        
        painter->drawEllipse(-Radius/2, -Radius/2, Radius, Radius);
}


