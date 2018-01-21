#include <qmainwindow.h>
#include <qmessagebox.h>
//#include <qpopupmenu.h>
#include <QMenu>
#include <qmenubar.h>
#include <qapplication.h>
#include <qpixmap.h>
#include <paint.h>


#ifndef _MY_WIDGET_H
#define _MY_WIDGET_H

class MyMainWindow: public QMainWindow {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT

	public:
    MyMainWindow(QWidget* parent = 0, const char *name=0);
    ~MyMainWindow();



    /* mouse event handler */
    //void mousePressEvent (QMouseEvent *);

    /* paint handler */
    // void paintEvent(QPaintEvent *);

private slots:
	void OnLoadImage();
    void create();
    void save();
    void quit();
    bool saveFile();
    void undo();
    void redo();
    void clrCanvas();
    void changeForegroundColor();
    void changeBackgroundColor();

    void penProp();
    void lineProp();
    void eraserProp();
    void rectangleProp();
    void lineSet();
    void rectSet();
    void penSet();
    void eraser();
    void resize();
private:

    PaintDraw *paintDraw= new PaintDraw();
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *toolMenu;
    QActionGroup *alignmentGroup;
    QAction *newImageAct;
    QAction *saveImageAct;
    QAction  *loadImageAct;
    QAction *quitAct;

    QAction *undoAct;
    QAction *redoAct;
    QAction *clrAct;
    QAction *bgChangeAct;
    QAction *fgChangeAct;

    QAction *linePropAct;
    QAction *penPropAct;
    QAction *eraserPropAct;
    QAction *rectPropAct;
    void createActions();
    void createMenus();


};

#endif
