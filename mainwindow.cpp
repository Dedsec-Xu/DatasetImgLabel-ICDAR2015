#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->showMessage("欢迎！");
    //显示欢迎信息
    ui->Lable_Show_Img->setScaledContents(true);
    ui->scrollArea_Show_Img->setBackgroundRole(QPalette::Dark);
    ui->Line_Scale_Factor->setText(QString::number(g_dScaleFactor,10,2));

    //设置图片显示区域
    qmodelPicList->setColumnCount(2);
    qmodelPicList->setHeaderData(0,Qt::Horizontal,QString("图片名"));
    qmodelPicList->setHeaderData(1,Qt::Horizontal,QString("路径"));
    ui->tableView_ShowPic->setModel(qmodelPicList);
    //设置右侧文件列表
    connect(ui->actionZoom_in,&QAction::triggered,this,&MainWindow::on_Btn_zoom_in_clicked);
    connect(ui->actionZoom_out,&QAction::triggered,this,&MainWindow::on_Btn_zoom_out_clicked);
    connect(ui->actionopen_file,&QAction::triggered,this,&MainWindow::on_Btn_open_clicked);
    connect(ui->actionopen_dir,&QAction::triggered,this,&MainWindow::on_Btn_open_dir_clicked);
    connect(this, SIGNAL(signal_StartDrawingRect()), ui->Lable_Show_Img, SLOT(slot_DrawRectStart()));
    //连接菜单栏事件和按钮
    ui->Lable_Show_Img->installEventFilter(this);
    //安装事件过滤器
    ui->Btn_open->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    ui->Btn_open_dir->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_D));
    ui->Btn_create_reactbox->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_R));
    //设置快捷键

}

MainWindow::~MainWindow()
{
    delete ui;
}

//开启按钮事件
void MainWindow::on_Btn_open_clicked()
{
    DirFileList.clear();
    qmodelPicList->clear();//clears the list
    if(g_iOpenMarker == 1)
    {
        QMessageBox::information(this,
                    tr("是否要保存"),
                    tr("是否要保存"));
    }
    strFilePath = QFileDialog::getOpenFileName(
            this, tr("open image file"),
            "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm *.tiff);;All files (*.*)"));
    if(openImage(strFilePath)!=0)
    {
        QMessageBox::information(this,
            tr("出现了一个问题"),
            tr("你没有选择图片！"));
    }
    statusBar()->showMessage(QString("打开图片:")+QString(strFilePath));
}

//适合窗口按钮事件
void MainWindow::on_Btn_fit_width_clicked()
{

    if(g_iOpenMarker == 1)
    {
        int iImgAreaHeight = ui->scrollArea_Show_Img->height()-2;
        int iImgAreaWidth = ui->scrollArea_Show_Img->width()-2;
        double dImgAreaRatio = (double)iImgAreaWidth / iImgAreaHeight;
        qDebug()<<"\nR:"<< dImgAreaRatio;
        double dImgRatio = (double)qimgOpened->width() / qimgOpened->height();
        ui->Lable_Show_Img->setAlignment(Qt::AlignCenter);
        if(dImgAreaRatio > dImgRatio)//区域宽高比大于图片宽高比，按照高度缩放
        {
            g_dScaleFactor = (double)iImgAreaHeight / qimgOpened->height();
            ui->Lable_Show_Img->set_dScaleFactor(g_dScaleFactor); 
            scaleImageD(g_dScaleFactor);
        }
        else//区域宽高比小于于图片宽高比，按照宽度缩放
        {

            g_dScaleFactor = (double)iImgAreaWidth / qimgOpened->width();
            ui->Lable_Show_Img->set_dScaleFactor(g_dScaleFactor);
            scaleImageD(g_dScaleFactor);
        }
    }
    statusBar()->showMessage(QString("已经缩放到适合边框"));
}

//放大按钮事件
void MainWindow::on_Btn_zoom_in_clicked()
{
    scaleImageR(1.25);
    statusBar()->showMessage(QString("放大(放缩范围：10%~1000%)"));
}

//缩小按钮事件
void MainWindow::on_Btn_zoom_out_clicked()
{
    scaleImageR(0.8);
    statusBar()->showMessage(QString("缩小(放缩范围：10%~1000%)"));
}

//开启文件夹按钮事件
void MainWindow::on_Btn_open_dir_clicked()
{
    DirFileList.clear();
    qmodelPicList->clear();//clears the list

    if(g_iOpenMarker == 1)
    {
        QMessageBox::information(this,
                    tr("是否要保存"),
                    tr("是否要保存"));
    }
    strDirPath = QFileDialog::getExistingDirectory(this,"one","/home");
    QDir qdirDirPath;
    qdirDirPath.setPath(strDirPath);
    qdirDirPath.setFilter(QDir::Files|QDir::NoSymLinks);
    qdirDirPath.setSorting(QDir::Name);
    QStringList filters;
    filters<<"*.bmp"<< "*.jpg"<< "*.pbm"<< "*.pgm"<< "*.png"<< "*.ppm"<< "*.xbm"<< "*.xpm" <<"*.tiff";
    qdirDirPath.setNameFilters(filters);
    DirFileList=qdirDirPath.entryInfoList();
    QString str;
    for(int i=0;i<DirFileList.length();i++)
    {
        QFileInfo fileinfo=DirFileList.at(i);
        str=fileinfo.fileName();
        QStandardItem *item=new QStandardItem(str);
        qmodelPicList->setItem(i,0,item);

        str=fileinfo.absoluteFilePath();
        item=new QStandardItem(str);
        qmodelPicList->setItem(i,1,item);
    }

    qDebug() << strDirPath;
    statusBar()->showMessage(QString("打开图片目录:")+QString(strFilePath)+QString(",双击你想编辑的图片"));
}

