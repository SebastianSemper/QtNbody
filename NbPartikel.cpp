#include "NbPartikel.h"

using namespace std;

const double G = 6.6738480E3;

NbPartikel::NbPartikel(QPointF Pos, QPointF Vel, double Rad, double m){
	Position = Pos;
	Velocity = Vel;
	Radius = Rad;
	Mass = m;
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

double NbPartikel::getMass(){
	return Mass;
}

QPointF NbPartikel::getAcceleration(){
        return Acceleration;
}

QPointF NbPartikel::getForce(){
        return Force;
}

void NbPartikel::setPosition(QPointF pos){
	Position = pos;
	this->setPos(Position);
}

void NbPartikel::setAcceleration(QPointF a){
        Acceleration = a;
}

void NbPartikel::setForce(QPointF f){
        Force = f;
}

void NbPartikel::setVelocity(QPointF vel){
	Velocity = vel;
}

void NbPartikel::setMass(double m){
	Mass = m;
}

double getDistance( NbPartikel * x, NbPartikel * y){
	return sqrt((x->Position.x()-y->Position.x())*(x->Position.x()-y->Position.x()) + (x->Position.y()-y->Position.y())*(x->Position.y()-y->Position.y()));
}

QRectF NbPartikel::boundingRect() const{
	return QRectF(-20, -20, 20, 20);
}
void NbPartikel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
	painter->setRenderHint(QPainter::Antialiasing);
	
        painter->setBrush(Qt::gray);
        
        painter->drawEllipse(-Radius/2, -Radius/2, Radius, Radius);
        
        painter->setPen(Qt::red);
        painter->drawLine(QPointF(0,0), 0.5*Velocity);
        
        painter->setPen(Qt::blue);
        painter->drawLine(QPointF(0,0), -0.0005*Force);
        
}

double qpsp(QPointF a, QPointF b){
	double s;
	s = a.x()*b.x()+a.y()*b.y();
	return s;
}

void NbPartikel::afterImpact(NbPartikel *p){
	double m2 = p->getMass();
	QPointF p2 = p->getPosition(), v2 = p->getVelocity(), v1p, v1o, v2p, v2o, mz = Position - p->getPosition();
	
	/*if((mz.x() == 0) && (mz.y() == 0)){
		Position = Position + QPointF(10,10);
		p->setPosition(p->getPosition() + QPointF(10,10));
		mz = Position - p->getPosition();
	}*/
	
	QPointF v1pafter, v2pafter, tmp1 = mz/qpsp(mz, mz), v2after;
	
	v1p = qpsp(Velocity, mz)*tmp1;
	v2p = qpsp(v2, mz)*tmp1;
	v1o = Velocity - v1p;
	v2o = v2 - v2p;
	
	QPointF tmp2 = 2/(Mass+p->getMass())*(Mass*v1p+m2*v2p);
	
	v1pafter = tmp2 - v1p;
	v2pafter = tmp2 - v2p;
	
	/*cout << " - impact - " << endl;
	cout << tmp1.x() << " - " << tmp1.y() << endl;
	cout << v1o.x() << " - " << v1o.y() << endl;
	cout << tmp2.x() << " - " << tmp2.y() << endl;
	cout << v1pafter.x() << " - " << v1pafter.y() << endl;
	cout << mz.x() << " - " << mz.y() << endl;
	cout << Velocity.x() << " - " << Velocity.y() << endl;*/
	
	Velocity = v1o + v1pafter;
	p->setVelocity(v2o + v2pafter);
}

void NbPartikel::gravity(QList<NbPartikel*> p){
        Force.setX(0); Force.setY(0);
        for(int i = 0; i < p.size(); i++){
                QPointF diff = Position - p[i]->getPosition();
                if((diff.x() != 0) && (diff.y() != 0)){
                        Force += G*Mass*p[i]->getMass()*1.0/pow(qpsp(diff,diff),3.0/2.0)*diff;
                }
        }
        if(pow(qpsp(Force,Force), 0.5) > 100000){
                Force *= 100000/pow(qpsp(Force,Force), 0.5);
        }
}
