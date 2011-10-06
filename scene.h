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

class scene:public QGraphicsScene{
	private:
		QList<NbPartikel *> Partikel;
			
	public:
		double update_intervall;
		scene();
		void update_world();
		//~scene();
		void mousePressEvent(QGraphicsSceneMouseEvent *event);
		void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
		

};
#endif
