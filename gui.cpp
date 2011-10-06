#include "gui.h"

using namespace std;


gui::gui(QMainWindow *parent) : QMainWindow(parent){
        
        setupUi(this);
        
        plane->setScene(&universe);
        plane->centerOn(0,0);
	plane->show();
	
	QTimer *timer = new QTimer(this);
     	connect(timer, SIGNAL(timeout()), this, SLOT(update_gui()));
     	timer->start(universe.update_intervall);

}


gui::~gui(){
	

}

void gui::update_gui(){
	universe.update_world();
}
	


