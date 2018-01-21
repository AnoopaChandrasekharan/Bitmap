#include <iostream>
#include <qfiledialog.h>
#include <qpainter.h>
#include <qmessagebox.h>
#include <QMenuBar>
#include <QLabel>
#include <QVBoxLayout>
#include <QIcon>
#include <QToolButton>
#include <QToolBar>
#include <QWidget>
#include <QVBoxLayout>
#include <QColor>
#include<QImage>
#include<QRgb>
#include<QSize>
#include<QMoveEvent>
#include "my_widget.h"



using namespace std;

MyMainWindow::MyMainWindow(QWidget* parent, const char* name)
:QMainWindow(parent)
{
    name="Paint";
    QWidget::setWindowTitle(name);
    createActions();
    createMenus();
    setCentralWidget(paintDraw);

    QToolBar *toolBar= new QToolBar("toolBar", this);
    QToolButton *button0 = new QToolButton;
    button0->setIcon(QIcon(":/icon/open_icon.bmp"));
    connect(button0,SIGNAL(clicked()),this,SLOT(OnLoadImage()));
    QToolButton *button1 = new QToolButton;
    button1->setIcon(QIcon(":/icon/new_icon.bmp"));
    connect(button1,SIGNAL(clicked()),this,SLOT(create()));
    QToolButton *button2 = new QToolButton;
    button2->setIcon(QIcon(":/icon/save_icon.bmp"));
    connect(button2,SIGNAL(clicked()),this,SLOT(saveFile()));
    QToolButton *button3 = new QToolButton;
    button3->setIcon(QIcon(":/icon/clearall_icon.bmp"));
    connect(button3,SIGNAL(clicked()),this,SLOT(clrCanvas()));
    QToolButton *button4 = new QToolButton;
    button4->setIcon(QIcon(":/icon/bcolor_icon.bmp"));
    connect(button4,SIGNAL(clicked()),this,SLOT(changeBackgroundColor()));
    QToolButton *button5 = new QToolButton;
    button5->setIcon(QIcon(":/icon/fcolor_icon.bmp"));
    connect(button5,SIGNAL(clicked()),this,SLOT(changeForegroundColor()));
    QToolButton *button6 = new QToolButton;
    button6->setIcon(QIcon(":/icon/redo_icon.bmp"));
    connect(button6,SIGNAL(clicked()),this,SLOT(redo()));
    QToolButton *button7 = new QToolButton;
    button7->setIcon(QIcon(":/icon/undo_icon.bmp"));
    connect(button7,SIGNAL(clicked()),this,SLOT(undo()));
    QToolButton *button8 = new QToolButton;
    button8->setIcon(QIcon(":/icon/line_icon.bmp"));
    connect(button3,SIGNAL(clicked()),this,SLOT(lineSet()));
    QToolButton *button9 = new QToolButton;
    button9->setIcon(QIcon(":/icon/rect_icon.bmp"));
    connect(button9,SIGNAL(clicked()),this,SLOT(rectSet()));
    QToolButton *button10 = new QToolButton;
    button10->setIcon(QIcon(":/icon/eraser_icon.bmp"));
    connect(button10,SIGNAL(clicked()),this,SLOT(eraser()));
    QToolButton *button11 = new QToolButton;
    button11->setIcon(QIcon(":/icon/pen_icon.bmp"));
    connect(button11,SIGNAL(clicked()),this,SLOT(penSet()));
    QToolButton *button12 = new QToolButton;
    button12->setIcon(QIcon(":/icon/resize_icon.bmp"));
    connect(button11,SIGNAL(clicked()),this,SLOT(resize()));
    toolBar->addWidget(button0);
    toolBar->addSeparator();
    toolBar->addWidget(button1);
    toolBar->addSeparator();
    toolBar->addWidget(button2);
    toolBar->addSeparator();
    toolBar->addWidget(button3);
    toolBar->addSeparator();
    toolBar->addWidget(button4);
    toolBar->addSeparator();
    toolBar->addWidget(button5);
    toolBar->addSeparator();
    toolBar->addWidget(button6);
    toolBar->addSeparator();
    toolBar->addWidget(button7);
    toolBar->addSeparator();
    toolBar->addWidget(button8);
    toolBar->addSeparator();
    toolBar->addWidget(button9);
    toolBar->addSeparator();
    toolBar->addWidget(button10);
    toolBar->addSeparator();
    toolBar->addWidget(button11);
    toolBar->addSeparator();
    toolBar->addWidget(button12);


}


