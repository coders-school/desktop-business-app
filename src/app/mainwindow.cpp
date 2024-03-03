#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(std::make_unique<Ui::MainWindow>()) // Use std::make_unique for
                                             // initialization
{
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  // No need to delete ui, it will be automatically deleted.
}
