#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include "scene.h"
#include <QTimer>


using namespace std; 
 
class gui : public QMainWindow, public Ui::MainWindow { 
	Q_OBJECT
	 
	public slots:
		
		
	public:
	    	gui(QMainWindow *parent = 0);
	    	~gui();
	private slots:
		
	private :
		void update();
		scene universe;		
};

#endif
