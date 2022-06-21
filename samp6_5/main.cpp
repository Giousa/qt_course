#include "mainwindow.h"

#include <QApplication>
#include "qdialoglogin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDialogLogin *dialogLogin = new QDialogLogin;

    if(dialogLogin->exec() == QDialog::Accepted){
        MainWindow w;
        w.show();
        return a.exec();
    }else{
        return 0;
    }


}
