#include "scene.h"

using namespace std;

scene::scene(){
	update_intervall = 25;
	grid_size = 10;
	
	this->	addRect(-400,-300,800,600);
	//this->	addRect(0,0,3,3);
	
	/*for (int i = 0; i < 800/grid_size; i++){
		for (int j = 0; j < 600/grid_size; j++){			
			NbVis * neu; neu = new NbVis(i*grid_size-400,j*grid_size-300,255,255,255);
			this->addItem(neu);
			vis.append(neu);
		}	
	}*/
	for (int i = 0; i <= 199; i++){
		int rm = rand()%9+1;
		NbPartikel *neu = new NbPartikel(QPointF(rand()%700 - 350, rand()%500-250),QPointF(0, 0), rm, rm);
		
		neu->setPos(neu->getPosition());
		//neu->setPos(QPointF(0,0));
		//this->addEllipse(neu->getPosition().x(),neu->getPosition().y(),1,1);
		this->addItem(neu);
		this->update();
		this->setStickyFocus(FALSE);
		Partikel.append(neu);		
	}
	
}

kd_tree scene::create_tree(kd_tree * baum, int n = 1){	
	
	baum->l = new kd_tree;
	baum->r = new kd_tree;
	if (n < 7){
		if (n % 2 == 0){
			baum->pos.setX(baum->pos.x()/2);
			for (int i = 0; i < baum->liste.size(); i++){
				if (baum->liste[i]->getPosition().x() + 400 <= baum->pos.x()){
					baum->l->liste.append(baum->liste[i]);
				}
				else{
					baum->r->liste.append(baum->liste[i]);
				}
			}
		}
		else{
			baum->pos.setY(baum->pos.y()/2);
			for (int i = 0; i < baum->liste.size(); i++){
				if (baum->liste[i]->getPosition().y() + 300 <= baum->pos.y()){
					baum->l->liste.append(baum->liste[i]);
				}
				else{
					baum->r->liste.append(baum->liste[i]);
				}
			}
			
		}
		baum->l->pos = baum->pos;
		baum->r->pos = baum->pos;
		return create_tree(baum->l, ++n);
		return create_tree(baum->r, ++n);
	}
	else{
		return *baum;	
	}
	
	
}

QList<NbPartikel *> scene::find_list(QPointF pos, kd_tree * baum, int n = 1){
	if (n < 6){
		if (n % 2 == 0){
			if (pos.x() + 400 <= baum->pos.x()){
				return find_list(pos,baum->l,++n);
			}
			else{
				return find_list(pos,baum->r,++n);
			}
		}
		else{
			if (pos.y() + 300  <= baum->pos.y()){
				return find_list(pos,baum->l,++n);
			}
			else{
				return find_list(pos,baum->r,++n);
			}
		}
		//return create_tree(baum->l, ++n);
		//return create_tree(baum->r, ++n);
	}
	else{
		return baum->liste;
	}

}

void scene::update_world(){
	
	/*int n = 0;
	for (int i = 0; i < 800/grid_size; i++){
		for (int j = 0; j < 600/grid_size; j++){			
			NbPartikel grid(QPoint(i*grid_size-400,j*grid_size-300), QPoint(0,0), 1, 100);
			
			grid.gravity(Partikel);
			int value = sqrt(grid.getForce().x()*grid.getForce().x()+grid.getForce().y()*grid.getForce().y());
			//cout << value << " - " << (1.0/value*255) << endl;
			//i*grid_size-400
			//j*grid_size-300
			int color = 1.0/value*255;
			if(color >= 255){color = 255;}
			if(color <= 0){color = 255;}
			vis[n]->setCol(255, color, color);
			n++;
		}	
	}*/
	
	for (int i = 0; i <= Partikel.size()-1; i++){
	        
	        Partikel[i]->gravity(Partikel);
                Partikel[i]->setAcceleration(Partikel[i]->getForce()/Partikel[i]->getMass());
                //Partikel[i]->setAcceleration(QPointF(0,0));
                Partikel[i]->setVelocity(Partikel[i]->getVelocity()-(update_intervall/1000)*(update_intervall/1000)*Partikel[i]->getAcceleration());
	}
	
	/*
	kd_tree *tree = new kd_tree;
	tree->liste = Partikel;
	tree->pos.setX(400);
	tree->pos.setY(300);
	create_tree(tree);
	*/	
	QList<NbPartikel *> Coll_List = Partikel;
	while(Coll_List.size() > 1){
		for (int i = 0; i <= Coll_List.size()-1; i++){		
			
			for (int j = 0; j <= Coll_List.size()-1; j++){
				if (i != j){
					if (getDistance(Coll_List[i],Coll_List[j]) <= ((Coll_List[i]->getRadius()+Coll_List[j]->getRadius()))/2){
						
						//QPointF tmp = Coll_List[i]->getPosition() - Coll_List[j]->getPosition();
						
						Coll_List[i]->setPosition(Coll_List[i]->getPosition()-2*(update_intervall/1000)*Coll_List[i]->getVelocity());
						Coll_List[j]->setPosition(Coll_List[j]->getPosition()-2*(update_intervall/1000)*Coll_List[j]->getVelocity());
						
						Coll_List[i]->afterImpact(Coll_List[j]);
						
						//Coll_List[i]->setVelocity(QPointF(0,0));
						//Coll_List[j]->setVelocity(QPointF(0,0));
					}
				}
			}
			Coll_List.removeAt(i);		
		}
	}
	
	
	
	for (int i = 0; i <= Partikel.size()-1; i++){		
		QPointF pos = Partikel[i]->getPosition();
		double rad = Partikel[i]->getRadius()/2;
		if (((pos + QPointF(+rad, 0)).x() > 400) || ((pos + QPointF(-rad, 0)).x() < -400)){
			/*if ((pos + QPointF(+rad, 0)).x() > 400){
				Partikel[i]->setPosition(QPointF(400-rad-1,pos.y()));
			}
			else{
				Partikel[i]->setPosition(QPointF(-400+rad+1,pos.y()));
			}*/		
			Partikel[i]->setPosition(Partikel[i]->getPosition()-1*(update_intervall/1000)*Partikel[i]->getVelocity());	
			Partikel[i]->setVelocity(QPointF(-Partikel[i]->getVelocity().x(),Partikel[i]->getVelocity().y()));
		}
		
		if (((pos + QPointF(0, +rad)).y() > 300) || ((pos + QPointF(0, -rad)).y() < -300)){
			/*if ((pos + QPointF(+rad, 0)).x() > 300){
				Partikel[i]->setPosition(QPointF(pos.x(),300-rad-1));
			}
			else{
				Partikel[i]->setPosition(QPointF(pos.x(),-300+rad+1));
			}*/
			Partikel[i]->setPosition(Partikel[i]->getPosition()-1*(update_intervall/1000)*Partikel[i]->getVelocity());
			Partikel[i]->setVelocity(QPointF(Partikel[i]->getVelocity().x(),-Partikel[i]->getVelocity().y()));
		}
		
		
		QPointF vel = (update_intervall/1000) * (Partikel[i]->getVelocity());
		//Partikel[i]->setVelocity(vel);
		Partikel[i]->setPosition(Partikel[i]->getPosition() +  vel);
		//this->addEllipse(Partikel[i]->getPosition().x(), Partikel[i]->getPosition().y(),1,1);
		Partikel[i]->setPos(Partikel[i]->getPosition());		
	}
	
	
	
	this->update();
}

void scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
	
}

void scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){    	
	
}


