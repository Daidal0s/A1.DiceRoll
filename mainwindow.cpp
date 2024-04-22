#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qobjectdefs.h>
#include <qrandom.h>

void MainWindow::rollDaDice() 
{
    _edge1 = QRandomGenerator::global()->bounded(2,32);
    _edge2 = QRandomGenerator::global()->bounded(2,32);
    emit edgeChanged();

    calculateChance();

    _count1 = QRandomGenerator::global()->bounded(1, _edge1);
    _count2 = QRandomGenerator::global()->bounded(1, _edge2);
    _summary = _count1 + _count2;
    emit countChanged();
}

void MainWindow::calculateChance() 
{
    _chance = (1.0 / _edge1) * (1.0 / _edge2);
    emit chanceChanged();
}

void MainWindow::compareResults() 
{
    if (_summary == ui->sb_guess->value())
        emit compareState(true);
    else
        emit compareState(false);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this,
        SIGNAL(edgeChanged()),
        this,
        SLOT(on_edgeChanged()));
    connect(this, 
        SIGNAL(countChanged()), 
        this, 
        SLOT(on_countChanged()));
    connect(this,
        SIGNAL(chanceChanged()),
        this,
        SLOT(on_chanceChanged()));
    connect(this,
        SIGNAL(compareState(bool)),
        this,
        SLOT(on_compare(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_guess_clicked()
{
    rollDaDice();
    compareResults();
}


void MainWindow::on_sb_dice1_valueChanged(int arg1)
{

}


void MainWindow::on_sb_dice2_valueChanged(int arg1)
{

}

void MainWindow::on_edgeChanged() 
{
    ui->sb_dice1->setValue(_edge1);
    ui->sb_dice2->setValue(_edge2);
}

void MainWindow::on_countChanged() 
{
    ui->lb_count1->setText(QString::number(_count1));
    ui->lb_count2->setText(QString::number(_count2));
    ui->lb_summary->setText(QString::number(_summary));
}

void MainWindow::on_chanceChanged() 
{
    QString chance = QString::number(_chance) + QString("%");
    ui->lb_chance->setText(chance);
}

void MainWindow::on_compare(bool compare) 
{
    if (compare)
        ui->lb_result->setText("You win!");
    else
        ui->lb_result->setText("You lost!");
}