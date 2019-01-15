#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QScrollBar>
#include <QScrollArea>
#include <QStandardItem>
#include <QTableView>
#include <QString>
#include <QEvent>
#include <QMouseEvent>
#include <QTime>
#include <QDir>
#include <QFile>
#include <QPainter>
#include <QPaintDevice>
#include <string>

#include "my_img_display_label.h"
#include "rectdata.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString strFilePath;//path of single opend file
    QString strDirPath;//path of opened path
    QStandardItemModel  *qmodelPicList = new QStandardItemModel();
    QFileInfoList DirFileList;
    QPoint g_qpointMousePosition;//鼠标位置
    QPoint g_qpointMousePressedLocation= QPoint(0,0);//鼠标按下位置
    QPoint g_qpointMousePressedPixelLocation= QPoint(0,0);//鼠标按下的像素位置
    QPoint g_qpointMouseReleasedLocation= QPoint(0,0);//鼠标释放位置
    QPoint g_qpointMouseReleasedPixelLocation= QPoint(0,0);//鼠标释放的像素位置
    int g_iOpenMarker = 0;//标记是否有文件打开
    int g_iMode = 0;//标记是打开单张图片模式（0）还是多张模式（1）
    bool g_boolMakingRect = false;//标记是否在创造矩形
    bool g_boolShowCord = false;//标记是否显示坐标
    bool g_boolRectMouseDown = false;//标记创造矩形时鼠标是否按下
    bool g_boolCurrentSaved = false;
    QImage* qimgOpened = NULL;//打开的单个图片·
    double g_dScaleFactor = 1.0;//全局图片放缩指数
    double g_dScaleFactorMAX = 10.0;//图片放缩指数最大值
    double g_dScaleFactorMIN = 0.1;//图片放缩指数最大值


private slots:
    //开启按钮事件
    void on_Btn_open_clicked();
    //适合窗口按钮事件
    void on_Btn_fit_width_clicked();
    //放大按钮事件
    void on_Btn_zoom_in_clicked();
    //缩小按钮事件
    void on_Btn_zoom_out_clicked();
    //开启文件夹按钮事件
    void on_Btn_open_dir_clicked();
    //双击表格文件事件
    void on_tableView_ShowPic_doubleClicked(const QModelIndex &index);
    //输入放大倍数事件
    void on_Line_Scale_Factor_editingFinished();
    //创建方框事件
    void on_Btn_create_reactbox_clicked();

protected:    


signals:
    void signal_StartDrawingRect();

private:
    Ui::MainWindow *ui;
    //放大图片 输入为相对放大系数
    void scaleImageR(double factor);
    //放大图片 输入为绝对放大系数
    void scaleImageD(double factor);
    //label显示图片
    int openImage(QString filepath);
    bool mMoveStart;
    bool mContinuousMove;
    QPoint mMousePoint;

};

#endif // MAINWINDOW_H
