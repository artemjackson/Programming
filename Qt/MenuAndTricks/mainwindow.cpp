#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      lineEdit(new QLineEdit)
{
    QWidget *widget = new QWidget();        /* TO DO */
                                            /* Add layouts, buttuns, etc to widget */
    setCentralWidget(widget);

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *openAct = new QAction(tr("&Open"), this);

    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open File"));

    fileMenu->addAction(openAct);
    fileMenu->setStatusTip(tr("File"));        /* it doesn'twork :( */

    connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));

    lineEdit->setReadOnly(true);
    statusBar()->addWidget(lineEdit);
    statusBar()->setToolTip("");
}

MainWindow::~MainWindow()
{

}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", tr("File(*.cpp)") );
    lineEdit->setText(fileName);
}
