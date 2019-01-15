#ifndef RECTDATA_H
#define RECTDATA_H

#include <QObject>
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
#include <QLabel>
#include <string>


class RectData
{
public:
    RectData();
    RectData(QPoint p1, QPoint p2);
    RectData(int x1, int x2, int y1, int y2);
    int ipixXmin = 0;
    int ipixXmax = 0;
    int ipixYmin = 0;
    int ipixYmax = 0;
    bool valid = false;
};

#endif // RECTDATA_H
