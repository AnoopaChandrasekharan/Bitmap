#include <qmainwindow.h>
#include <qmessagebox.h>
#include <QMenu>
#include <qmenubar.h>
#include <qapplication.h>
#include <qpixmap.h>
#include<QPen>
#include<QWidget>
#ifndef PAINT
#define PAINT

#endif // PAINT

class PaintDraw : public QWidget {

    Q_OBJECT


public:

    PaintDraw(QWidget *parent = 0);
    enum Shape { Line, Rect, Pixmap };
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);
    void erasePoint();
    //void drawRectTo(const QPoint &endpoint);
    void paintEventRect(QPaintEvent *event) ;
    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void clearImage();


private:

    Shape shape;
    QPen pen;
    QBrush brush;
    bool modified;
    bool painting;
    int myPenWidth;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
    QPixmap pixmap;

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE;

};
