#include <QTextEdit>
#include <QDockWidget>
#include <QStatusBar>
#include <QPushButton>
#include "mainwindow.h"
#include <QMenuBar>
#include <QDebug>
#include <QToolBar>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //调整窗口大小
    resize(600,400);

    //菜单栏创建 ,菜单栏只能有一个
    QMenuBar *bar = menuBar();
    //将菜单栏放入窗口中
    setMenuBar(bar);

    //创建菜单
//    bar->addMenu("控制台");
    QMenu *controlMenu = bar->addMenu("控制台");
    QMenu *plaintMenu = bar->addMenu("绘图");

    //创建菜单项
    //写字机控制台
    QAction *controlAction = controlMenu->addAction("写字机控制台");
    controlMenu->addSeparator();
    controlMenu->addAction("雕刻机控制台");
    //绘图控制台
    plaintMenu->addAction("写字机绘图");
//    controlMenu->setc
//    connect(controlMenu,&QMunu::)

    //工具栏
    QToolBar *toolBar =new QToolBar(this);

    //把工具栏放入窗口
    addToolBar(Qt::LeftToolBarArea,toolBar);

    //设置只能左右停靠，不能上下停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置不能悬停，浮动，只能停靠
    toolBar->setFloatable(false);
    //设置移动使能（总开关）
    toolBar->setMovable(true);

    //设置工具栏内容
    //方式1
    toolBar->addAction("命令窗口");
    toolBar->addSeparator();
    //方式2
    toolBar->addAction(controlAction);
    toolBar->addSeparator();

    //工具栏添加控件
    QPushButton *btn0 = new QPushButton("绘图",this);
    btn0->adjustSize();
    toolBar->addWidget(btn0);
    toolBar->addSeparator();


    //状态栏 最多有一个
    QStatusBar *statusBar = new QStatusBar;
    //把状态栏放入窗口
    setStatusBar(statusBar);

    //放入标签控件
    QLabel *label = new QLabel("版本信息",this);
    QLabel *label1 = new QLabel("提示",this);
    //从左到右
    statusBar->addWidget(label);
    //从右到左
    statusBar->addPermanentWidget(label1);

    //铆接控件 （浮动窗口） ，可以有多个
    QDockWidget *dockWidget = new QDockWidget("控制台",this);
    addDockWidget(Qt::TopDockWidgetArea,dockWidget);
    //设置停靠范围
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::RightDockWidgetArea);
//    //添加控件
//    dockWidget->addAction(controlAction);



    //设置中心部件 只能有一个
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);



}

MainWindow::~MainWindow()
{
}

