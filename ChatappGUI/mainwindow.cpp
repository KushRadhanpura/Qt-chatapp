#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "networkmanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::on_sendButton_clicked);

    // Create an object of your NetworkManager class
    NetworkManager *networkManager = new NetworkManager(this);

    // Call the network function to connect to the server
    networkManager->connectToServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendButton_clicked()
{
    // For now, this is just a placeholder to test the button
    std::cout << "Button was clicked!" << std::endl;
}
