#include "gui.h"

using namespace std;


gui::gui(QMainWindow *parent) : QMainWindow(parent){
        //Methode, die die erstellte GUI läd und erstellt.
        setupUi(this);

}

//Destruktor der Klasse "GUI".
gui::~gui(){
}


