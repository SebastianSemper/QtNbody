#include "scene.h"

using namespace std;

scene::scene(){
	for (int i = 0; i <= 20; i++){
		
		NbPartikel *neu = new NbPartikel(QPointF(rand()%400 - 200, rand()%400-200),QPointF(rand()%6 - 3, rand()%6-3),10);		
		
		neu->setPos(neu->getPosition());
		//neu->setPos(QPointF(0,0));
		this->addItem(neu);
		this->update();
		Partikel.append(neu);
		
	}
}

void scene::update_world(){
	for (int i = 0; i <= Partikel.size()-1; i++){
		Partikel[i]->setPosition(Partikel[i]->getPosition() +  Partikel[i]->getVelocity());
		Partikel[i]->setPos(Partikel[i]->getPosition());
		
	}
	this->update();
}

void scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
	
}

void scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){    	
	
}


