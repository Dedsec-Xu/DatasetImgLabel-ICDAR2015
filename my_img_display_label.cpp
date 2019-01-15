#include "my_img_display_label.h"


my_img_display_label::my_img_display_label(QWidget *parent) :
    QLabel(parent)
{

}

void my_img_display_label::set_dScaleFactor(double g_dScaleFactor)
{
    my_img_dScaleFactor = g_dScaleFactor;
    update();
}

void my_img_display_label::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(my_img_boolMakingRect)
        {
            emit ImgLabelMousePressed();
            my_img_qpointMousePressedLocation = event->pos();//鼠标按下位置
            my_img_qpointMousePosition = event->pos();
            my_img_qpointMousePressedPixelLocation = my_img_qpointMousePressedLocation / my_img_dScaleFactor;//计算像素位置,此则要保存的像素位置
            my_img_boolMouseDown = true;
            update();
        }
        else
        {
            my_img_qpointMousePressedLocation = event->pos();
            for(int itempindex = 0; itempindex < qvecRectData.count(); itempindex++)
            {
                int temp;
                if(checkclicked(my_img_qpointMousePressedLocation, qvecRectData[itempindex], temp))
                {//右键点到了一个矩形框 删除并跳出
                    rectCurrentData = qvecRectData[itempindex];
                    rectTempData = qvecRectData[itempindex];
                    qvecRectData.erase(qvecRectData.begin()+itempindex);
                    my_img_boolDragging = true;//标记现在正在拖动、
                    iDraggingPlace = temp;//标记正在拖动的位置
                    my_img_qpointMousePosition = event->pos();
                    update();
                    break;
                }
            }
        }
    }
    else if(event->button() == Qt::RightButton)
    {
        my_img_qpointMousePressedLocation = event->pos();
        for(int itempindex = 0; itempindex < qvecRectData.count(); itempindex++)
        {
            int temp;
            if(checkclicked(my_img_qpointMousePressedLocation, qvecRectData[itempindex], temp))
            {//右键点到了一个矩形框 删除并跳出
                qvecRectData.erase(qvecRectData.begin()+itempindex);
                update();
                emit DeletedRect();//通知删除了一个矩形
                break;
            }
        }
    }
}

void my_img_display_label::mouseMoveEvent(QMouseEvent *event)
{
    if(my_img_boolMakingRect || my_img_boolDragging)
    {
        emit ImgLabelMouseMoved();
        my_img_qpointMousePosition = event->pos();
        my_img_qpointMousePixelPosition = my_img_qpointMousePosition / my_img_dScaleFactor;
        update();
    }
}

void my_img_display_label::mouseReleaseEvent(QMouseEvent *event)
{

    if(my_img_boolMakingRect&&my_img_boolMouseDown)
    {
        emit ImgLabelMouseReleased();
        my_img_qpointMouseReleasedLocation = event->pos();
        my_img_qpointMouseReleasedPixelLocation = my_img_qpointMouseReleasedLocation / my_img_dScaleFactor;//计算像素位置,此则要保存的像素位置

        my_img_boolMouseDown = false;
        my_img_boolMakingRect = false;
        rectCurrentData = new RectData(my_img_qpointMousePressedPixelLocation, my_img_qpointMouseReleasedPixelLocation);
        
        if(rectCurrentData->valid)
        {
            emit FinishRectadd();//通知主窗口矩形已经创建并保存
            qvecRectData.append(rectCurrentData);
            qDebug()<<qvecRectData.count();//回显保存的个数
        }
        else
        {
            emit RectNotValid();//通知主窗口矩形不符合要求
        }
        update();
    }
    else if(my_img_boolDragging)
    {
        my_img_boolDragging = false;
        if(rectCurrentData->valid)
        {
            emit FinishRectModify();//通知主窗口矩形改动可行并保存
            qvecRectData.append(rectCurrentData);
            qDebug()<<qvecRectData.count();//回显保存的个数
        }
        else
        {
            emit RectModifyNotValid();//通知主窗口矩形改动不符合要求
        }
        update();
    }
}



