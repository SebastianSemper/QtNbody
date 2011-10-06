#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsItem>
#include <QList>
#include <QPointF>
#include <QRectF>
#include <QPolygonF>
#include <QPainter>
#include <QPainterPath>
#include <QWidget>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "NbPartikel.h"


using namespace std;

struct kd_tree{
	QPointF pos;
	kd_tree *l;
	kd_tree *r;
	QList<NbPartikel *> liste;
};

class scene:public QGraphicsScene{
	private:
		QList<NbPartikel *> Partikel;
		
		kd_tree create_tree(kd_tree *,int);
		QList<NbPartikel *> find_list(QPointF, kd_tree *, int);
		
	public:
		
		double update_intervall;
		scene();
		void update_world();
		//~scene();
		void mousePressEvent(QGraphicsSceneMouseEvent *event);
		void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
		

};
#endif
