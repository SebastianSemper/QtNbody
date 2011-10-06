#include "scene.h"

using namespace std;

scene::scene(){
	update_intervall = 25;
	for (int i = 0; i <= 20; i++){
		
		NbPartikel *neu = new NbPartikel(QPointF(rand()%700 - 350, rand()%500-250),QPointF(rand()%60 - 30,rand()%60 - 30),rand()%15 + 5);		
		
		neu->setPos(neu->getPosition());
		//neu->setPos(QPointF(0,0));
		this->addItem(neu);
		this->update();
		this->setStickyFocus(FALSE);
		Partikel.append(neu);
		
	}
}

void scene::update_world(){
	for (int i = 0; i <= Partikel.size()-1; i++){
		
		QPointF pos = Partikel[i]->getPosition();
		double rad = Partikel[i]->getRadius();
		if (((pos + QPointF(+rad, 0)).x() > 400) || ((pos + QPointF(-rad, 0)).x() < -400)){
			Partikel[i]->setVelocity(QPointF(-Partikel[i]->getVelocity().x(),Partikel[i]->getVelocity().y()));
		}
		
		if (((pos + QPointF(0, +rad)).y() > 300) || ((pos + QPointF(0, -rad)).y() < -300)){
			Partikel[i]->setVelocity(QPointF(Partikel[i]->getVelocity().x(),-Partikel[i]->getVelocity().y()));
		}
		
		QPointF vel = (update_intervall/1000) * Partikel[i]->getVelocity();
		Partikel[i]->setPosition(Partikel[i]->getPosition() +  vel);
		Partikel[i]->setPos(Partikel[i]->getPosition());
		
		
		
	}
	this->update();
}

void scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
	
}

void scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){    	
	
}