void my_img_display_label::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    if(my_img_boolMouseDown && my_img_boolMouseDown)
    {//绘图：正在画的这个矩形
        QPainter painter(this);
        painter.setOpacity(0.3);
        QBrush brush(Qt::green, Qt::CrossPattern);
        painter.setBrush(brush);
        paintRectPix(my_img_qpointMousePressedLocation, my_img_qpointMousePosition, 0, painter);
        painter.drawLine(my_img_qpointMousePressedLocation,my_img_qpointMousePosition);

    }
    if(qvecRectData.count()>0)
    {//绘图：画好的所有矩形
        for(int itempindex = 0; itempindex < qvecRectData.count(); itempindex++)
        {
            QPainter painter(this);
            painter.setOpacity(0.6);
            paintRect(qvecRectData[itempindex], 1, my_img_dScaleFactor, painter);
        }
    }
    if(my_img_boolMakingRect)
    {//显示目前正在画的坐标
        QPainter painter(this);
        QString location;
        QFont font;
        font.setFamily("consolas");
        painter.setFont(font);
        location = QString::number(my_img_qpointMousePixelPosition .x());
        location += QString(",");
        location += QString::number(my_img_qpointMousePixelPosition .y());
        painter.drawText(my_img_qpointMousePosition.x()+20,my_img_qpointMousePosition.y()+20, location);
    }
    if(my_img_boolDragging)
    {
        QPainter painter(this);
        painter.setOpacity(0.3);
        QBrush brush(Qt::blue, Qt::CrossPattern);
        painter.setBrush(brush);
        paintDraggingRect(my_img_qpointMousePosition , rectTempData, iDraggingPlace, 2, painter);
    }
}

void my_img_display_label::paintRect(RectData* rectbox, int type, double dScaleFactor, QPainter &qpainterRect)
{
    QRect *temprect = new QRect(rectbox->ipixXmin*dScaleFactor, rectbox->ipixYmin * dScaleFactor
                                  , (rectbox->ipixXmax-rectbox->ipixXmin) * dScaleFactor
                                  , (rectbox->ipixYmax-rectbox->ipixYmin) * dScaleFactor);
    switch(type)
    {
        case 0:
        qpainterRect.setPen(QPen(Qt::green,3));
        break;
            
        case 1:
        qpainterRect.setPen(QPen(Qt::red,3));
        break;
            
        case 2:
        qpainterRect.setPen(QPen(Qt::blue,3));
        break;
    
        default :
        qpainterRect.setPen(QPen(Qt::red,3));
        break;
    }
    qpainterRect.drawRect(*temprect);
}

void my_img_display_label::paintRectPix(QPoint p1, QPoint p2, int type, QPainter &qpainterRect)
{
    int ipixXmin, ipixXmax, ipixYmin, ipixYmax;
    point2pix(p1, p2, ipixXmin, ipixXmax, ipixYmin, ipixYmax);

    QRect *temprect = new QRect(ipixXmin, ipixYmin
                            , (ipixXmax - ipixXmin)
                            , (ipixYmax - ipixYmin));
    switch(type)
    {
        case 0:
        qpainterRect.setPen(QPen(Qt::green,3));
        break;
            
        case 1:
        qpainterRect.setPen(QPen(Qt::red,3));
        break;
            
        case 2:
        qpainterRect.setPen(QPen(Qt::blue,3));
        break;
    
        default :
        qpainterRect.setPen(QPen(Qt::red,3));
        break;
    }
    qpainterRect.drawRect(*temprect);
}

void my_img_display_label::paintDraggingRect(QPoint p1, RectData* rect, int iDragPlace, int type, QPainter &qpainterRect)
{
    int x1 = p1.x();
    int y1 = p1.y();
    QPoint pLeftUp = QPoint(rect->ipixXmin*my_img_dScaleFactor, rect->ipixYmin * my_img_dScaleFactor);
    QPoint pRightUp = QPoint(rect->ipixXmax*my_img_dScaleFactor, rect->ipixYmin * my_img_dScaleFactor);
    QPoint pLeftDown = QPoint(rect->ipixXmin*my_img_dScaleFactor, rect->ipixYmax * my_img_dScaleFactor);
    QPoint pRightDown = QPoint(rect->ipixXmax*my_img_dScaleFactor, rect->ipixYmax * my_img_dScaleFactor);

    switch(iDragPlace)
    {
        case 1://左上
            paintRectPix(pRightDown , p1, type, qpainterRect);
            rectCurrentData = new RectData(p1/my_img_dScaleFactor, pRightDown/my_img_dScaleFactor);
        break;

        case 2://右上
            paintRectPix(pLeftDown , p1, type, qpainterRect);
            rectCurrentData = new RectData(pLeftDown/my_img_dScaleFactor, p1/my_img_dScaleFactor);
        break;

        case 3://左下
            paintRectPix(pRightUp , p1, type, qpainterRect);
            rectCurrentData = new RectData(pRightUp/my_img_dScaleFactor, p1/my_img_dScaleFactor);
        break;

        case 4://右下
            paintRectPix(pLeftUp , p1, type, qpainterRect);
            rectCurrentData = new RectData(pLeftUp/my_img_dScaleFactor, p1/my_img_dScaleFactor);
        break;

        case 5://上
            pLeftUp = QPoint(pLeftUp.x(), p1.y());
            paintRectPix(pLeftUp, pRightDown, type, qpainterRect);
            rectCurrentData = new RectData(pLeftUp/my_img_dScaleFactor, pRightDown/my_img_dScaleFactor);
        break;

        case 6://下
            pRightDown = QPoint(pRightDown.x(), p1.y());
            paintRectPix(pLeftUp, pRightDown, type, qpainterRect);
            rectCurrentData = new RectData(pLeftUp/my_img_dScaleFactor, pRightDown/my_img_dScaleFactor);
        break;

        case 7://左
            pLeftUp = QPoint(p1.x(), pLeftUp.y());
            paintRectPix(pLeftUp, pRightDown, type, qpainterRect);
            rectCurrentData = new RectData(pLeftUp/my_img_dScaleFactor, pRightDown/my_img_dScaleFactor);
        break;

        case 8://右
            pRightDown = QPoint(p1.x(), pRightDown.y());
            paintRectPix(pLeftUp, pRightDown, type, qpainterRect);
            rectCurrentData = new RectData(pLeftUp/my_img_dScaleFactor, pRightDown/my_img_dScaleFactor);
        break;
    
        default :
        break;
    }
}

