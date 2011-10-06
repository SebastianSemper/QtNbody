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
#include <math.h>


using namespace std;

class NbPartikel:public QGraphicsItem{
	private:
		QPointF Position;
		QPointF Velocity;
		QPointF Force;
		double Radius;
				
	public:
	
	
		NbPartikel(QPointF, QPointF, double);
		~NbPartikel();
		void setPosition(QPointF);
		void setVelocity(QPointF);
		void setForce(QPointF);
		void setRadius(double);
		QPointF getPosition();
		QPointF getVelocity();
		QPointF getForce();
		double getRadius();
		
		friend double getDistance(NbPartikel *, NbPartikel *);
		
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);	

};
#endif
