#include "dialog.h"
#include "ui_dialog.h"
#include <QJSEngine>
#include <QDebug>

#include <vector>

CalcDialog::CalcDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

//    std::vector< QPushButton* > buttons = {
//        ui->btn0, ui->btn1, ui->btn2, ui->btn3, ui->btn4, ui->btn5, ui->btn6, ui->btn7, ui->btn8, ui->btn8
//    };
//
//    for( QPushButton* btn : buttons )
//        QObject::connect( btn, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );

    QObject::connect( ui->btn0, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btn1, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btn2, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btn3, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btn4, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btn5, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btn6, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btn7, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btn8, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btn9, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btnAdd, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );
    QObject::connect( ui->btnSub, &QPushButton::clicked, this, &CalcDialog::onAnyBtnClicked );

    QObject::connect( ui->btnCalc, &QPushButton::clicked, this, &CalcDialog::onBtnCalcClicked );

//    QObject::connect( this, &CalcDialog::calculatedNewResult, this, &CalcDialog::showMsgBoxWithResult );
}

void CalcDialog::addTextToInput( const QString& addText )
{
    QString text = ui->leInput->text();
    text += addText;
    ui->leInput->setText( text );
}

void CalcDialog::onAnyBtnClicked()
{
    QObject* senderObj = sender();
    QPushButton* senderBtn = dynamic_cast< QPushButton* >( senderObj );
    if( !senderBtn )
        return;

    addTextToInput( " " + senderBtn->text() + " " );
}

void CalcDialog::onBtnCalcClicked()
{
    QString strFormula = ui->leInput->text();

    QJSEngine myEngine;
    QJSValue result = myEngine.evaluate( strFormula );

    QString resultStr = result.toString();

    ui->leInput->setText( "" );

    emit calculatedNewResult( resultStr );
}

CalcDialog::~CalcDialog()
{
    delete ui;
}