void my_img_display_label::point2pix(QPoint p1, QPoint p2, int &ipixXmin, int &ipixXmax, int &ipixYmin, int &ipixYmax)
{
    int x1 = p1.x();
    int x2 = p2.x();
    int y1 = p1.y();
    int y2 = p2.y();
    if(x1<x2)
    {
        if(y1<y2)
        {
            ipixXmin = x1;
            ipixXmax = x2;
            ipixYmin = y1;
            ipixYmax = y2;
        }
        else if(y1>y2)
        {
            ipixXmin = x1;
            ipixXmax = x2;
            ipixYmin = y2;
            ipixYmax = y1;
        }
        else
        {
            ipixXmin = x1;
            ipixXmax = x2;
            ipixYmin = y1;
            ipixYmax = y2;
        }
    }
    else if(x1>x2)
    {
        if(y1<y2)
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y1;
            ipixYmax = y2;
        }
        else if(y1>y2)
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y2;
            ipixYmax = y1;
        }
        else
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y2;
            ipixYmax = y1;
        }
    }
    else
    {
        if(y1<y2)
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y1;
            ipixYmax = y2;
        }
        else
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y2;
            ipixYmax = y1;
        }
    }
}

bool my_img_display_label::checkclicked(QPoint p1, RectData *rect, int &iClickedplace)
{
    int xmin = rect->ipixXmin * my_img_dScaleFactor;
    int xmax = rect->ipixXmax * my_img_dScaleFactor;
    int ymin = rect->ipixYmin * my_img_dScaleFactor;
    int ymax = rect->ipixYmax * my_img_dScaleFactor;

    int px = p1.x();
    int py = p1.y();
    int iLeftDist = qAbs(px - xmin);
    int iRightDist = qAbs(px - xmax);
    int iUptDist = qAbs(py - ymin);
    int iDowntDist = qAbs(py - ymax);

    if(iLeftDist<=iDistGate && iUptDist<=iDistGate)
    {
        iClickedplace = 1;//左上角
        return true;
    }
    else if(iRightDist<=iDistGate && iUptDist<=iDistGate)
    {
        iClickedplace = 2;//右上角
        return true;
    }
    else if(iLeftDist<=iDistGate && iDowntDist<=iDistGate)
    {
        iClickedplace = 3;//左下角
        return true;
    }
    else if(iRightDist<=iDistGate && iDowntDist<=iDistGate)
    {
        iClickedplace = 4;//右下角
        return true;
    }
    else if(iUptDist<=iDistGate)
    {
        iClickedplace = 5;//上边
        return true;
    }
    else if(iDowntDist<=iDistGate)
    {
        iClickedplace = 6;//下边
        return true;
    }
    else if(iLeftDist<=iDistGate)
    {
        iClickedplace = 7;//左边
        return true;
    }
    else if(iRightDist<=iDistGate)
    {
        iClickedplace = 8;//右边
        return true;
    }
    else
    {
        iClickedplace = 0;//没有点到
        return false;
    }


}



void my_img_display_label::slot_DrawRectStart()
{
    my_img_boolMakingRect = true;
}



