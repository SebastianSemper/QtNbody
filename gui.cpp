#include "gui.h"

using namespace std;


gui::gui(QMainWindow *parent) : QMainWindow(parent){
        //Methode, die die erstellte GUI läd und erstellt.
        setupUi(this);
        
        scene universe;
	plane->setScene(&universe);
	plane->show();

}

//Destruktor der Klasse "GUI".
gui::~gui(){
}


