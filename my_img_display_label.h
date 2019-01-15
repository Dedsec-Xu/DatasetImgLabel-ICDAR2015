#ifndef MY_IMG_DISPLAY_LABEL_H
#define MY_IMG_DISPLAY_LABEL_H

#include <QMainWindow>
#include <QDebug>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QScrollBar>
#include <QScrollArea>
#include <QStandardItem>
#include <QTableView>
#include <QDebug>
#include <QString>
#include <QEvent>
#include <QMouseEvent>
#include <QTime>
#include <QDir>
#include <QFile>
#include <QPainter>
#include <QPaintDevice>
#include <QLabel>
#include <string>
#include <QVector>
#include "rectdata.h"

/*重写Qlabel类 使其支持画图*/
class my_img_display_label : public QLabel
{
    Q_OBJECT
public:
    explicit my_img_display_label(QWidget *parent = 0);
    void set_dScaleFactor(double g_dScaleFactor);
    QVector<RectData*> qvecRectData;

private:
    bool my_img_boolMakingRect = false;//标记鼠标是否按下
    bool my_img_boolMouseDown = false;//标记鼠标是否按下
    bool my_img_boolDragging = false;//标记现在正在拖动、
    int iDraggingPlace = 0;//标记正在拖动的位置
    int iDistGate = 3;//判断点到的门限像素值
    QPoint my_img_qpointMousePosition = QPoint(0,0);//鼠标移动时的位置
    QPoint my_img_qpointMousePixelPosition= QPoint(0,0);//鼠标移动时的像素位置
    QPoint my_img_qpointMousePressedLocation = QPoint(0,0);//鼠标按下位置
    QPoint my_img_qpointMousePressedPixelLocation= QPoint(0,0);//鼠标按下的像素位置
    QPoint my_img_qpointMouseReleasedLocation= QPoint(0,0);//鼠标释放位置
    QPoint my_img_qpointMouseReleasedPixelLocation= QPoint(0,0);//鼠标释放的像素位置
    RectData* rectCurrentData;
    RectData* rectTempData;
    double my_img_dScaleFactor = 1.0;//全局图片放缩指数



signals:
    void ImgLabelMousePressed();
    void ImgLabelMouseMoved();
    void ImgLabelMouseReleased();
    void DeletedRect();//通知主窗口删除了一个矩形
    void FinishRectadd();//通知主窗口新矩形可行并保存
    void RectNotValid();//通知主窗口新矩形不可行
    void FinishRectModify();//通知主窗口矩形改动可行并保存
    void RectModifyNotValid();//通知主窗口矩形不可行

protected:
    //鼠标点击事件
    void mousePressEvent(QMouseEvent* event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);
    //绘图事件
    void paintEvent(QPaintEvent *event);
    //画一个矩形 输入1为一个结构体 输入2为要画的矩形的类型
    void paintRect(RectData* rectbox, int type, double dScaleFactor, QPainter &qpainterRect);
    //通过像素画一个矩形
    void paintRectPix(QPoint p1, QPoint p2, int type, QPainter &qpainterRect);
    //画一个正在被拖动的矩形
    void paintDraggingRect(QPoint p1, RectData* rect, int iDragPlace, int type, QPainter &qpainterRect);
    //将点转换成像素位置
    void point2pix(QPoint p1, QPoint p2, int &ipixXmin, int &ipixXmax, int &ipixYmin, int &ipixYmax);
    //检测是否点到矩形,iClickedplace记录点到的位置，返回是否点到
    bool checkclicked(QPoint p1, RectData* rect, int &iClickedplace);

public slots:
    void slot_DrawRectStart();

};

#endif // MY_IMG_DISPLAY_LABEL_H
