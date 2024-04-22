#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    int _count1 = 1;
    int _count2 = 1;
    int _summary = 0;

    int _edge1 = 2;
    int _edge2 = 2;

    float _chance = 0;

private:
    void rollDaDice();
    void calculateChance();
    void compareResults();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void edgeChanged();
    void countChanged();
    void chanceChanged();
    void compareState(bool compare);

private slots:
    void on_edgeChanged();
    void on_countChanged();
    void on_chanceChanged();
    void on_compare(bool compare);
    void on_pb_guess_clicked();
    void on_sb_dice1_valueChanged(int arg1);
    void on_sb_dice2_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
