#ifndef NBPARTIKEL_H
#define NBPARTIKEL_H

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


using namespace std;

class NbPartikel:public QGraphicsItem{
	private:
		QPointF Velocity;
		QPointF Force;
		double Radius;
				
	public:
		NbPartikel(QPointF, QPointF, double);
		~NbPartikel();
		void setVelocity(QPointF);
		void setForce(QPointF);
		void setRadius(double);
		QPointF getVelocity();
		QPointF getForce();
		double getRadius();
		
		
		

};
#endif
