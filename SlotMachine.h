#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class SlotMachine; }
QT_END_NAMESPACE

class SlotMachine : public QMainWindow
{
    Q_OBJECT

public:
    SlotMachine(QWidget *parent = nullptr);
    ~SlotMachine();

private slots:
    void on_pushButton_clicked();
    void updateSpin();
    void startSpin();
    void stopSpin();

private:
	Ui::SlotMachine *ui;
    QTimer m_updateTimer;
    QTimer m_runTimer;

    int m_spinLeftNumber;
    int m_spinMiddleNumber;
    int m_spinRightNumber;
    std::vector<QString> m_imagePaths;
};
#endif // SLOTMACHINE_H
