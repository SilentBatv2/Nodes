#pragma once

#include <QtWidgets/QMainWindow>
#include "Renderer.h"

class FOSSEE_Screening : public QMainWindow
{
    Q_OBJECT

public:
    FOSSEE_Screening(QWidget *parent = nullptr);
    ~FOSSEE_Screening();

private:
    void setupStatusBar();
    void setupMenuBar();
    void setupCentralWidget();

    QStatusBar* statusbar;
    QMenuBar* menu;

    QWidget* centre;
    QTabBar* tabBar;
    Renderer* renderer;
};
