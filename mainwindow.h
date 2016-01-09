#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bt_browse_clicked();

    void on_bt_apply_clicked();

    void on_bt_Apply1_clicked();

    void on_bt_apply_tp_clicked();

    void on_bt_apply_tp1_clicked();

    void on_bt_xuly_pn_clicked();

    void on_bt_browse1_clicked();

    void on_bt_Add_clicked();

    void on_bt_Sub_clicked();

    void on_bt_showH_clicked();

    void Histogram(const QImage &img, const int &his_height);
    void on_bt_showH1_clicked();

    void on_bt_showH3_clicked();

    void on_bt_p2n_clicked();

    void draw_Histogram(const QImage &img, const int &height, const QString &str);


    void on_bt_applyTCD_clicked();

    void on_bt_ApplyCBTCD_clicked();

    void on_bt_LocAnhTB_Color_clicked();

    void on_bt_LocAnhTB_Gray_clicked();

    void on_bt_LocAnhMedian_Gray_clicked();

    void on_bt_LocAnhMedian_Color_clicked();

    void on_btn_Gradient_clicked();

    void on_btn_GradientY_clicked();

    void on_btn_Roberts_X_clicked();

    void on_btn_Roberts_Y_clicked();

    void on_btn_Sobel_X_clicked();

    void on_btn_Sobel_Y_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
