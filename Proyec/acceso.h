#ifndef ACCESO_H
#define ACCESO_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class acceso;
}

class acceso : public QMainWindow
{
    Q_OBJECT

public:
    explicit acceso(QWidget *parent = 0);
    ~acceso();

private slots:
    void on_pushButton_clicked();
    void empezar();

private:
    Ui::acceso *ui;
    QGraphicsScene* scene;
};

#endif // ACCESO_H
