#pragma once

#include <QtWidgets/QMainWindow>
#include "stdafx.h"
#include "Renderer.h"

class Nodes : public QMainWindow
{
    Q_OBJECT

public:
    Nodes(QWidget* parent = nullptr);
    ~Nodes();

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
