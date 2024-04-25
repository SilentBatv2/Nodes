#include "stdafx.h"
#include "fossee_screening.h"

FOSSEE_Screening::FOSSEE_Screening(QWidget* parent)
    : QMainWindow(parent)
{
    setupMenuBar();
    setupStatusBar();
    setupCentralWidget();
}

FOSSEE_Screening::~FOSSEE_Screening()
{}

void FOSSEE_Screening::setupStatusBar()
{
    statusbar = statusBar();
}

void FOSSEE_Screening::setupMenuBar()
{
    menu = new QMenuBar;
    QMenu* fileMenu = menu->addMenu(tr("&File"));
    QMenu* editMenu = menu->addMenu(tr("&Edit"));
    QMenu* viewMenu = menu->addMenu(tr("&View"));

    QAction* newAction = new QAction(tr("&New Tab"), this);
    fileMenu->addAction(newAction);

    QAction* openAction = new QAction(tr("&Open"), this);
    fileMenu->addAction(openAction);

    QAction* saveAction = new QAction(tr("&Save"), this);
    fileMenu->addAction(saveAction);

    QAction* closeAction = new QAction(tr("&Close"), this);
    fileMenu->addAction(closeAction);

    QAction* addAction = new QAction(tr("&Add Node"), this);
    editMenu->addAction(addAction);

    QAction* removeAction = new QAction(tr("&Remove Node"), this);
    editMenu->addAction(removeAction);

    QAction* renameAction = new QAction(tr("Rena&me Node"), this);
    editMenu->addAction(renameAction);

    QAction* changeTheme = new QAction(tr("&Change theme"), this);
    viewMenu->addAction(changeTheme);

    setMenuBar(menu);
}

void FOSSEE_Screening::setupCentralWidget()
{
    centre = new QWidget();

    QVBoxLayout* centralLayout = new QVBoxLayout();

    tabBar = new QTabBar();
    renderer = new Renderer(centre);

    centralLayout->addWidget(tabBar);
    centralLayout->addWidget(renderer);
    

    centre->setLayout(centralLayout);

    setCentralWidget(centre);
}