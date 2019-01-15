/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <my_img_display_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen_file;
    QAction *actionopen_dir;
    QAction *actionsave_txt;
    QAction *actionsave_txt_as;
    QAction *actionset_save_dir;
    QAction *actioncancel;
    QAction *actionredo;
    QAction *actionadd_new_box;
    QAction *actiondelete;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *Btn_save;
    QPushButton *Btn_create_reactbox;
    QPushButton *Btn_zoom_in;
    QLineEdit *Line_Scale_Factor;
    QPushButton *Btn_zoom_out;
    QPushButton *Btn_fit_width;
    QScrollArea *scrollArea_Show_Img;
    QWidget *Qwidget_Show_Img;
    my_img_display_label *Lable_Show_Img;
    QLabel *Label_Cord;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Btn_open_dir;
    QPushButton *Btn_open;
    QTableView *tableView_ShowPic;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu_H;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1093, 848);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMouseTracking(true);
        actionopen_file = new QAction(MainWindow);
        actionopen_file->setObjectName(QStringLiteral("actionopen_file"));
        actionopen_dir = new QAction(MainWindow);
        actionopen_dir->setObjectName(QStringLiteral("actionopen_dir"));
        actionsave_txt = new QAction(MainWindow);
        actionsave_txt->setObjectName(QStringLiteral("actionsave_txt"));
        actionsave_txt_as = new QAction(MainWindow);
        actionsave_txt_as->setObjectName(QStringLiteral("actionsave_txt_as"));
        actionset_save_dir = new QAction(MainWindow);
        actionset_save_dir->setObjectName(QStringLiteral("actionset_save_dir"));
        actioncancel = new QAction(MainWindow);
        actioncancel->setObjectName(QStringLiteral("actioncancel"));
        actionredo = new QAction(MainWindow);
        actionredo->setObjectName(QStringLiteral("actionredo"));
        actionadd_new_box = new QAction(MainWindow);
        actionadd_new_box->setObjectName(QStringLiteral("actionadd_new_box"));
        actiondelete = new QAction(MainWindow);
        actiondelete->setObjectName(QStringLiteral("actiondelete"));
        actionZoom_in = new QAction(MainWindow);
        actionZoom_in->setObjectName(QStringLiteral("actionZoom_in"));
        actionZoom_out = new QAction(MainWindow);
        actionZoom_out->setObjectName(QStringLiteral("actionZoom_out"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(300, 500));
        centralWidget->setMouseTracking(true);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Btn_save = new QPushButton(centralWidget);
        Btn_save->setObjectName(QStringLiteral("Btn_save"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Btn_save->sizePolicy().hasHeightForWidth());
        Btn_save->setSizePolicy(sizePolicy2);
        Btn_save->setMinimumSize(QSize(90, 90));

        verticalLayout->addWidget(Btn_save);

        Btn_create_reactbox = new QPushButton(centralWidget);
        Btn_create_reactbox->setObjectName(QStringLiteral("Btn_create_reactbox"));
        sizePolicy2.setHeightForWidth(Btn_create_reactbox->sizePolicy().hasHeightForWidth());
        Btn_create_reactbox->setSizePolicy(sizePolicy2);
        Btn_create_reactbox->setMinimumSize(QSize(90, 90));

        verticalLayout->addWidget(Btn_create_reactbox);

        Btn_zoom_in = new QPushButton(centralWidget);
        Btn_zoom_in->setObjectName(QStringLiteral("Btn_zoom_in"));
        sizePolicy2.setHeightForWidth(Btn_zoom_in->sizePolicy().hasHeightForWidth());
        Btn_zoom_in->setSizePolicy(sizePolicy2);
        Btn_zoom_in->setMinimumSize(QSize(90, 90));

        verticalLayout->addWidget(Btn_zoom_in);

        Line_Scale_Factor = new QLineEdit(centralWidget);
        Line_Scale_Factor->setObjectName(QStringLiteral("Line_Scale_Factor"));
        sizePolicy2.setHeightForWidth(Line_Scale_Factor->sizePolicy().hasHeightForWidth());
        Line_Scale_Factor->setSizePolicy(sizePolicy2);
        Line_Scale_Factor->setMinimumSize(QSize(90, 0));

        verticalLayout->addWidget(Line_Scale_Factor);

        Btn_zoom_out = new QPushButton(centralWidget);
        Btn_zoom_out->setObjectName(QStringLiteral("Btn_zoom_out"));
        sizePolicy2.setHeightForWidth(Btn_zoom_out->sizePolicy().hasHeightForWidth());
        Btn_zoom_out->setSizePolicy(sizePolicy2);
        Btn_zoom_out->setMinimumSize(QSize(90, 90));

        verticalLayout->addWidget(Btn_zoom_out);

        Btn_fit_width = new QPushButton(centralWidget);
        Btn_fit_width->setObjectName(QStringLiteral("Btn_fit_width"));
        sizePolicy2.setHeightForWidth(Btn_fit_width->sizePolicy().hasHeightForWidth());
        Btn_fit_width->setSizePolicy(sizePolicy2);
        Btn_fit_width->setMinimumSize(QSize(90, 90));

        verticalLayout->addWidget(Btn_fit_width);


        horizontalLayout->addLayout(verticalLayout);

        scrollArea_Show_Img = new QScrollArea(centralWidget);
        scrollArea_Show_Img->setObjectName(QStringLiteral("scrollArea_Show_Img"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(5);
        sizePolicy3.setHeightForWidth(scrollArea_Show_Img->sizePolicy().hasHeightForWidth());
        scrollArea_Show_Img->setSizePolicy(sizePolicy3);
        scrollArea_Show_Img->setMinimumSize(QSize(0, 0));
        scrollArea_Show_Img->setMouseTracking(true);
        scrollArea_Show_Img->setWidgetResizable(true);
        Qwidget_Show_Img = new QWidget();
        Qwidget_Show_Img->setObjectName(QStringLiteral("Qwidget_Show_Img"));
        Qwidget_Show_Img->setGeometry(QRect(0, 0, 667, 771));
        Qwidget_Show_Img->setMinimumSize(QSize(0, 0));
        Qwidget_Show_Img->setMouseTracking(true);
        Lable_Show_Img = new my_img_display_label(Qwidget_Show_Img);
        Lable_Show_Img->setObjectName(QStringLiteral("Lable_Show_Img"));
        Lable_Show_Img->setGeometry(QRect(0, 0, 669, 773));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Lable_Show_Img->sizePolicy().hasHeightForWidth());
        Lable_Show_Img->setSizePolicy(sizePolicy4);
        Lable_Show_Img->setMouseTracking(true);
        Label_Cord = new QLabel(Qwidget_Show_Img);
        Label_Cord->setObjectName(QStringLiteral("Label_Cord"));
        Label_Cord->setGeometry(QRect(90, 110, 54, 12));
        Label_Cord->setMouseTracking(true);
        scrollArea_Show_Img->setWidget(Qwidget_Show_Img);

        horizontalLayout->addWidget(scrollArea_Show_Img);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        Btn_open_dir = new QPushButton(centralWidget);
        Btn_open_dir->setObjectName(QStringLiteral("Btn_open_dir"));
        sizePolicy2.setHeightForWidth(Btn_open_dir->sizePolicy().hasHeightForWidth());
        Btn_open_dir->setSizePolicy(sizePolicy2);
        Btn_open_dir->setMinimumSize(QSize(300, 0));

        verticalLayout_2->addWidget(Btn_open_dir);

        Btn_open = new QPushButton(centralWidget);
        Btn_open->setObjectName(QStringLiteral("Btn_open"));
        sizePolicy2.setHeightForWidth(Btn_open->sizePolicy().hasHeightForWidth());
        Btn_open->setSizePolicy(sizePolicy2);
        Btn_open->setMinimumSize(QSize(300, 0));

        verticalLayout_2->addWidget(Btn_open);

        tableView_ShowPic = new QTableView(centralWidget);
        tableView_ShowPic->setObjectName(QStringLiteral("tableView_ShowPic"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tableView_ShowPic->sizePolicy().hasHeightForWidth());
        tableView_ShowPic->setSizePolicy(sizePolicy5);
        tableView_ShowPic->setMinimumSize(QSize(300, 0));
        tableView_ShowPic->setMaximumSize(QSize(50, 16777215));

        verticalLayout_2->addWidget(tableView_ShowPic);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1093, 23));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QStringLiteral("menu_E"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addAction(actionopen_file);
        menu_F->addAction(actionopen_dir);
        menu_F->addAction(actionsave_txt);
        menu_F->addAction(actionsave_txt_as);
        menu_F->addAction(actionset_save_dir);
        menu_E->addAction(actioncancel);
        menu_E->addAction(actionredo);
        menu_E->addSeparator();
        menu_E->addAction(actionadd_new_box);
        menu_E->addAction(actiondelete);
        menu_E->addSeparator();
        menu_E->addAction(actionZoom_in);
        menu_E->addAction(actionZoom_out);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionopen_file->setText(QApplication::translate("MainWindow", "open file", Q_NULLPTR));
        actionopen_dir->setText(QApplication::translate("MainWindow", "open dir", Q_NULLPTR));
        actionsave_txt->setText(QApplication::translate("MainWindow", "save", Q_NULLPTR));
        actionsave_txt_as->setText(QApplication::translate("MainWindow", "save as", Q_NULLPTR));
        actionset_save_dir->setText(QApplication::translate("MainWindow", "set save dir", Q_NULLPTR));
        actioncancel->setText(QApplication::translate("MainWindow", "undo", Q_NULLPTR));
        actionredo->setText(QApplication::translate("MainWindow", "redo", Q_NULLPTR));
        actionadd_new_box->setText(QApplication::translate("MainWindow", "add new box", Q_NULLPTR));
        actiondelete->setText(QApplication::translate("MainWindow", "delete box", Q_NULLPTR));
        actionZoom_in->setText(QApplication::translate("MainWindow", "Zoom in", Q_NULLPTR));
        actionZoom_out->setText(QApplication::translate("MainWindow", "Zoom out", Q_NULLPTR));
        Btn_save->setText(QApplication::translate("MainWindow", "save", Q_NULLPTR));
        Btn_create_reactbox->setText(QApplication::translate("MainWindow", "create rectbox", Q_NULLPTR));
        Btn_zoom_in->setText(QApplication::translate("MainWindow", "zoom in", Q_NULLPTR));
        Btn_zoom_out->setText(QApplication::translate("MainWindow", "zoom out", Q_NULLPTR));
        Btn_fit_width->setText(QApplication::translate("MainWindow", "fit width", Q_NULLPTR));
        Lable_Show_Img->setText(QString());
        Label_Cord->setText(QString());
        Btn_open_dir->setText(QApplication::translate("MainWindow", "open img dir", Q_NULLPTR));
        Btn_open->setText(QApplication::translate("MainWindow", "open image", Q_NULLPTR));
        menu_F->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(F)", Q_NULLPTR));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(E)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
