#include "rectdata.h"

RectData::RectData()
{
    ipixXmin = 0;
    ipixXmax = 0;
    ipixYmin = 0;
    ipixYmax = 0;
    valid = false;
}

RectData::RectData(QPoint p1, QPoint p2)
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
            valid = true;            
        }
        else if(y1>y2)
        {
            ipixXmin = x1;
            ipixXmax = x2;
            ipixYmin = y2;
            ipixYmax = y1;
            valid = true; 
        }
        else
        {
            ipixXmin = x1;
            ipixXmax = x2;
            ipixYmin = y1;
            ipixYmax = y2;
            valid = false; 
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
            valid = true; 
        }
        else if(y1>y2)
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y2;
            ipixYmax = y1;
            valid = true; 
        }
        else
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y2;
            ipixYmax = y1;
            valid = true; 
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
            valid = false;
        }
        else
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y2;
            ipixYmax = y1;
            valid = false;
        }
    }
    qDebug()<<"创建了"<<ipixXmin <<ipixXmax <<ipixYmin <<ipixYmax <<valid;
}
RectData::RectData(int x1, int x2, int y1, int y2)
{
    if(x1<x2)
    {
        if(y1<y2)
        {
            ipixXmin = x1;
            ipixXmax = x2;
            ipixYmin = y1;
            ipixYmax = y2;
            valid = true;
        }
        else if(y1>y2)
        {
            ipixXmin = x1;
            ipixXmax = x2;
            ipixYmin = y2;
            ipixYmax = y1;
            valid = true;
        }
        else
        {
            ipixXmin = x1;
            ipixXmax = x2;
            ipixYmin = y1;
            ipixYmax = y2;
            valid = false;
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
            valid = true;
        }
        else if(y1>y2)
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y2;
            ipixYmax = y1;
            valid = true;
        }
        else
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y2;
            ipixYmax = y1;
            valid = true;
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
            valid = false;
        }
        else
        {
            ipixXmin = x2;
            ipixXmax = x1;
            ipixYmin = y2;
            ipixYmax = y1;
            valid = false;
        }
    }
}
