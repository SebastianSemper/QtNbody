#include "scene.h"

using namespace std;

scene::scene(){
	for (int i = 0; i <= 20; i++){
		QPointF pos(rand()%200 - 100, rand()%200-100);
		cout << pos.x() << "/" << pos.y() << endl;
		NbPartikel *neu = new NbPartikel(QPointF(rand()%10 - 5, rand()%10-5),QPointF(rand()%6 - 3, rand()%6-3),10);		
		
		neu->setPos(neu->getPosition());
		this->addItem(neu);
		this->update();
		Partikel.append(neu);
		
	}
}

void scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
	
}

void scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){    	
	
}


