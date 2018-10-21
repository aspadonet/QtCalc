#include "dialog.h"
#include <QApplication>
#include <QMessageBox>
#include <QListWidget>


void showMsgRes( QString res )
{
    QMessageBox::information( nullptr, "Ркзультат", res  );
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalcDialog w;
    w.show();

    QListWidget lw;
    lw.show();

    QObject::connect( &w, &CalcDialog::calculatedNewResult, &showMsgRes );

    auto addNewResInListWidget = [ &lw ]( QString res ){
      lw.addItem( res );
    };

    QObject::connect( &w, &CalcDialog::calculatedNewResult, addNewResInListWidget );

    return a.exec();
}
