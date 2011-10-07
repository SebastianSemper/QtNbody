#ifndef NBVIS_H
#define NBVIS_H

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

class NbVis:public QGraphicsItem{
	private:
		QColor col;
				
	public:
	
		void setCol(int,int,int);
		NbVis(int,int,int,int,int);
		~NbVis();
		
		QRectF boundingRect() const;
		void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);	

};
#endif
