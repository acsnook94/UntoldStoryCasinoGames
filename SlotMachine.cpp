#include "SlotMachine.h"
#include "ui_SlotMachine.h"
#include <QDebug>

SlotMachine::SlotMachine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SlotMachine)
{
    ui->setupUi(this);

    connect(&m_updateTimer, &QTimer::timeout,
            this, &SlotMachine::updateSpin);
    connect(&m_runTimer, &QTimer::timeout,
            this, &SlotMachine::stopSpin);

    m_updateTimer.setInterval(100);
    m_runTimer.setInterval(5000);
    m_runTimer.setSingleShot(true);


    m_imagePaths.push_back(":/diamond.jpg");
    m_imagePaths.push_back(":/cherries.webp");
    m_imagePaths.push_back(":/hearts.webp");
}

SlotMachine::~SlotMachine()
{
    delete ui;
}

void SlotMachine::on_pushButton_clicked()
{
    qDebug() << "I've been clicked";
    startSpin();
}

void SlotMachine::updateSpin()
{
    m_spinLeftNumber = rand() % (int)m_imagePaths.size();
    ui->SpinLeft->setPixmap(QPixmap(m_imagePaths[m_spinLeftNumber]));

    m_spinMiddleNumber = rand() % (int)m_imagePaths.size();
    ui->SpinMiddle->setPixmap(QPixmap(m_imagePaths[m_spinMiddleNumber]));

    m_spinRightNumber = rand() % (int)m_imagePaths.size();
    ui->SpinRight->setPixmap(QPixmap(m_imagePaths[m_spinRightNumber]));
}

void SlotMachine::startSpin()
{
    m_updateTimer.start();
    m_runTimer.start();
}

void SlotMachine::stopSpin()
{
    m_updateTimer.stop();
    qDebug() << "Spin Numbers" << m_spinLeftNumber << m_spinMiddleNumber << m_spinRightNumber;
}
