#include "gui.h"

using namespace std;


gui::gui(QMainWindow *parent) : QMainWindow(parent){
        //Methode, die die erstellte GUI läd und erstellt.
        setupUi(this);
        
        plane->setScene(&universe);
	plane->show();
	
	QTimer *timer = new QTimer(this);
     	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
     	timer->start(100);

}

//Destruktor der Klasse "GUI".
gui::~gui(){
	

}

void gui::update(){
	cout << "bam";
	universe.update_world();
}
	