void MyMainWindow::clrCanvas()
{
    paintDraw->clearImage();

}
void MyMainWindow::create()
{

}
void MyMainWindow::save()
{
    /*QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat =new QByteArray();
            fileFormat= action->data().toByteArray();
    saveFile(fileFormat); */

}
bool MyMainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"),
                               "/home",
                               tr("BMP(*.bmp)"));
    if (fileName.isEmpty()) {
        return false;
    } else {
        if(!fileName.contains(".bmp")){
            fileName = fileName.append(".bmp");
        }
        return paintDraw->saveImage(fileName, "BMP");
    }
}
void MyMainWindow::lineSet()
{
    paintDraw->setShape(paintDraw->Line);
}
void MyMainWindow::rectSet()
{
     paintDraw->setShape(paintDraw->Rect);
}
void MyMainWindow::eraser()
{
    //paintDraw->erasePoint(paintDraw->);
}
void MyMainWindow::penSet()
{}
void MyMainWindow::resize()
{
  //QMouseEvent *event;

 // paintDraw->resizeEvent(&event);

}
void MyMainWindow::quit()
{}
void MyMainWindow::undo()
{}
void MyMainWindow::redo()
{}
void MyMainWindow::changeBackgroundColor()
{}
void MyMainWindow::changeForegroundColor()
{}
void MyMainWindow::penProp()
{}
void MyMainWindow::lineProp()
{}
void MyMainWindow::eraserProp()
{}
void MyMainWindow::rectangleProp()
{}
void MyMainWindow::createActions()
{
    newImageAct = new QAction(tr("&New"), this);
    newImageAct->setShortcuts(QKeySequence::New);
    newImageAct->setStatusTip(tr("Create a new file"));
    connect(newImageAct, &QAction::triggered, this, &MyMainWindow::create);


    saveImageAct = new QAction(tr("&Save"), this);
    saveImageAct->setShortcuts(QKeySequence::Save);
    saveImageAct->setStatusTip(tr("Save file"));
    connect(saveImageAct, &QAction::triggered, this, &MyMainWindow::save);

    loadImageAct = new QAction(tr("&Load Image"), this);
    newImageAct->setShortcuts(QKeySequence::Open);
    newImageAct->setStatusTip(tr("Load file"));
    connect(loadImageAct, &QAction::triggered, this, &MyMainWindow::OnLoadImage);

    quitAct= new QAction(tr("&Quit"), this);
    quitAct->setShortcuts(QKeySequence::Undo);
    newImageAct->setStatusTip(tr("Quit"));
    connect(quitAct, &QAction::triggered, this, &MyMainWindow::undo);

    undoAct= new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo"));
    connect(undoAct, &QAction::triggered, this, &MyMainWindow::undo);

    redoAct= new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo"));
    connect(redoAct, &QAction::triggered, this, &MyMainWindow::redo);

    clrAct= new QAction(tr("&Clear Canvas"), this);
    clrAct->setShortcuts(QKeySequence::Undo);
    clrAct->setStatusTip(tr("Clear Canvas"));
    connect(clrAct, &QAction::triggered, this, &MyMainWindow::clrCanvas);

    bgChangeAct=new QAction(tr("&Background Color.."), this);
    bgChangeAct->setStatusTip(tr("Background Color"));
    connect(bgChangeAct, &QAction::triggered, this, &MyMainWindow::changeBackgroundColor);

    fgChangeAct=new QAction(tr("&Foreground Color.."), this);
    fgChangeAct->setStatusTip(tr("Foreground Color"));
    connect(fgChangeAct, &QAction::triggered, this, &MyMainWindow::changeForegroundColor);

    penPropAct=new QAction(tr("&Pen Properties.."), this);
    penPropAct->setStatusTip(tr("Pen Properties.."));
    connect(penPropAct, &QAction::triggered, this, &MyMainWindow::penProp);

    linePropAct=new QAction(tr("&Line Properties.."), this);
    linePropAct->setStatusTip(tr("Line Properties"));
    connect(linePropAct, &QAction::triggered, this, &MyMainWindow::penProp);

    eraserPropAct=new QAction(tr("&Eraser Properties.."), this);
    eraserPropAct->setStatusTip(tr("Eraser Properties"));
    connect(eraserPropAct, &QAction::triggered, this, &MyMainWindow::eraserProp);

    rectPropAct=new QAction(tr("&Rectangle Properties.."), this);
    rectPropAct->setStatusTip(tr("Rectangle Properties"));
    connect(rectPropAct, &QAction::triggered, this, &MyMainWindow::rectangleProp);


}
void MyMainWindow ::createMenus()
{

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newImageAct);
    fileMenu->addAction(loadImageAct);
    fileMenu->addAction(saveImageAct);
    fileMenu->addAction(quitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addAction(clrAct);
    editMenu->addAction(bgChangeAct);
    editMenu->addAction(fgChangeAct);

    toolMenu= menuBar()->addMenu(tr("&Tools"));
    toolMenu->addAction(linePropAct);
    toolMenu->addAction(penPropAct);
    toolMenu->addAction(eraserPropAct);
    toolMenu->addAction(rectPropAct);

}