//双击表格文件事件
void MainWindow::on_tableView_ShowPic_doubleClicked(const QModelIndex &index)
{
    QFileInfo fileinfo=DirFileList.at(index.row());

    if(openImage(fileinfo.absoluteFilePath())!=0)
    {
        QMessageBox::information(this,
            tr("出现了一个问题"),
            tr("图像无法打开！"));
    }
    statusBar()->showMessage(QString("打开目录下图片:")+QString(fileinfo.fileName()));
}

//输入放大倍数事件
void MainWindow::on_Line_Scale_Factor_editingFinished()
{
    bool bTranslationSuccess;
    double dInputScaleFactor = ui->Line_Scale_Factor->text().toDouble(&bTranslationSuccess);
    if(!bTranslationSuccess)
    {
        QMessageBox::information(this,
                    tr("输入错误"),
                    QString("请输入一个")+QString::number(g_dScaleFactorMIN,10,1)+QString("~")+QString::number(g_dScaleFactorMAX,10,1)+QString("之间的有效缩放比例"));
    }
    else if((dInputScaleFactor < 0.3) || (dInputScaleFactor > 3.0) )
    {
        QMessageBox::information(this,
                    tr("输入错误"),
                    QString("请输入一个")+QString::number(g_dScaleFactorMIN,10,1)+QString("~")+QString::number(g_dScaleFactorMAX,10,1)+QString("之间的有效缩放比例"));
    }
    else
    {
        scaleImageD(dInputScaleFactor);
    }
}

//创建方框事件
void MainWindow::on_Btn_create_reactbox_clicked()
{
    g_boolMakingRect = true;
    g_boolShowCord = true;
    emit signal_StartDrawingRect();
    qDebug()<< g_boolMakingRect << g_boolRectMouseDown;
}


//放大图片 输入为相对放大系数
void MainWindow::scaleImageR(double dInputScaleFactor)
{
    if(g_iOpenMarker == 1)
    {
        g_dScaleFactor *= dInputScaleFactor;
        ui->Lable_Show_Img->set_dScaleFactor(g_dScaleFactor); 
        
        if(g_dScaleFactor < g_dScaleFactorMIN)
        {
            g_dScaleFactor = g_dScaleFactorMIN;
        }
        if(g_dScaleFactor > g_dScaleFactorMAX)
        {
            g_dScaleFactor = g_dScaleFactorMAX;
        }

        ui->Line_Scale_Factor->setText(QString::number(g_dScaleFactor,10,2));
        ui->Lable_Show_Img->resize(g_dScaleFactor * ui->Lable_Show_Img->pixmap()->size());
        ui->Qwidget_Show_Img->setMinimumSize(ui->Lable_Show_Img->pixmap()->size()*g_dScaleFactor);
    }

}

//放大图片 输入为绝对放大系数
void MainWindow::scaleImageD(double dInputScaleFactor)
{
    if(g_iOpenMarker == 1)
    {
        g_dScaleFactor = dInputScaleFactor;
        ui->Lable_Show_Img->set_dScaleFactor(g_dScaleFactor); 
        if(g_dScaleFactor < g_dScaleFactorMIN)
        {
            g_dScaleFactor = g_dScaleFactorMIN;
        }
        if(g_dScaleFactor > g_dScaleFactorMAX)
        {
            g_dScaleFactor = g_dScaleFactorMAX;
        }

        ui->Line_Scale_Factor->setText(QString::number(g_dScaleFactor,10,2));
        ui->Lable_Show_Img->resize(g_dScaleFactor * ui->Lable_Show_Img->pixmap()->size());
        ui->Qwidget_Show_Img->setMinimumSize(ui->Lable_Show_Img->pixmap()->size()*g_dScaleFactor);

    }


}

//label显示图片
int MainWindow::openImage(QString qstrFilePath)
{
    ui->scrollArea_Show_Img->setVisible(false);
    qimgOpened = new QImage;

    if(!(qimgOpened->load(qstrFilePath))) //加载图像
    {
        ui->scrollArea_Show_Img->setVisible(true);
        return -1;
    }
    else
    {
        ui->Lable_Show_Img->resize(qimgOpened->width(),qimgOpened->height());
        ui->Lable_Show_Img->setAlignment(Qt::AlignCenter);
        ui->Lable_Show_Img->setPixmap(QPixmap::fromImage(*qimgOpened));
        scaleImageD(1.00);
        ui->scrollArea_Show_Img->setVisible(true);
        g_iOpenMarker = 1;
    }
    ui->Qwidget_Show_Img->setMinimumSize(ui->Lable_Show_Img->pixmap()->size()*g_dScaleFactor);
    return 0;
}


