#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class CalcDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalcDialog(QWidget *parent = nullptr);
    ~CalcDialog();

    void addTextToInput( const QString& addText );


private Q_SLOTS:
    void onAnyBtnClicked();
    void onBtnCalcClicked();

Q_SIGNALS:
    void calculatedNewResult( QString result );

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
