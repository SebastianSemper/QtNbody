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
		double Mass;
				
	public:
	
	
		NbPartikel(QPointF, QPointF, double, double);
		~NbPartikel();
		void setPosition(QPointF);
		void setVelocity(QPointF);
		void setForce(QPointF);
		void setRadius(double);
		void setMass(double);
		QPointF getPosition();
		QPointF getVelocity();
		QPointF getForce();
		double getRadius();
		double getMass();
		
		friend double getDistance(NbPartikel *, NbPartikel *);
		void afterImpact(NbPartikel*);
		friend double qpsp(QPointF, QPointF);
		
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);	

};
#endif