MyMainWindow::~MyMainWindow()
{
    //delete paintdraw->image;
}

void MyMainWindow::OnLoadImage()
{

    QString s = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.bmp)"));

    if (! s.isNull())
    {
      paintDraw->openImage(s);
    }

}

/*void MyMainWindow::mousePressEvent(QMouseEvent * e)
{
    QMessageBox::about( this, "bitmap", "Mouse click event!");
}*/

// paint draw

PaintDraw::PaintDraw(QWidget *parent)
    : QWidget(parent)
{

    setAttribute(Qt::WA_StaticContents);
    shape= Line;
    modified = false;
    painting = false;
    myPenWidth = 1;
    myPenColor = Qt::black;

}
bool PaintDraw::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;

    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

bool PaintDraw::saveImage(const QString &fileName, const char *fileFormat)
{
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());
    if (visibleImage.save(fileName, fileFormat)) {
        modified = false;
        return true;
    } else {
        return false;
    }
}
void PaintDraw::setShape(Shape shape)
{
    this->shape = shape;
    update();
}
void PaintDraw::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}
void PaintDraw::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}
void PaintDraw::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}
void PaintDraw::setPenWidth(int newWidth)
{
    myPenWidth = newWidth;
}
void PaintDraw::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    modified = true;
    update();
}
void PaintDraw::erasePoint()
{
    /*QPainter painter(&image);
    int px=lastPoint->x;
    int py=lastPoint->y;
    int px1=endpoint->x;
    int py1=endpoint->y;
    painter->eraseRect(px,py,px1,py1);*/

}
void PaintDraw::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        painting = true;

    }
}
void PaintDraw::mouseReleaseEvent(QMouseEvent *event)
{
    //int type;
    if (event->button() == Qt::LeftButton && painting) {
        drawLineTo(event->pos());
        painting = false;
       /* switch(event->button())
        {

        case MyMainWindow::eraser()
            erasePoint(event->pos());



        }*/
    }
}
void PaintDraw::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && painting)
        drawLineTo(event->pos());
}

/*void PaintDraw::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}*/
void PaintDraw::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        int newWidth = qMax(width() + 128, image.width());
        int newHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}
void PaintDraw::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    painter.setPen(QPen(myPenColor, myPenWidth, Qt::SolidLine, Qt::RoundCap,
                        Qt::RoundJoin));
    painter.drawLine(lastPoint, endPoint);
    modified = true;

    int rad = (myPenWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized()
                                     .adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}
void PaintDraw::resizeImage(QImage *image, const QSize &newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void PaintDraw::paintEvent(QPaintEvent* e)
{
    QPainter paint(this);
    if (! image.isNull())
    {
        paint.drawImage(QPoint(0,0), (image));
    }
}
